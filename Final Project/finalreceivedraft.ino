const int CEPIN = 9;
const int CSNPIN = 10;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN

#include <Servo.h>
Servo myServo; 

const byte address[6] = "00001";

const int rightDirPin = 4;
const int rightPWMPin = 5;
const int leftDirPin = 7;
const int leftPWMPin = 6;

#define LED_PIN    3
#define LED_COUNT 64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

float startTime;
boolean isActive = false;
int currentFrame = 0;

int buttons;
int potentiometer;
bool newData = false;

long elapsed_time = 0;
long previousMillis = 0;
long previousMillis2 = 0;
long servointerval = 15;
long interval = 1000;
int pos = 0;

void setup() {
  myServo.attach(8);

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  strip.begin();
  strip.show();
  strip.setBrightness(50);

  // Motor controller pins
  pinMode(rightDirPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  pinMode(rightPWMPin, OUTPUT);
  pinMode(leftPWMPin, OUTPUT);
  
  Serial.begin(9600);

  // RF24 setup
  if (!radio.begin()) {
    Serial.println("radio  initialization failed");
    while (1)
      ;
  } else {
    Serial.println("radio successfully initialized");
  }
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // sets  module as receiver
}
void loop() {
  getData();
  showData();
  dcMotor();
  servoMotor();
  neoPixel();
}

void getData(){
  if (radio.available()){
    int data[2];
    radio.read(&data, sizeof(data));
    buttons = data[0];
    potentiometer = data[1];
    newData = true;
}
}

void showData(){
  if (newData == true) { 
    Serial.print(buttons);
    Serial.print("\t");
    Serial.println(potentiometer);
    newData = false;
  }
}

void servoMotor() {
  switch (buttons) {
      case 4:
        Serial.println("turning right");
        digitalWrite(rightDirPin, LOW);
        analogWrite(rightPWMPin, 200);
        break;
      case 2:
        Serial.println("forward");
        digitalWrite(rightPWMPin, HIGH);
        analogWrite(rightDirPin, 0);
        digitalWrite(leftPWMPin, LOW);
        analogWrite(leftDirPin, 255);
        break;
      case 1:
        Serial.println("backward");
        digitalWrite(rightPWMPin, LOW);
        analogWrite(rightDirPin, 255);
        digitalWrite(leftPWMPin, HIGH);
        analogWrite(leftDirPin, 0);
        break;
      case 8:
        Serial.println("turning left");
        digitalWrite(leftDirPin, HIGH);
        analogWrite(leftPWMPin, 50);
        break;
      default:
        Serial.println("invalid code");
        stop();
        digitalWrite(rightDirPin, LOW);
        digitalWrite(rightPWMPin, LOW);
        break;
    }
}

void dcMotor() {
  myServo.write(potentiometer);
}

void neoPixel() {
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
}

void stop() {
  digitalWrite(rightDirPin, LOW);
  analogWrite(rightPWMPin, 0);
  digitalWrite(leftDirPin, LOW);
  analogWrite(leftPWMPin, 0);
}
