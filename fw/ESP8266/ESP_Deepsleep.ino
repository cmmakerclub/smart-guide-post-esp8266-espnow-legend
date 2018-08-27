/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 12;
int warning = 14;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(warning, OUTPUT);
  digitalWrite(warning, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  digitalWrite(warning, HIGH);
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
  setSleep(10);//ตั้งเวลาหลับ = 10 วิ

}
void setSleep(int timeOut) {
  int constant = 1000;//Dont Change
  int changeSec = 1000 * timeOut;
  ESP.deepSleep(changeSec * constant); //Process
}


