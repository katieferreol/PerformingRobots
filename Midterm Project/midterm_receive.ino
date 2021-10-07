const int CEPIN = 9;
const int CSNPIN = 10;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);

const byte address[6] = "00001";

const int motor1pin1 = 4;
const int motor1pin2 = 5;
const int motor2pin1 = 6;
const int motor2pin2 = 7;

float startTime;
boolean isActive = false;
int currentFrame = 0;

#define LED_PIN    3

#define LED_COUNT 64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show();
  strip.setBrightness(50);


  Serial.begin(115200);
  if (!radio.begin()) {
    Serial.println("radio  initialization failed");
    while (1)
      ;
  } else {
    Serial.println("radio successfully initialized");
  }
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  uint8_t pipeNum;
  if (radio.available(&pipeNum))
  {
    int data;
    radio.read(&data, sizeof(data));
    startShow(data);
  } else {
    stop();
  }
}


void startShow(int i) {
  switch (i) {
      break;
    case 2:
      Serial.println("stoic");
      if (isActive == false) {
        startTime = millis();
        isActive = true;
        currentFrame = 0;
      }
      if (millis() > startTime + 1000) {
        currentFrame = 1 - currentFrame;
        startTime = millis();
      }
      if (currentFrame == 0) {
        strip.setPixelColor(9, 255, 255, 255);
        strip.setPixelColor(10, 255, 255, 255);
        strip.setPixelColor(11, 255, 255, 255);
        strip.setPixelColor(13, 255, 255, 255);
        strip.setPixelColor(14, 255, 255, 255);
        strip.setPixelColor(15, 255, 255, 255);
        strip.setPixelColor(18, 255, 255, 255);
        strip.setPixelColor(22, 255, 255, 255);

        strip.setPixelColor(41, 255, 255, 255);
        strip.setPixelColor(42, 255, 255, 255);
        strip.setPixelColor(43, 255, 255, 255);
        strip.setPixelColor(44, 255, 255, 255);
        strip.setPixelColor(45, 255, 255, 255);
        strip.setPixelColor(46, 255, 255, 255);
        strip.setPixelColor(47, 255, 255, 255);
        strip.show();
        strip.clear();
      } else {
        strip.setPixelColor(9, 255, 255, 255);
        strip.setPixelColor(10, 255, 255, 255);
        strip.setPixelColor(11, 255, 255, 255);
        strip.setPixelColor(13, 255, 255, 255);
        strip.setPixelColor(14, 255, 255, 255);
        strip.setPixelColor(15, 255, 255, 255);
        strip.setPixelColor(19, 255, 255, 255);
        strip.setPixelColor(23, 255, 255, 255);

        strip.setPixelColor(41, 255, 255, 255);
        strip.setPixelColor(42, 255, 255, 255);
        strip.setPixelColor(43, 255, 255, 255);
        strip.setPixelColor(44, 255, 255, 255);
        strip.setPixelColor(45, 255, 255, 255);
        strip.setPixelColor(46, 255, 255, 255);
        strip.setPixelColor(47, 255, 255, 255);
        strip.show();
        strip.clear();
      }
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      break;
    case 4:
      Serial.println("happy");
      if (isActive == false) {
        startTime = millis();
        isActive = true;
        currentFrame = 0;
      }
      if (millis() > startTime + 1000) {
        currentFrame = 1 - currentFrame;
        startTime = millis();
      }
      if (currentFrame == 0) {
        strip.setPixelColor(10, 255, 255, 0);
        strip.setPixelColor(14, 255, 255, 0);
        strip.setPixelColor(17, 255, 255, 0);
        strip.setPixelColor(19, 255, 255, 0);
        strip.setPixelColor(21, 255, 255, 0);
        strip.setPixelColor(23, 255, 255, 0);

        strip.setPixelColor(33, 255, 255, 0);
        strip.setPixelColor(39, 255, 255, 0);
        strip.setPixelColor(42, 255, 255, 0);
        strip.setPixelColor(46, 255, 255, 0);
        strip.setPixelColor(51, 255, 255, 0);
        strip.setPixelColor(52, 255, 255, 0);
        strip.setPixelColor(53, 255, 255, 0);
        strip.show();
        strip.clear();
      } else {
        strip.setPixelColor(10, 255, 255, 0);
        strip.setPixelColor(14, 255, 255, 0);
        strip.setPixelColor(17, 255, 255, 0);
        strip.setPixelColor(19, 255, 255, 0);
        strip.setPixelColor(21, 255, 255, 0);
        strip.setPixelColor(23, 255, 255, 0);

        strip.setPixelColor(33, 255, 255, 0);
        strip.setPixelColor(34, 255, 255, 0);
        strip.setPixelColor(35, 255, 255, 0);
        strip.setPixelColor(36, 255, 255, 0);
        strip.setPixelColor(37, 255, 255, 0);
        strip.setPixelColor(38, 255, 255, 0);
        strip.setPixelColor(39, 255, 255, 0);
        strip.setPixelColor(42, 255, 255, 0);
        strip.setPixelColor(46, 255, 255, 0);
        strip.setPixelColor(51, 255, 255, 0);
        strip.setPixelColor(52, 255, 255, 0);
        strip.setPixelColor(53, 255, 255, 0);
        strip.show();
        strip.clear();
      }
      analogWrite(motor1pin1, 100);
      digitalWrite(motor1pin2, LOW);
      analogWrite(motor2pin1, 100);
      digitalWrite(motor2pin2, LOW);
      break;
    case 8:
      Serial.println("sad");
      if (isActive == false) {
        startTime = millis();
        isActive = true;
        currentFrame = 0;
      }
      if (millis() > startTime + 1000) {
        currentFrame = 1 - currentFrame;
        startTime = millis();
      }
      if (currentFrame == 0) {
        strip.setPixelColor(9, 0, 0, 255);
        strip.setPixelColor(11, 0, 0, 255);
        strip.setPixelColor(13, 0, 0, 255);
        strip.setPixelColor(15, 0, 0, 255);
        strip.setPixelColor(18, 0, 0, 255);
        strip.setPixelColor(22, 0, 0, 255);

        strip.setPixelColor(35, 0, 0, 255);
        strip.setPixelColor(36, 0, 0, 255);
        strip.setPixelColor(37, 0, 0, 255);
        strip.setPixelColor(42, 0, 0, 255);
        strip.setPixelColor(46, 0, 0, 255);
        strip.setPixelColor(49, 0, 0, 255);
        strip.setPixelColor(55, 0, 0, 255);
        strip.show();
        strip.clear();
      } else {
        strip.setPixelColor(9, 0, 0, 255);
        strip.setPixelColor(11, 0, 0, 255);
        strip.setPixelColor(13, 0, 0, 255);
        strip.setPixelColor(15, 0, 0, 255);
        strip.setPixelColor(18, 0, 0, 255);
        strip.setPixelColor(22, 0, 0, 255);

        strip.setPixelColor(35, 0, 0, 255);
        strip.setPixelColor(36, 0, 0, 255);
        strip.setPixelColor(37, 0, 0, 255);
        strip.setPixelColor(43, 0, 0, 255);
        strip.setPixelColor(45, 0, 0, 255);
        strip.setPixelColor(51, 0, 0, 255);
        strip.setPixelColor(52, 0, 0, 255);
        strip.setPixelColor(53, 0, 0, 255);
        strip.show();
        strip.clear();
      }
      analogWrite(motor1pin1, 50);
      digitalWrite(motor1pin2, LOW);
      analogWrite(motor2pin1, 50);
      digitalWrite(motor2pin2, LOW);
      break;
    case 16:
      Serial.println("angry");
      if (isActive == false) {
        startTime = millis();
        isActive = true;
        currentFrame = 0;
      }
      if (millis() > startTime + 1000) {
        currentFrame = 1 - currentFrame;
        startTime = millis();
      }
      if (currentFrame == 0) {
        strip.setPixelColor(1, 255, 0, 0);
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(14, 255, 0, 0);
        strip.setPixelColor(19, 255, 0, 0);
        strip.setPixelColor(21, 255, 0, 0);

        strip.setPixelColor(35, 255, 0, 0);
        strip.setPixelColor(36, 255, 0, 0);
        strip.setPixelColor(37, 255, 0, 0);
        strip.setPixelColor(42, 255, 0, 0);
        strip.setPixelColor(46, 255, 0, 0);
        strip.setPixelColor(49, 255, 0, 0);
        strip.setPixelColor(55, 255, 0, 0);
        strip.show();
        strip.clear();
      } else {
        strip.setPixelColor(1, 255, 0, 0);
        strip.setPixelColor(7, 255, 0, 0);
        strip.setPixelColor(10, 255, 0, 0);
        strip.setPixelColor(14, 255, 0, 0);
        strip.setPixelColor(19, 255, 0, 0);
        strip.setPixelColor(21, 255, 0, 0);

        strip.setPixelColor(35, 255, 0, 0);
        strip.setPixelColor(36, 255, 0, 0);
        strip.setPixelColor(37, 255, 0, 0);
        strip.setPixelColor(42, 255, 0, 0);
        strip.setPixelColor(46, 255, 0, 0);
        strip.setPixelColor(49, 255, 0, 0);
        strip.setPixelColor(50, 255, 0, 0);
        strip.setPixelColor(51, 255, 0, 0);
        strip.setPixelColor(52, 255, 0, 0);
        strip.setPixelColor(53, 255, 0, 0);
        strip.setPixelColor(54, 255, 0, 0);
        strip.setPixelColor(55, 255, 0, 0);
        strip.show();
        strip.clear();
      }
      //motor1 forward, fast
      analogWrite(motor1pin1, 200);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, 200);
      digitalWrite(motor2pin2, LOW);
      break;
  }
}

void stop() {
  strip.clear();
}
