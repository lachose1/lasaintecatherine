#include <ArduinoJson.h>

StaticJsonBuffer<200> jsonBuffer;

int btnPins[1] = {2};
int btns[1];
int potsPins[1] = {A0};
int pots[1];
int stations = 0;

void setup() {
  stations = sizeof(btnPins); //Detect how many stations are plugged
  for(byte i = 0; i < stations; i++) // declare pushbuttons as inputs
    pinMode(btnPins[i], INPUT);

  Serial.begin(9600);
}

void loop(){
//  JsonObject& root = jsonBuffer.createObject();
  
  for(byte i = 0; i < stations; i++)
    pots[i] = analogRead(potsPins[i]); // Read pots
  
  for(byte i = 0; i < stations; i++)
    btns[i] = digitalRead(btnPins[i]);  // Read input value
    

  Serial.println(pots[0]);
  if (btns[0] == HIGH) {         // check if the input is HIGH (button released)
    Serial.println("0");
  } else {
    Serial.println("1");
  }
  delay(50); //Delay to avoid flicker
}
