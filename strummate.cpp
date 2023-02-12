#include <Servo.h>
Servo servo;

int potPin = 0;             // analog pin that will be used to read the value of the potentiometer
int speedPotPin = 1;        // analog pin that will be used to read the speed of the servo
double potVal = 0;          // variable to store the value of the potentiometer which will tell which strings to strike
double speedPotVal = 0;     // variable to store the speed of striking

int pulseWidth, delayTime;  // Initialise variables to store the pulse width and delay time of the servo

/**
    The setup function is called whenever the Arduino board is initialised/re-initialised
    It is used to initialize variable, setup modes for digital pins, setup communications and start libraries.
*/
void setup()
{
    servo.attach(9);        // attach the servo to pin 9
    pinMode(A0, INPUT);     // set the first analog pin as input
    pinMode(A1, INPUT);     // set the second analog pin as input
    servo.write(20);        // set the initial position of the servo to 20 degrees
}

/*
    This funciton will be called continuously as long as the arduino board is ON
*/
void loop()
{
    potVal = analogRead(potPin);    // read the value of the potentiometer
    speedPotVal = analogRead(speedPotPin);  // read the speed of the servo

    // a loop to strike first two strings
    while (potVal > 0 && potVal <= 340)
    {
        // Value of i corresponds to the angle at which the servo should move
        for (int i = 20; i <= 90; i++)
        {
            pulseWidth = map(i, 0, 180, 500, 2500);       // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);          // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);         // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0); // map the speed of the servo to a delay time
            delay(delayTime);                  // delay the loop by the delay time
            potVal = analogRead(potPin);       // read the value of the potentiometer
        }

        // for loop to strike the strings in reverse
        for (int i = 90; i >= 20; i--)
        {
            pulseWidth = map(i, 0, 180, 500, 2500);     // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);        // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);      // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0);      // map the speed of the servo to a delay time
            delay(delayTime);                           // delay the loop by the delay time
            potVal = analogRead(potPin);                // read the value of the potentiometer
        }
    }

    // a loop to strike the four strings of the guitar
    while (potVal >= 341 && potVal <= 680)
    {
        for (int i = 20; i <= 120; i++)
        {
            pulseWidth = map(i, 0, 180, 500, 2500);     // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);        // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);      // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0);      // map the speed of the servo to a delay time
            delay(delayTime);                           // delay the loop by the delay time
            potVal = analogRead(potPin);                // read the value of the potentiometer
        }

        for (int i = 120; i >= 20; i--)
        {
            pulseWidth = map(i, 0, 180, 500, 2500);     // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);        // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);      // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0);  // map the speed of the servo to a delay time
            delay(delayTime);                           // delay the loop by the delay time
            potVal = analogRead(potPin);                // read the value of the potentiometer
        }
    }

    // a loop to strike the all the strings of the guitar
    while (potVal >= 681 && potVal <= 1024)
    {

        for (int i = 20; i <= 180; i++)
        {
            pulseWidth = map(i, 0, 180, 500, 2500);     // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);        // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);      // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0);  // map the speed of the servo to a delay time
            delay(delayTime);                           // delay the loop by the delay time
            potVal = analogRead(potPin);                // read the value of the potentiometer
        }

        for (int i = 180; i >= 20; i--)
        {

            pulseWidth = map(i, 0, 180, 500, 2500);     // map the value of i to a pulse width for the servo
            servo.writeMicroseconds(pulseWidth);        // write the pulse width to the servo

            speedPotVal = analogRead(speedPotPin);      // read the speed of the servo
            delayTime = map(speedPotVal, 0, 1023, 100, 0);  // map the speed of the servo to a delay time
            delay(delayTime);                              // delay the loop by the delay time
            potVal = analogRead(potPin);                // read the value of the potentiometer
        }
    }
}
