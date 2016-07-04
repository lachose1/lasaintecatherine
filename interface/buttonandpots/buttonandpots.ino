#include <string.h>

int btnPins[1] = {2};
int btns[1];
int potsPins[3] = {A0, A1, A2};
int pots[3];
int stations = 0;

void setup() {
  stations = sizeof(btnPins) - 1; //Detect how many stations are plugged
  for(byte i = 0; i < stations; i++) // declare pushbuttons as inputs
    pinMode(btnPins[i], INPUT);

  Serial.begin(9600);
}

void loop(){
  String json = "{";
  for(byte i = 0; i < stations * 3; i++)
    pots[i] = analogRead(potsPins[i]); // Read pots
  pots[1], pots[2] = 0;
  
  for(byte i = 0; i < stations; i++)
    btns[i] = digitalRead(btnPins[i]);  // Read input value
    
  for(byte i = 0; i < stations; i++) {
     json += "\"station";
     json += i;
     json += "\": {\"btn\": ";
     json += !btns[0];
     json += ", ";
     for(byte j = 0; j < 3; j++) {
          json += "\"pot";
          json += j;
          json += "\": ";
          json += pots[j];
          if(j < 2)
            json += ", ";
     }
     json += "}";
  }
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
