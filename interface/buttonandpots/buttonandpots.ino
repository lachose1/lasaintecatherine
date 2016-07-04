/* Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int ledPin = 13; // choose the pin for the LED
int btnPins[1] = {2};
int btns[1];     // variable for reading the pin status
int pot = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(btnPins[0], INPUT);    // declare pushbutton as input
  Serial.begin(9600);
}

void loop(){
  btns[0] = digitalRead(btnPins[0]);  // read input value
  pot = analogRead(A0);
  
  Serial.println(pot);
  if (btns[0] == HIGH) {         // check if the input is HIGH (button released)
    Serial.println("0");
  } else {
    Serial.println("1");
  }
  delay(50); //Delay to avoid flicker
}
