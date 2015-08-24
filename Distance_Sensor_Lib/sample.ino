#include <ultra_sense.h>

Trans t;
void setup()
{
  t.Trig=12;
  t.Echo=11;
  Serial.begin(9600);
}
void loop()
{
  t.begin();
  t.print("centi");
  delay(100);
}