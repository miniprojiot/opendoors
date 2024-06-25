/*
  Recuperation etat du Capteur
  __ET__
  Envoi de donnees vers RPi (via comm serie)
 */

const int CAPTOR_PIN  = A0;
const int interval  = 500;  /* ms */

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(CAPTOR_PIN, INPUT); 

  Serial.begin(9600); 
}

unsigned int lastCaptorStatus = 0; //init: assuming the door is closed (captorStatus=1 otherwise (ie the door is opened))  

// the loop function runs over and over again forever
void loop() {
  unsigned int captorStatus;  
  
  captorStatus     = digitalRead(CAPTOR_PIN);

  /*Serial.print("last=");
  Serial.println(lastCaptorStatus);
  Serial.print("current=");
  Serial.println(captorStatus);*/
  
  if ( captorStatus != lastCaptorStatus ) {
    Serial.println(captorStatus);
    lastCaptorStatus = captorStatus;
  }
  
  delay(interval);              // wait for while (in millisecond)
}
