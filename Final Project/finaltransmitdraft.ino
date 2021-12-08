const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);                

const byte address[6] = "00001";

// Pins for the directional buttons
const int LEFT_BUTTON = 4;
const int RIGHT_BUTTON = 7;
const int UP_BUTTON = 8;
const int DOWN_BUTTON = 2;
const int POT1PIN = A1;
const int POT2PIN = A0;

int value;

void setup() {
  Serial.begin(9600);

  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);

  boolean retval = radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); 
}

void loop() {

  static unsigned long timer = 0;
   unsigned long interval = 1000;
   if (millis() - timer >= interval)
   {
      timer = millis();
      value = analogRead(POT2PIN);
      value =  map(analogRead(A0), 0, 1023, 5, 175);
      Serial.println(value);
   }

  int left = !digitalRead(LEFT_BUTTON);
  int right = !digitalRead(RIGHT_BUTTON);
  int down = !digitalRead(DOWN_BUTTON);
  int up = !digitalRead(UP_BUTTON);

  int data =  
    (left << 4) |
    (up << 3) |
    (right << 2) |
    (down << 1) ;

  if (data) {
    Serial.println(data, BIN);
    radio.write(&data, sizeof(data)) ;
  }
   if (value) {
    Serial.println(value, BIN);
    radio.write(&value, sizeof(value)) ;
  }
}
