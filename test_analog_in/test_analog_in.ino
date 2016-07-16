
void setup()
{                
  Serial.begin(38400);
}

int val;

void loop()                     
{
  val = analogRead(11);
  Serial.print("analog 11 is: ");
  Serial.println(val);
  delay(250);
}
