//Defining Arduino pins for direction and step 
const int dirPin = 9;
const int stepPin = 8;

#define Pot A0

int pot_val = 0;
int delay_val = 0;
int rpm = 0;

void setup() {
 pinMode(dirPin, OUTPUT);
 pinMode(stepPin, OUTPUT);
 pinMode(Pot, INPUT);
}

void loop() {
  //Reading the analog value received from the potentiometer
  pot_val = analogRead(Pot);

  //Mapping the received value from 0-1024 (0-5V) to 600 to 2 microseconds and defining as a delay value
  delay_val = map(pot_val, 0, 1023, 600, 2);

  //Making the motor stop when potentiometer value is 0
  if(!pot_val)
  {
    digitalWrite(stepPin, LOW);
  }
  //If the pot value is not 0, generating the pwm signal with 50% duty cycle using the delay values mapped from the potentiometer input
  else
  {
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(delay_val);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(delay_val);
  }
  
}
