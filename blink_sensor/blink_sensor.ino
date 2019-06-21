/*
Title: blink_sensor
Program Description:
  This program assumes that two LED pins (i.e. variables named led1 and led2) are attached 
  as well as a photocell (i.e. variable named A7).

  The program should change the speed which the two attached LEDS blink depending on the
  intensity of light measured by the photocell. 

*/

#include <math.h>
#define M_E 2.7182818284590452354 // euler's constant

int measure;   // This is the measurement of light which the photocell returns
int sec;       // This is the calculated amount of seconds for blinking
int incr = 0;  // This is for the exit code. Program stops after 100 iterations.
int photo = A7;
int led1 = 10; 
int led2 = 9;


void setup() {
  // Setup code goes here, it runs once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Main code here, runs repeatedly:
  
  
  measure = analogRead(A7);    // Measures photocell value

  // To find the seconds, the Sigmoid function was used.
     // The seconds should not be greater than 2000 ms or
     // or less than 100 ms. The range of 950 was chosen
     // because the observed environmental maxium measure-
     // ment of light was 1100 and the minimum was 800
  sec = 2000 / (1 + pow(M_E, measure - 950)) + 100;

  Serial.print(measure);
  Serial.print("    ");
  Serial.println(sec);

  //Blinking rotation code
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH);
  delay(sec);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(sec);

  // Exits program after 100 iterations
  incr++;
  if (incr == 100) exit(0);
}
