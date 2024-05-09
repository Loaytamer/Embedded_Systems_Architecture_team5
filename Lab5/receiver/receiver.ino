void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char buf[5] = "";
    //char data = Serial.read();
    Serial.readBytes(buf, 5);
    //Serial.println(data);
    Serial.println(buf);
  }
  //Serial.write('A');
  delay(1000);
}
