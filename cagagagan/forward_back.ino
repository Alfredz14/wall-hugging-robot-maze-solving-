void straightL(int lenght) {
  analogWrite(R_Mpwm, Rspeed);
  analogWrite(L_Mpwm, Lspeed);
  digitalWrite(L_Mdir, LOW);
  digitalWrite(R_Mdir, HIGH);
  Lcounter = 0;
  Rcounter = 0;
  while (true) {
    if (analogRead(RSens) > 150 && analogRead(LSens) > 150) {
      dif = analogRead(RSens) - analogRead(LSens);
      analogWrite(R_Mpwm, Rspeed + (dif / 20));
      analogWrite(L_Mpwm, Lspeed - (dif / 20));
    } else if (analogRead(RSens) > 150) {
      analogWrite(R_Mpwm, Rspeed + (analogRead(RSens) - 350) / 10);
      analogWrite(L_Mpwm, Lspeed);
    } else if (analogRead(LSens) > 150)  //150
    {
      analogWrite(L_Mpwm, Lspeed + (analogRead(LSens) - 350) / 10);
      analogWrite(R_Mpwm, Rspeed);
    } else {
      analogWrite(L_Mpwm, Lspeed);
      analogWrite(R_Mpwm, Rspeed);
    }
    val();
    if (Lcounter > lenght || Rcounter > lenght) {
      break;
    }
  }
}

void straight() {
  digitalWrite(L_Mdir, LOW);
  digitalWrite(R_Mdir, HIGH);
  if (analogRead(RSens) > 150 && analogRead(LSens) > 150) {
    dif = analogRead(RSens) - analogRead(LSens);
    analogWrite(R_Mpwm, Rspeed + (dif / 20));
    analogWrite(L_Mpwm, Lspeed - (dif / 20));
  } else if (analogRead(RSens) > 150) {
    analogWrite(R_Mpwm, Rspeed + (analogRead(RSens) - 350) / 10);
    analogWrite(L_Mpwm, Lspeed);
  } else if (analogRead(LSens) > 150)  //150
  {
    analogWrite(L_Mpwm, Lspeed + (analogRead(LSens) - 350) / 10);
    analogWrite(R_Mpwm, Rspeed);
  } else {
    analogWrite(L_Mpwm, Lspeed);
    analogWrite(R_Mpwm, Rspeed);
  }
}
void Mstop() {
  analogWrite(L_Mpwm, 0);
  analogWrite(R_Mpwm, 0);
}
