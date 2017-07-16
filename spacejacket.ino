const int sensorPin = A5;
float sensorValue = 0;

float inch= 0;
float cm = 0;

const int C = 1046;


int blueLED  = 9;
int yellowLED = 6;
int redLED = 5;

int buzzerPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(4800);
}
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
//  Serial.println(sensorValue);
  inch = (sensorValue/4);
  cm = inch*2.54;
//  Serial.print(inch);
//  Serial.println("inch");
  Serial.println(cm);
//  Serial.println("cm");


  if (inch < 10){
    //turn on red light
    digitalWrite(redLED, HIGH);
    //turn on buzzer
    tone(buzzerPin, C);
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
  if(inch > 10 && inch < 48){
    //turn on yellow light
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, HIGH);
     noTone(buzzerPin);
  }
  if(inch > 48){
   //turn on blue light
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellowLED, LOW);
    noTone(buzzerPin);
  }

  delay(100);
}
