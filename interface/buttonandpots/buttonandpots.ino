#include <string.h>

int btnPins[3] = {2, 3, 4};
int potsPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, A8};
int stations = 3;

void setup() {
//  stations = sizeof(btnPins) - 1; //Detect how many stations are plugged
  for(byte i = 0; i < stations; i++) // declare pushbuttons as inputs
    pinMode(btnPins[i], INPUT);

  Serial.begin(9600);
}

void loop(){
  String json = "{";
  json += "\"pots\": [";
  for(byte i = 0; i < stations * 3; i++) {
    json += analogRead(potsPins[i]); // Read pots
    if(i < stations * 3 - 1)
      json += ", ";
  }
  json += "], \"btns\": [";
  for(byte i = 0; i < stations; i++) {
    json += digitalRead(btnPins[i]);  // Read input value
    if(i < stations - 1)
      json += ", ";
  }
  json += "]";
//  for(byte i = 0; i < stations; i++) {
//     json += "\"station";
//     json += i;
//     json += "\": {\"btn\": ";
//     json += !digitalRead(btnPins[i]);
//     json += ", ";
//     for(byte j = 0; j < 3; j++) {
//          json += "\"pot";
//          json += j;
//          json += "\": ";
//          json += analogRead(potsPins[(i+1)*j]);
//          if(j < 2)
//            json += ", ";
//     }
//     json += "}";
//     if(i < stations - 1)
//          json += ", ";
//  }
  json += "}";
  Serial.println(json);
//  for(byte i = 0; i < stations; i++)
//    json += "'station1' : {'button1': " + "1" + "}";
//  Serial.println(btns[0]);
//  Serial.println(pots[0]);
//  if (btns[0] == HIGH) {         // check if the input is HIGH (button released)
//    Serial.println("0");
//  } else {
//    Serial.println("1");
//  }
  delay(50); //Delay to avoid flicker
}
