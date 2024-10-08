float counter = 0;  //This variable will increase or decrease depending on the rotation of encoder
String aci1="1.aci: ";
float counter2 = 0;  //This variable will increase or decrease depending on the rotation of encoder
String aci2="/2.aci: ";
float counter3 = 0;  //This variable will increase or decrease depending on the rotation of encoder
String aci3="/3.aci: ";
void setup() {
  Serial.begin (9600);
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(20, ai0, RISING);
  
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(21, ai1, RISING);
  attachInterrupt(18, ai2, RISING);
  attachInterrupt(19, ai3, RISING);
  attachInterrupt(22, ai4, RISING);
  attachInterrupt(23, ai5, RISING);
}

void loop() {
  // Send th2e value of counter
  Serial.println (aci1+counter+aci2+counter2+aci3+counter3);
  delay(20);
}

void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(21)==LOW) {
    counter=counter+0.17;
  }else{
    counter=counter-0.17;
  }
}

void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(20)==LOW) {
    counter=counter-0.17;
  }else{
    counter=counter+0.17;
  }
}
void ai2() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(19)==LOW) {
    counter2=counter2+0.17;
  }else{
    counter2=counter2-0.17;
  }
}

void ai3() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(18)==LOW) {
    counter2=counter2-0.17;
  }else{
    counter2=counter2+0.17;
  }
}
void ai4() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(23)==LOW) {
    counter3=counter3+0.17;
  }else{
    counter3=counter3-0.17;
  }
}

void ai5() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(22)==LOW) {
    counter3=counter3-0.17;
  }else{
    counter3=counter3+0.17;
  }
}
