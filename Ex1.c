void setup(){
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
    //digitalWrite(i, HIGH);
    //delay(100);
  }
  
  
}

void loop(){
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
    delay(200);
  }
  
  for(int i = 9; i >= 2; i--){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    delay(200);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  //Serial.print("Hello computer!");
}

void loop() {
  // put your main code here, to run repeatedly:
  /* digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

  Serial.println("Hello computer!")
  */
  if (serial.available() > 0) {
    char data = Serial.read();
    if (data == 'a') {
      digitalWrite(2, HIGH);
    } else if (data == 'b') {
      digitalWrite(2, LOW);
    }
  }
}
