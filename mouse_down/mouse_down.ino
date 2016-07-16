void setup(){
  //The switch that will initiate the Mouse press
  pinMode(25,OUTPUT);
  //The switch that will terminate the Mouse press
  pinMode(18,INPUT);
 digitalWrite(25, LOW);
  
  
  //Start serial communication with the computer
  Serial1.begin(9600);
  //initiate the Mouse library

  
  Mouse.begin();
}

void loop(){
  //a variable for checking the button's state
  int mouseState=0;
  //if the switch attached to pin 2 is closed, press and hold the right mouse button and save the state ina  variable
  if(digitalRead(18) == HIGH){
    Mouse.press();
    mouseState=Mouse.isPressed();
  //if the switch attached to pin 3 is closed, release the rig
  }
 // ht mouse button and save the state in a variable
  if(digitalRead(18) == LOW){
    Mouse.release();
    mouseState=Mouse.isPressed();
  }
  //print out the current mouse button state
  Serial1.println(mouseState);
  delay(10);
}
 
