#include <ultra_sense.h>

Trans t; // Object to set the ultrasonic sensor parameters 
void setup()
{
  t.Trig=12; //Set Trig pin as digital pin 12, can be varied
  t.Echo=11; //Set Echo pin as digital pin 11, can be varied
  Serial.begin(9600);
}
void loop()
{
  t.begin();// Start the sensing 
  t.print("centi"); // Replace centi with inch for calculation in inch
  delay(100);
}
