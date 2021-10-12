const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);                // CE, CSN

const byte address[6] = "00001";

const int stoicPin = 5;
const int happyPin = 2;
const int sadPin = 3;
const int angryPin = 4;

void setup() {
  Serial.begin(115200);
  boolean retval = radio.begin();   //Starting the Wireless communication
  Serial.println(retval);
  radio.openWritingPipe(address);  //destination addres
  radio.setPALevel(RF24_PA_MIN);   // min or max
  radio.stopListening();           //This sets the module as transmitter
}

void loop() {
    int stoic = digitalRead(stoicPin) << 1;
    int happy = digitalRead(happyPin) << 2;
    int sad = digitalRead(sadPin) << 3;
    int angry = digitalRead(angryPin) << 4;
  
  int data = stoic | happy | sad | angry;
  if (data) {
    Serial.print( "sending data = " );
    Serial.println(data);
    radio.write(&data, sizeof(data)) ;
  }
}
