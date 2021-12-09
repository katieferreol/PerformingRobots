const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN

const byte address[6] = "00001";

const int rightDirPin = 4;
const int rightPWMPin = 5;
const int leftDirPin = 7;
const int leftPWMPin = 6;

int buttons;
int potentiometer;
bool newData = false;

void setup() {

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
  servoMotor();
  //dcMotor();
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
      case 1:
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
      case 4:
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
  
}

void stop() {
  digitalWrite(rightDirPin, LOW);
  analogWrite(rightPWMPin, 0);
  digitalWrite(leftDirPin, LOW);
  analogWrite(leftPWMPin, 0);
}
