const int pushButton = 2;
const int in1Pin = 7;
const int in2Pin = 6;
const int in3Pin = 5;
const int in4Pin = 4;


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(1);

  if (buttonState == HIGH) {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, LOW);
  }
}
