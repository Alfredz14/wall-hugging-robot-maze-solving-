#define L_Mdir 7
#define L_Mpwm 9
#define R_Mdir 8
#define R_Mpwm 10

#define left_en 4
#define right_en 5

#define LSens A2  //left sensor
#define MSens A1  //orta sensör
#define RSens A0  //sağ sensör
#define SensPin 12
#define QtrSens A3

#define button A6  //

#define LeftLed 11
#define RightLed 6

int dif = 0;

//sensor
int sensor = 100;  //135
int frontSens = 0;
int rightSens = 0;


//setting
int turncount = 187;

//speed
int Lspeed = 100;
int Rspeed = 100;  //153

//encoder
int Lcounter = 0;
int Rcounter = 0;
int left_pre = 0;
int right_pre = 0;

int squareL = 710;

void setup() {
  Serial.begin(9600);
  pinMode(L_Mdir, OUTPUT);
  pinMode(L_Mpwm, OUTPUT);
  pinMode(R_Mdir, OUTPUT);
  pinMode(R_Mpwm, OUTPUT);


  pinMode(LSens, INPUT);
  pinMode(RSens, INPUT);
  pinMode(MSens, INPUT);
  pinMode(SensPin, OUTPUT);
  digitalWrite(SensPin, HIGH);

  pinMode(left_en, INPUT);
  pinMode(right_en, INPUT);

  pinMode(button, INPUT);
  pinMode(LeftLed, OUTPUT);
  pinMode(RightLed, OUTPUT);

  digitalWrite(RightLed, LOW);
  digitalWrite(LeftLed, LOW);

  /*while (true)
  {
    left();
    //straight();
  }*/


  while (true) {
    if (analogRead(button) > 800) {
      ledblink(6);
      break;
    }
  }
  /*straightL(squareL);  //BAŞTAN EZBER
  left();
  straightL(squareL*2);
  left();
  straightL(squareL);
  right();
  straightL(squareL);
  right();
  straightL(squareL*3);
  right();
  straightL(squareL);
  left();
  while(true)
  {
    straight();
    if(analogRead(MSens) > sensor+450)
    {
      break;
    }
  }
  left();
  straightL(squareL*2);
  right();
  straightL(squareL-75);
  right();
  straightL(squareL*2+215);
  left();
  straightL(squareL);
  left();
  straightL(squareL*4+375);
  right();
  straightL(squareL*2);

  /*left();
  straightL(squareL*4+375);
  right();
  straightL(squareL);
  right();
  straightL(squareL*2+250);
  left();
  straightL(squareL-350);
  left();
  straightL(squareL*2);
  right();
  straightL(squareL);
  right();
  straightL(squareL);
  left();
  straightL(squareL*3);
  left();
  straightL(squareL);
  left();
  straightL(squareL);
  right();
  straightL(squareL*2);
  right();
  straightL(squareL*2);*/


  while (1) {
    val();
    straight();
    Serial.print(Lcounter);
    Serial.print("\t");
    Serial.print(Rcounter);
    Serial.println("\t");
  }
}

void loop() {
  if (analogRead(MSens) > sensor + 150 && analogRead(RSens) > sensor)  //ön dolu sağ dolu / ÖN SENSÖR DEĞERİ ARTACAK
  {
    left();
    if (analogRead(MSens) > sensor) {
      left();
    }
  } else if (analogRead(MSens) < sensor + 150 && analogRead(RSens) > sensor)  //ön boş sağ dolu
  {
    straight();
  } else if (analogRead(RSens) < sensor)  //sağ boş
  {
    straightL(650);
    right();
    straightL(700);                        //618
    if (analogRead(RSens) < sensor + 220)  //sağ boş
    {
      right();
      straightL(700);  //618
    }
  }




  /*straightL(squareL);
  left();
  straightL(squareL);
  right();
  straightL(squareL*2);
  left();
  straightL(squareL);  
  right();
  straightL(squareL*2+375);
  left();
  straightL(squareL+85);
  right();
  straightL(squareL); 
  left();
  straightL(squareL-30);
  left();
  straightL(squareL-75);
  right();  
  straightL(squareL*2);
  right();
  straightL(squareL*2);     
  right();
  straightL(squareL*4);   */
}

//ön dolu: if(analogRead(MSens) > sensor)
//ön boş: if(analogRead(MSens) < sensor)
//sağ dolu: if(analogRead(RSens) > sensor)
//sağ boş: if(analogRead(RSens) < sensor)
