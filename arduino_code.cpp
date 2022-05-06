int sen_1=14;
int sen_2=15;
int sen_3=16;
int sen_4=17;

int out_1;
int out_2;
int out_3;
int out_4;

int b_1=2;
int b_2=3;
int b_3=4;

int interval = 3000;

unsigned long pmillis1=0;
unsigned long pmillis2=0;
unsigned long pmillis3=0;

void setup() {
  Serial.begin(9600);
  pinMode(sen_1,INPUT);
  pinMode(sen_2,INPUT);
  pinMode(sen_3,INPUT);
  pinMode(sen_4,INPUT);

  pinMode(b_1,OUTPUT);
  pinMode(b_2,OUTPUT);
  pinMode(b_3,OUTPUT);
}
bool y1,y2,y3;
void loop() {
  out_1= digitalRead(sen_1);
  out_2= digitalRead(sen_2);
  out_3= digitalRead(sen_3);
  out_4= digitalRead(sen_4);

  if (out_1==LOW){
    analogWrite(b_1,255);
    unsigned long cmillis1 = millis();
    pmillis1= cmillis1+interval;
    y1=1;
  }

  if (y1==1){
      unsigned long cmillis1 = millis();
      if (cmillis1 >= pmillis1){
        analogWrite(b_1,10);
        y1=0;
    }
  }
  
  if (out_4==LOW){
    analogWrite(b_3,255);
    unsigned long cmillis3 = millis();
    pmillis3= cmillis3+interval;
    y3=1;
  }

  if (y3==1){
      unsigned long cmillis3 = millis();
      if (cmillis3 >= pmillis3){
        analogWrite(b_3,10);
        y3=0;
    }
  }
  
  if (out_2==LOW or out_3==LOW){
    analogWrite(b_2,255);
    unsigned long cmillis2 = millis();
    pmillis2= cmillis2+interval;
    y2=1;
  }

  if (y2==1){
      unsigned long cmillis2 = millis();
      if (cmillis2 >= pmillis2){
        analogWrite(b_2,10);
        y2=0;
    }
  }
  
}
