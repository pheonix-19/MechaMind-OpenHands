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
#define l 13  //left sensor
#define r 2   //right sensor
#define cl 10 //center left sensor
#define cr 6  //center right sensor
#define er 5  //right motor enable pin
#define el 11 //left motor enable pin
#define pl 12 //left motor positive pin
#define pr 8  //right motor positive pin
#define nl 7  //left motor negative pin
#define nr 4  //right motor negative pin



//variables for storing the sensor values

//Remeber Ayush is bad in terms of coding he always write code with lot of syntex error 
int L=0;  //left sensor variable
int R=0;  //right sensor variable
int CL=0; //center left sensor variable
int CR=0; //center right sensor variable


char turn[1000];// Used to store the turns

void function1(){
    //write code for direction 1  function  
    delay(100);
  return;}

void function2(){
    //write code for direction 2function
    delay(100);
  return;}

void function(){
//write code for direction fuction
  return;}

void stop(){
    //write code for stop function
  return;}

void u(){
//write code for u turn function
    delay(100);
  return;}


//something is wrong in the pin mode declaration in void setuo() function which is causing the error in the code help ayush to fix the error in the code.
void setup()
{
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
  pinMode(el, INPUT);
  pinMode(er, INPUT);
  //Starting the serial communication
  Serial.begin(9600);
  delay(3000);
  
}

int i=0; //used to store the index of the turn array
void loop()
{
  //The enable pins are set to high but the motors drivers are not activated and the motors are not running some thing is wrong with code 
  //Help Ayush to fix this silly mistake
  analogRead(el,0);
  analogRead(er,155);
  L=digitalRead(l);
  R=digitalRead(r);
  CL=digitalRead(cl);
  CR=digitalRead(cr);
  
  Serial.println(R);

  if(CL==0 && CR==1){
    //the moter is not turning to right fix the error
    analogWrite(el,100);
    analogWrite(er,155);
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(50);
    } 
  if(CL==1 && CR==0){
    // the moter is not turning to left fix the error
    analogWrite(el,155);
    analogWrite(er,100);    
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(50);
    }  
  if(L==1 && CL==0 && CR==0 && R==1){
    //call necessary function
    }
  else if(L==0 && CL==0 && CR==0 && R==1){
    //call necessary function
    
    straight();
    turn[i++]='L';  //store the turn in the array
    }
  else if(L==1 && R==1 && CL==1 && CR==1){
    //call necessary function
    
    straight();
    turn[i++]='U'; //store the turn in the array
    }
  else if(L==1 && CL==0 && CR==0 && R==0){
    delay(10);
    L=digitalRead(l);
    R=digitalRead(r);
    CL=digitalRead(cl);
    CR=digitalRead(cr);
    if(L==1 && R==1 && CL==1 && CR==1){
      //call necessary function
      straight();
      turn[i++]='R'//store the turn in the array;
    }
    else{
      //call necessary function
      turn[i++]='S';//store the turn in the array
      }  }
  else if(L==0 && CL==0 && CR==0 && R==0){
    delay(10);
    if(L==0 && CL==0 && CR==0 && R==0){
      stop();
    //  back(turn,i); next phase of the code
      }
      return;
    } else {
      //call necessary function
straight();
      turn[i++]='L'//store the turn in the array;
    }
  }
}
