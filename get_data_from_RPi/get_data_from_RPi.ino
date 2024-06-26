#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void change_couleur(int r, int v, int b) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(r,v,b));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
  
}

void en_noir()  { change_couleur(0,0,0); }
void en_rouge() { change_couleur(64,0,0); }
void en_vert()  { change_couleur(0,64,0); }
void en_bleu()  { change_couleur(0,0,64); }
void en_blanc() { change_couleur(64,64,64); }

void setup() {
  int color_init=64;
  // put your setup code here, to run once:
  Serial.begin(9600); 

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  change_couleur(color_init,color_init,color_init);
  for(int i=color_init; i>18; i=i-(i>>2)) {
    change_couleur(i,i,i);
  }
  en_noir();
  // delay(1000); /* wait for 1s */
}

char etat_porte = '1';
void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    etat_porte = (char) Serial.read();
    Serial.print((char)etat_porte);
  }

  switch(etat_porte) {
    case '0': /* door is opened */
      en_vert();
      break;
    case '1': /* door is closed */
      en_rouge();
      break;
    default:
      en_bleu();
  }

  
}
