void ledblink(int blinkcount)
{
  for(int i=0; i<blinkcount+1; i++)
  {
  digitalWrite(LeftLed, LOW);
  digitalWrite(RightLed, LOW);
  delay(100);
  digitalWrite(LeftLed, HIGH);
  digitalWrite(RightLed, HIGH);
  delay(100);
  }
}