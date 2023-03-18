#include <Servo.h>
Servo servo1, servo2, servo3, servo4, servo5, servo6;

int potPin = 0;             // analog pin that will be used to read the value of the potentiometer
int speedPotPin = 1;        // analog pin that will be used to read the speed of the servo
double potVal = 0;          // variable to store the value of the potentiometer which will tell which strings to strike
double speedPotVal = 0;     // variable to store the speed of striking

int pulseWidth, delayTime;  // Initialise variables to store the pulse width and delay time of the servo

int potDelay = 100;

int button1Pin = 1;
int button2Pin = 2;
int button3Pin = 3;
int button4Pin = 4;
int button5Pin = 5;
int button6Pin = 6;
int switchPin = 7;


int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;
int switchPinState = 0;

// Define variables to store previous button states
int button1PrevState = LOW;
int button2PrevState = LOW;
int button3PrevState = LOW;
int button4PrevState = LOW;
int button5PrevState = LOW;
int button6PrevState = LOW;

int debounceDelay = 5;

int servo1Angle = 20;
int servo2Angle = 45;
int servo3Angle = 70;
int servo4Angle = 95;
int servo5Angle = 120;
int servo6Angle = 145;

int servo1Target = 35;
int servo2Target = 60;
int servo3Target = 85;
int servo4Target = 110;
int servo5Target = 135;
int servo6Target = 160;

int servo1Current = 0, servo2Current = 0;
int servo3Current = 0, servo4Current = 0;
int servo5Current = 0, servo6Current = 0;

/**
    The setup function is called whenever the Arduino board is initialised/re-initialised
    It is used to initialize variable, setup modes for digital pins, setup communications and start libraries.
*/
void setup()
{
    servo1.attach(8);        // attach the servo to pin 9
  	servo2.attach(9);
  	servo3.attach(10);
  	servo4.attach(11);
  	servo5.attach(12);
  	servo6.attach(13);
  
    pinMode(A0, INPUT);     // set the first analog pin as input
    pinMode(A1, INPUT);     // set the second analog pin as input
    
  	servo1.write(servo1Angle);        // set the initial position of the servo to 20 degrees
	servo2.write(servo2Angle);
  	servo3.write(servo3Target);
  	servo4.write(servo4Target);
  	servo5.write(servo5Target);
  	servo6.write(servo6Target);
  
	pinMode(button1Pin, INPUT);
	pinMode(button2Pin, INPUT);
  	pinMode(button3Pin, INPUT);
  	pinMode(button4Pin, INPUT);
  	pinMode(button5Pin, INPUT);
  	pinMode(button6Pin, INPUT);
  	pinMode(switchPin, INPUT);

}

/*
    This funciton will be called continuously as long as the arduino board is ON
*/
void loop()
{
  potVal = analogRead(potPin);    // read the value of the potentiometer
  speedPotVal = analogRead(speedPotPin);  // read the speed of the servo

  if (potVal == 0){
  	handleButton1Press();
    handleButton2Press();
    handleButton3Press();
    handleButton4Press();
    handleButton5Press();
    handleButton6Press();
  }
  else{
  	potStriking();
  }
  
  
}

void handleButton1Press(){
button1State = digitalRead(button1Pin);
 
  if (button1State != button1PrevState) {
    delay(debounceDelay);
    if (button1State == LOW) {
      
      servo1Current = servo1.read();
      if (servo1Current == servo1Angle) {
        servo1Current = servo1Target;
      } else {
        servo1Current = servo1Angle;
      }
      // Move the servo to the new position
      servo1.write(servo1Current);
    }
    // Update the last button state
    button1PrevState = button1State;
   }
}

void handleButton2Press(){
button2State = digitalRead(button2Pin);
 
  if (button2State != button2PrevState) {
    delay(debounceDelay);
    if (button2State == LOW) {
      
      servo2Current = servo2.read();
      if (servo2Current == servo2Angle) {
        servo2Current = servo2Target;
      } else {
        servo2Current = servo2Angle;
      }
      // Move the servo to the new position
      servo2.write(servo2Current);
    }
    // Update the last button state
    button2PrevState = button2State;
   }
}

void handleButton3Press(){
button3State = digitalRead(button3Pin);
 
  if (button3State != button3PrevState) {
    delay(debounceDelay);
    if (button3State == LOW) {
      
      servo3Current = servo3.read();
      if (servo3Current == servo3Angle) {
        servo3Current = servo3Target;
      } else {
        servo3Current = servo3Angle;
      }
      // Move the servo to the new position
      servo3.write(servo3Current);
    }
    // Update the last button state
    button3PrevState = button3State;
   }
}

void handleButton4Press(){
button4State = digitalRead(button4Pin);
 
  if (button4State != button4PrevState) {
    delay(debounceDelay);
    if (button4State == LOW) {
      
      servo4Current = servo4.read();
      if (servo4Current == servo4Angle) {
        servo4Current = servo4Target;
      } else {
        servo4Current = servo4Angle;
      }
      // Move the servo to the new position
      servo4.write(servo4Current);
    }
    // Update the last button state
    button4PrevState = button4State;
   }
}

