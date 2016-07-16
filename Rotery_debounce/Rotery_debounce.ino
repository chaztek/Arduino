int num = 0;
int lastNum = 0;
int pinA = 3;
int pinB = 4;

int thisPos = 0;
int lastPos = 0;
boolean goingUp = false;
boolean goingDown = false;
void setup(){
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);


}

void loop(){
  boolean isA = (digitalRead(pinA)==HIGH);//turn pinA into a boolean, isA
  boolean isB = (digitalRead(pinB)==HIGH);//turn pinB into a boolean, isB


  thisPos=(isA)?((isB)?2:1):
  ((isB)?3:0);//Convert quad to 0 to 3

  if(thisPos==0&&lastPos==3&&goingUp){//if encoder gets to 0 from 3 and we were given permission to count up then count up and reset permissions
    num++;
    goingUp = false;
    goingDown = false; 
  }
  if(thisPos==0&&lastPos==1&&goingDown){//if encoder gets to 0 from 1 and we were given permission to count down then count down and reset permissions
    num--; 
    goingUp = false;
    goingDown = false; 
  }

  if(thisPos==2&&lastPos==1)goingUp=true;//if encoder is rolling up then allow program to count up when it gets to zero
  if(thisPos==1&&lastPos==2)goingDown=true;//if encoder is rolling down then allow program to count down when it gets to zero

  lastPos=thisPos;//set lastPos for next loop
  if(num!=lastNum){//if the number has changed, print it
    lastNum = num;//set lastNum for next report
    Serial.println(num);
  }
}

