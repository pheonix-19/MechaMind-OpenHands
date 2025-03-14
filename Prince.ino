/*
A line following robot is a robotic car that follows a specified black line with the help of an infrared sensor. 
The infrared sensor gives an output in the form of 1 or 0 when it detects the black color. Based on the sensitivity of the sensor,
we have to write the code using Arduino programming language and incorporate the sensor feedback for the traversal of the robotic car.

In simpler terms, a line following robot is a small car or vehicle that can move along a black line drawn on the ground.
It uses an infrared sensor to detect the black line. When the sensor sees the black line, it sends a signal (either 1 or 0) to the Arduino microcontroller board.
The Arduino board is programmed with code that tells the robot how to move based on the sensor's input.If the sensor detects the line,
the robot will continue moving forward. If the sensor doesn't detect the line, the robot will adjust its direction to find the line again.
The sensitivity of the sensor determines how precisely it can detect the black line, and the Arduino code needs to be written accordingly
to ensure that the robot follows the line accurately.
  
  */

// /A student named Ayush got some incomplete Arduino code. Our task is to help him complete the code with valid arguments.

// /The code is given below:

// C++ code
#include <Arduino.h>
#define l 13  //left IR sensor
#define r 2   //right IR sensor
#define cl 10 //center left IR sensor
#define cr 6  //center right IR sensor
#define er 5  //right motor enable pin
#define el 11 //left motor enable pin
#define pl 12 //left motor positive pin
#define pr 8  //right motor positive pin
#define nl 7  //left motor negative pin
#define nr 4  //right motor negative pin

//variables for storing the sensor values

//Remeber Ayush is bad in terms of coding he always write code with lot of syntex error 
int L = 0;  //left sensor variable
int R = 0;  //right sensor variable
int CL = 0; //center left sensor variable
int CR = 0; //center right sensor variable

char turn[1000]; // Used to store the turns


void straight() {
  analogWrite(el, 150); 
  analogWrite(er, 150); 
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, HIGH);
  digitalWrite(pr, HIGH);
}

void slightLeft() {
  analogWrite(el, 100); 
  analogWrite(er, 170); 
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, HIGH);
  digitalWrite(pr, HIGH);
}

void slightRight() {
  analogWrite(el, 170); 
  analogWrite(er, 100); 
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, HIGH);
  digitalWrite(pr, HIGH);
}

void left() {
  //Sharp left turn 
  analogWrite(el, 70);  
  analogWrite(er, 200); 
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, HIGH);
  digitalWrite(pr, HIGH);
}

void right() {
  //Sharp right turn 
  analogWrite(el, 200); 
  analogWrite(er, 70);  
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, HIGH);
  digitalWrite(pr, HIGH);
}

void stop() {
  analogWrite(el, 0);
  analogWrite(er, 0);
  digitalWrite(nl, LOW);
  digitalWrite(nr, LOW);
  digitalWrite(pl, LOW);
  digitalWrite(pr, LOW);
}

void u() {
  analogWrite(el, 200);
  analogWrite(er, 200);
  digitalWrite(nl, LOW);
  digitalWrite(nr, HIGH); 
  digitalWrite(pl, HIGH); 
  digitalWrite(pr, LOW);
  delay(800);
}

void setup() {
  //Define the pin modes
  //Defining sensor pins as input
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  pinMode(cl, INPUT);
  pinMode(cr, INPUT);
  //Defining motor pins as output
  pinMode(pl, OUTPUT);
  pinMode(pr, OUTPUT);
  pinMode(nl, OUTPUT);
  pinMode(nr, OUTPUT);
  //Defining enable pins as output
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  //Starting the serial communication
  Serial.begin(9600);
  delay(3000);
  

}


bool returning = false; 
int i = 0; //used to store the index of the turn array
int return_index; 
void loop() {
  //The enable pins are set to high but the motors drivers are not activated and the motors are not running some thing is wrong with code 
  //Help Ayush to fix this silly mistake

  L = digitalRead(l);
  R = digitalRead(r);
  CL = digitalRead(cl);
  CR = digitalRead(cr);
  
  Serial.println(R);

  if (!returning) {
    // Outward journey logic
    if (L == 0 && R == 1)
      slightRight();
    else if (L == 1 && R == 0)
      slightLeft();
    if (CR == 0 && CL == 1)
      right();
    else if (CR == 1 && CL == 0)
      left();
    if (L == 1 && CL == 0 && CR == 0 && R == 1)
      straight();
    else if (L == 0 && CL == 0 && CR == 0 && R == 1) { 
      left();
      turn[i++] = 'L';
    }
    else if (L == 1 && R == 1 && CL == 1 && CR == 1) {
      u();
      turn[i++] = 'U';
    }
    else if (L == 1 && CL == 0 && CR == 0 && R == 0) {
      right();
      turn[i++] = 'R';   
    }
    else if (L == 0 && CL == 0 && CR == 0 && R == 0) {
      u(); // Turn around at the end
      returning = true;
      return_index = i - 1; // Start from the last recorded turn
    }
  } else {
    if (L == 0 && R == 1)
      slightRight();
    else if (L == 1 && R == 0)
      slightLeft();
    if (CR == 0 && CL == 1)
      right();
    else if (CR == 1 && CL == 0)
      left();
    if (L == 1 && CL == 0 && CR == 0 && R == 1)
      straight();
    else if (L == 0 && CL == 0 && CR == 0 && R == 1) { 
      if (return_index >= 0) {
        if (turn[return_index] == 'R') left();
        else if (turn[return_index] == 'L') right();
        else if (turn[return_index] == 'U') u();
        return_index--;
      }
    }
    else if (L == 1 && R == 1 && CL == 1 && CR == 1) {
      if (return_index >= 0) {
        if (turn[return_index] == 'R') left();
        else if (turn[return_index] == 'L') right();
        else if (turn[return_index] == 'U') u();
        return_index--;
      }
    }
    else if (L == 1 && CL == 0 && CR == 0 && R == 0) {
      if (return_index >= 0) {
        if (turn[return_index] == 'R') left();
        else if (turn[return_index] == 'L') right();
        else if (turn[return_index] == 'U') u();
        return_index--;
      }
    }
  }
}