const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);                // CE, CSN

// Byte of array representing the address.
// This is the address where we will send the data.
// This should be same on the receiving side.
const byte address[6] = "00001";

// Pins for the pushbuttons
const int LEFT_BUTTON = 4;
const int RIGHT_BUTTON = 7;
const int UP_BUTTON = 8;
const int DOWN_BUTTON = 2;

const int pot = A0;

void setup() {
  Serial.begin(9600);
  boolean retval = radio.begin();   //Starting the Wireless communication
  Serial.println(retval);
  radio.openWritingPipe(address);  //destination addres
  radio.setPALevel(RF24_PA_MIN);   // min or max
  radio.stopListening();           //This sets the module as transmitter

  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);

}

void loop() {

  int up = !digitalRead(UP_BUTTON) << 0;
  int down = !digitalRead(DOWN_BUTTON) << 1;
  int left = !digitalRead(LEFT_BUTTON) << 2;
  int right = !digitalRead(RIGHT_BUTTON) << 3;
  
    int npData = 0;
    npData = analogRead(pot);
    npData = map(analogRead(pot), 0, 1023, 5, 175);
    npData << 8;
//  Serial.println(npData);

  int data[2];
  data[0] = up | down | left | right;
  data[1] = npData;
  if (data) {
    Serial.println(data[0]);
    radio.write(&data, sizeof(data)) ;
  }
}
