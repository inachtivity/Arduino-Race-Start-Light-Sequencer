#include <stdio.h>
#include <stdlib.h>
#define MIN 200
#define MAX 3000

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 8;
int LED5 = 7;

int buttonPin = 2;
int buttonState = 0;

int n, min = MIN, max = MAX;

void setup() {
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
  pinMode (LED5, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {

  n = rand() % (max - min + 1) + min;
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED4, HIGH);
    delay(1000);
    digitalWrite(LED5, HIGH);

    delay(n);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);

  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } 
}