void handleButton5Press(){
button5State = digitalRead(button5Pin);
 
  if (button5State != button5PrevState) {
    delay(debounceDelay);
    if (button5State == LOW) {
      
      servo5Current = servo5.read();
      if (servo5Current == servo5Angle) {
        servo5Current = servo5Target;
      } else {
        servo5Current = servo5Angle;
      }
      // Move the servo to the new position
      servo5.write(servo5Current);
    }
    // Update the last button state
    button5PrevState = button5State;
   }
}

void handleButton6Press(){
button6State = digitalRead(button6Pin);
 
  if (button6State != button6PrevState) {
    delay(debounceDelay);
    if (button6State == LOW) {
      
      servo6Current = servo6.read();
      if (servo6Current == servo6Angle) {
        servo6Current = servo6Target;
      } else {
        servo6Current = servo6Angle;
      }
      // Move the servo to the new position
      servo6.write(servo6Current);
    }
    // Update the last button state
    button6PrevState = button6State;
   }
}


void potStriking(){
  
  switchPinState = digitalRead(switchPin);
  
  if (switchPinState == HIGH){
  	strikeFromBelow();
  }
  else{
  	strikeFromAbove();
  }
  
  
}

void strikeFromAbove(){
	while (potVal > 0 && potVal < 205 && switchPinState == LOW){
  	toggleServo(1, servo1Angle, servo1Target);
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(6, servo6Angle, servo6Target);
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 205 && potVal < 410 && switchPinState == LOW){
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(6, servo6Angle, servo6Target);
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 410 && potVal < 615 && switchPinState == LOW){
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(6, servo6Angle, servo6Target);
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 615 && potVal < 820 && switchPinState == LOW){
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(6, servo6Angle, servo6Target);
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 820 && potVal < 1023 && switchPinState == LOW){
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(6, servo6Angle, servo6Target);
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
}

void strikeFromBelow(){
	while (potVal > 0 && potVal < 205 && switchPinState == HIGH){
      toggleServo(6, servo6Angle, servo6Target);
      toggleServo(5, servo5Angle, servo5Target);
      toggleServo(4, servo4Angle, servo4Target);
      toggleServo(3, servo3Angle, servo3Target);
      toggleServo(2, servo2Angle, servo2Target);
  	  toggleServo(1, servo1Angle, servo1Target);
      
      switchPinState = digitalRead(switchPin);
      potVal = analogRead(potPin);
  }
  
  while (potVal > 205 && potVal < 410 && switchPinState == HIGH){
    toggleServo(5, servo5Angle, servo5Target);
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(1, servo1Angle, servo1Target);
    
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 410 && potVal < 615 && switchPinState == HIGH){
    toggleServo(4, servo4Angle, servo4Target);
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(1, servo1Angle, servo1Target);
    
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 615 && potVal < 820 && switchPinState == HIGH){
    toggleServo(3, servo3Angle, servo3Target);
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(1, servo1Angle, servo1Target);
    
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
  
  while (potVal > 820 && potVal < 1023 && switchPinState == HIGH){
    toggleServo(2, servo2Angle, servo2Target);
    toggleServo(1, servo1Angle, servo1Target);
    
    potVal = analogRead(potPin);
    switchPinState = digitalRead(switchPin);
  }
}


void toggleServo(int servoNumber, int servoAngle, int servoTarget) {
  speedPotVal = analogRead(speedPotPin);
  potDelay = map(speedPotVal, 0, 1023, 100, 5);
  
  int currentAngle = 0;
  
  switch(servoNumber) {
    case 1:
      	currentAngle = servo1.read();
        if (currentAngle == servo1Angle) {
          currentAngle = servo1Target;
        } else {
          currentAngle = servo1Angle;
        }
        servo1.write(currentAngle);
    	delay(potDelay);
    	break;
    
    case 2:
    	currentAngle = servo2.read();
        if (currentAngle == servo2Angle) {
          currentAngle = servo2Target;
        } else {
          currentAngle = servo2Angle;
        }
        servo2.write(currentAngle);
    	delay(potDelay);
    	break;
    
    case 3:
    	currentAngle = servo3.read();
        if (currentAngle == servo3Angle) {
          currentAngle = servo3Target;
        } else {
          currentAngle = servo3Angle;
        }
        servo3.write(currentAngle);
    	delay(potDelay);
    	break;
    
    case 4:
    	currentAngle = servo4.read();
        if (currentAngle == servo4Angle) {
          currentAngle = servo4Target;
        } else {
          currentAngle = servo4Angle;
        }
        servo4.write(currentAngle);
    	delay(potDelay);
    	break;
    
    case 5:
    	currentAngle = servo5.read();
        if (currentAngle == servo5Angle) {
          currentAngle = servo5Target;
        } else {
          currentAngle = servo5Angle;
        }
        servo5.write(currentAngle);
    	delay(potDelay);
    	break;
    
    case 6:
    	currentAngle = servo6.read();
        if (currentAngle == servo6Angle) {
          currentAngle = servo6Target;
        } else {
          currentAngle = servo6Angle;
        }
        servo6.write(currentAngle);
    	delay(potDelay);
    	break;
    
    default:
    	break;
  }
  

}