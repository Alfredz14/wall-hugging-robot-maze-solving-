void left() 
{
  Mstop();
  delay(250);
  analogWrite(L_Mpwm, 100);
  analogWrite(R_Mpwm, 100);
  left_pre = digitalRead(left_en);
  right_pre = digitalRead(right_en);
  digitalWrite(L_Mdir, HIGH);
  digitalWrite(R_Mdir, HIGH);
  Lcounter = 0;
  Rcounter = 0;
  while (true)
  {
    val();
    if (Lcounter >= turncount)
    {
      analogWrite(L_Mpwm, 0);
    }
    if (Rcounter >= turncount)
    {
      analogWrite(R_Mpwm, 0);
    }
    if (Lcounter >= turncount && Rcounter >= turncount)
    {
      delay(250);
      break;
    }
  }
}
void right() {
  Mstop();
  delay(250);
  analogWrite(L_Mpwm, 100);
  analogWrite(R_Mpwm, 100);
  left_pre = digitalRead(left_en);
  right_pre = digitalRead(right_en);
  digitalWrite(R_Mdir, LOW);
  digitalWrite(L_Mdir, LOW);
  Lcounter = 0;
  Rcounter = 0;
  while (true)
  {
    val();
    if (Lcounter >= turncount)
    {
      analogWrite(L_Mpwm, 0);
    }
    if (Rcounter >= turncount)
    {
      analogWrite(R_Mpwm, 0);
    }
    if (Lcounter >= turncount && Rcounter >= turncount)
    {
      delay(250);
      break;
    }
  }
}
void val ()
{
  if (left_pre != digitalRead(left_en))
  {
    Lcounter++; 
    left_pre = digitalRead(left_en);
  }
  if (right_pre != digitalRead(right_en))
  {
    Rcounter++;
    right_pre = digitalRead(right_en);
  }
}