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

#define LED_PIN    6

#define LED_COUNT 64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
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
    radio.read(&data, sizeof(data));  //Reading the data
    //Serial.print("data = ");
    //Serial.println(data);
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
        stoic(strip.Color(255, 255, 255), 1000);
        break;
      case 6:
        Serial.println("happy");
        happy(strip.Color(255, 255, 0), 1000);
        break;
      case 10:
        Serial.println("sad");
        sad(strip.Color(0, 0, 255), 1000);
        break;
      case 18:
        Serial.println("angry");
        angry(strip.Color(255, 0, 0), 1000);
        break;
    }
  }

void happy(uint32_t color, int wait) {
  strip.setPixelColor(10, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(17, color);
  strip.setPixelColor(19, color);
  strip.setPixelColor(21, color);
  strip.setPixelColor(23, color);

  strip.setPixelColor(33, color);
  strip.setPixelColor(39, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(51, color);
  strip.setPixelColor(52, color);
  strip.setPixelColor(53, color);
  strip.show();
  delay(wait);
  strip.clear();

  strip.setPixelColor(10, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(17, color);
  strip.setPixelColor(19, color);
  strip.setPixelColor(21, color);
  strip.setPixelColor(23, color);

  strip.setPixelColor(33, color);
  strip.setPixelColor(34, color);
  strip.setPixelColor(35, color);
  strip.setPixelColor(36, color);
  strip.setPixelColor(37, color);
  strip.setPixelColor(38, color);
  strip.setPixelColor(39, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(51, color);
  strip.setPixelColor(52, color);
  strip.setPixelColor(53, color);
  strip.show();
  delay(wait);
  strip.clear();
}

void stoic(uint32_t color, int wait) {
  strip.setPixelColor(9, color);
  strip.setPixelColor(10, color);
  strip.setPixelColor(11, color);
  strip.setPixelColor(13, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(15, color);
  strip.setPixelColor(18, color);
  strip.setPixelColor(22, color);

  strip.setPixelColor(41, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(43, color);
  strip.setPixelColor(44, color);
  strip.setPixelColor(45, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(47, color);
  strip.show();
  delay(wait);
  strip.clear();

  strip.setPixelColor(9, color);
  strip.setPixelColor(10, color);
  strip.setPixelColor(11, color);
  strip.setPixelColor(13, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(15, color);
  strip.setPixelColor(19, color);
  strip.setPixelColor(23, color);

  strip.setPixelColor(41, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(43, color);
  strip.setPixelColor(44, color);
  strip.setPixelColor(45, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(47, color);
  strip.show();
  delay(wait);
  strip.clear();
}

void sad(uint32_t color, int wait) {
  strip.setPixelColor(9, color);
  strip.setPixelColor(11, color);
  strip.setPixelColor(13, color);
  strip.setPixelColor(15, color);
  strip.setPixelColor(18, color);
  strip.setPixelColor(22, color);

  strip.setPixelColor(35, color);
  strip.setPixelColor(36, color);
  strip.setPixelColor(37, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(49, color);
  strip.setPixelColor(55, color);
  strip.show();
  delay(wait);
  strip.clear();

  strip.setPixelColor(9, color);
  strip.setPixelColor(11, color);
  strip.setPixelColor(13, color);
  strip.setPixelColor(15, color);
  strip.setPixelColor(18, color);
  strip.setPixelColor(22, color);

  strip.setPixelColor(35, color);
  strip.setPixelColor(36, color);
  strip.setPixelColor(37, color);
  strip.setPixelColor(43, color);
  strip.setPixelColor(45, color);
  strip.setPixelColor(51, color);
  strip.setPixelColor(52, color);
  strip.setPixelColor(53, color);
  strip.show();
  delay(wait);
  strip.clear();
}


void angry(uint32_t color, int wait) {
  strip.setPixelColor(1, color);
  strip.setPixelColor(7, color);
  strip.setPixelColor(10, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(19, color);
  strip.setPixelColor(21, color);

  strip.setPixelColor(35, color);
  strip.setPixelColor(36, color);
  strip.setPixelColor(37, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(49, color);
  strip.setPixelColor(55, color);
  strip.show();
  delay(wait);
  strip.clear();

  strip.setPixelColor(1, color);
  strip.setPixelColor(7, color);
  strip.setPixelColor(10, color);
  strip.setPixelColor(14, color);
  strip.setPixelColor(19, color);
  strip.setPixelColor(21, color);

  strip.setPixelColor(35, color);
  strip.setPixelColor(36, color);
  strip.setPixelColor(37, color);
  strip.setPixelColor(42, color);
  strip.setPixelColor(46, color);
  strip.setPixelColor(49, color);
  strip.setPixelColor(50, color);
  strip.setPixelColor(51, color);
  strip.setPixelColor(52, color);
  strip.setPixelColor(53, color);
  strip.setPixelColor(54, color);
  strip.setPixelColor(55, color);
  strip.show();
  delay(wait);
  strip.clear();
}

void stop() {
  strip.clear();
}
