#!/usr/bin/env python3

import serial
import requests
import time
import json

BASE_URL = "https://api.thingspeak.com/"
TS_CHANNEL_ID = "2582296"
WRITE_TS_KEY = "Y2A9Q6LC6A034TD6"
READ_TS_KEY  = "E1AQ8KXAHJ9VXIWB"
QUIET_PERIOD = 10

def read_ch_field1(n_last_ids):
	api_url = BASE_URL+"channels/"+TS_CHANNEL_ID+"/fields/1.json?api_key="+READ_TS_KEY+"&results="+str(n_last_ids)
	response = requests.get(api_url)
	# print(response.json())
	infos = json.loads(response.text)
	ret_val=infos["feeds"][0]["field1"]
	
	print(ret_val)
	
	return ret_val
# end read_ch_feed

if __name__ == '__main__':
	toArduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
	toArduino.reset_output_buffer()

	while True:
		print("out_waiting: "+str(toArduino.out_waiting))
		if int(toArduino.out_waiting) == 0:
			etat_porte=read_ch_field1(1)
			toArduino.write(etat_porte.encode('utf-8'))
			print("waiting for "+str(QUIET_PERIOD)+" s")
			time.sleep(QUIET_PERIOD)


# end main

# end of file
