const int ledred =  0;// the number of the LED pin
const int ledgreen =  1;// the number of the LED pin
const int sensor = 4;
const int esp_in = 2;
const int esp_out = 3;

//const int ledred =  2;// the number of the LED pin
//const int ledgreen =  3;// the number of the LED pin
//const int sensor = A0;
//const int esp_in = 7;
//const int esp_out = 12;

boolean lastState;
boolean lastState1;
boolean ledStatered = LOW;             // ledState used to set the LED
boolean ledStategreen = LOW;             // ledState used to set the LED

unsigned long previousMillisred = 0;        // will store last time LED was updated
unsigned long previousMillisgreen = 0;        // will store last time LED was updated
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long previousMillis1 = 0;        // will store last time LED was updated

unsigned long previousMillisesp = 0;        // will store last time LED was updated

int red_enable = 0;
int green_enable = 1;
int esp_enable = 0;

// constants won't change:
const long interval_red = 50;           // interval at which to blink (milliseconds)
const long interval_green = 250;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(sensor, INPUT_PULLUP);
  pinMode(esp_in, INPUT_PULLUP);
  pinMode(esp_out, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
//  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();
  unsigned long currentMillis1 = millis();
  unsigned long showTime = millis();

  //////////////////////////////////////////////////////////////////// || reading == Sensor
  if (showTime - previousMillis >= 10) {
    previousMillis = showTime;
    boolean reading = digitalRead(sensor) && digitalRead(sensor);
    if ( reading == LOW  && lastState == HIGH ) {
      esp_enable = 15000 / 10; //ปรับเวลา กระพริบ 2 นาที
    }
    lastState = reading;

    if (esp_enable > 0) esp_enable --;
    else (esp_enable = 0);

    // Serial.println(reading);
  }
  /////////////////////////////////////////////////////////////////// || reading1 == ESP
  if (showTime - previousMillis1 >= 10) {
    previousMillis1 = showTime;
    boolean reading1 = digitalRead(esp_in) && digitalRead(esp_in);
    if ( reading1 == LOW  && lastState1 == HIGH ) {
      red_enable = 15000 / 10; //ปรับเวลา กระพริบ 2 นาที
    }
    lastState1 = reading1;

    if (red_enable > 0) red_enable --; 
    else (red_enable = 0);

    //     Serial.println(reading1);
  }
  //        else {
  //          (red_enable = 1);
  //

  //
  //      }

  //////////////////////////////////////////////////////////////////////////////
  if (currentMillis - previousMillisred >= interval_red / 2) {
    previousMillisred = currentMillis;
    if (red_enable)
    {
      if (ledStatered == LOW) {
        ledStatered = HIGH;
      } else {
        ledStatered = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(esp_out, HIGH);
      digitalWrite(ledgreen, LOW);
      digitalWrite(ledred, ledStatered);
    } else {
      digitalWrite(ledred, 0);
    }
  }

  if (currentMillis - previousMillisgreen >= interval_green / 2) {
    previousMillisgreen = currentMillis;
    if (!red_enable) {
      if (ledStategreen == LOW) {
        ledStategreen = HIGH;
      } else {
        ledStategreen = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(esp_out, LOW);
      digitalWrite(ledred, LOW);
      digitalWrite(ledgreen, ledStategreen);
    } else {
      digitalWrite(ledgreen, 0);
    }
  }
  //////////////////////////////////////////////////////////////////////////////////
  if (currentMillis1 - previousMillisesp >= 1) {
    previousMillisesp = currentMillis1;
    if (esp_enable)
    {
      digitalWrite(esp_out, HIGH);
    } else {
      digitalWrite(esp_out, LOW);
    }
  }

  if (currentMillis1 - previousMillisesp >= 1) {
    previousMillisesp = currentMillis1;
    if (!esp_enable) {
      // set the LED with the ledState of the variable:
      digitalWrite(esp_out, LOW);
    } else {
      digitalWrite(esp_out, HIGH);
    }
  }
}
