#!/usr/bin/env python3
import serial
import requests
import time

BASE_URL="https://api.thingspeak.com/"
TS_CHANNEL_ID= "2582290"
WRITE_TS_KEY = "J19KONCHRJWLCNJ8"
READ_TS_KEY  = "70URRTIX01JMOQJ9"
QUIET_PERIOD = 10

def read_ch_feed(n_last_ids) :
	api_url  = BASE_URL+"channels/"+TS_CHANNEL_ID+"/feeds.json?api_key="+READ_TS_KEY+"&results="+str(n_last_ids)
	response = requests.get(api_url)
	print(response.json()) 
#end read_ch_feed

def upd_ch_feed(value) :
	api_url  = BASE_URL+"update?api_key="+WRITE_TS_KEY+"&field1="+str(value)
	response = requests.get(api_url)
	#print(type(response.json()))
	print(response.json())
	while int(response.json()) == 0: 
		print("too soon! should wait for "+str(QUIET_PERIOD)+"sec (patience is mother of safety!)")
		time.sleep(QUIET_PERIOD)
		response = requests.get(api_url)
		print(response.json())
		
	print("upd_ch_feed("+str(value)+") : OK")
#end upd_ch_feed


if __name__ == '__main__':
	ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
	ser.reset_input_buffer()

	while True:
		if ser.in_waiting > 0:
			read_ch_feed(2)
			line = ser.readline().decode('utf-8').rstrip()
			print(line)
			upd_ch_feed(int(line))


#end of file
