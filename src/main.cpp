#include <Arduino.h>
byte digits[16] = {0x3f, 0x06, 0x5b, 0x4f, 
                    0x66, 0x6d, 0x7d, 0x07, 
                    0x7f, 0x6f, 0x77, 0x7c,
                    0x39, 0x5e, 0x79, 0x71};
byte pins[7] = {4,5,6,7,8,9,10};
byte in_pins[4] = {3,2,1,0};

void setup() {
  for(int i=0; i<7; i++){
    pinMode(pins[i], OUTPUT);
  }
  for(int i=0; i<4; i++){
    pinMode(in_pins[i], INPUT_PULLUP);
  }

}

void display_digit(int d){
  //iterate through the pins and set them to each bit value
  for(int i=0; i<7; i++){
    byte pin_to_set = pins[i];
    byte value_to_set = bitRead(digits[d], i);
    digitalWrite(pin_to_set, value_to_set);
    delay(1);
    digitalWrite(pin_to_set, LOW);
  }
}
long time_of_last_change = 0;

void loop() {
  //read the binary values from the 4 input pins
  byte digit = 0;
  for(int i=0; i<4; i++){
    bool bitvalue = digitalRead(in_pins[i]);
    digit |= bitvalue << i;
  } 
  display_digit(digit);
}