/* Project: Line Following Robot 
// Name : Amy Wu
// Date : 11/8/2018
// Version : 1.1
// Description: Line Following Robot with Sensors in "v" formation with attempt to implement PID control
*/
//Variables

//Sensors
const int S1 = A0; //left sensor//analog pin 1
const int S2 = A1; //left middle sensor//analog pin 2
const int S3 = A2; //middle sensor//analog pin 3
const int S4 = A3; //right middle sensor//analog pin 4
const int S5 = A4; //right sensor//analog pin 5
//LED
const int LED1 = 4;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 12;
const int LED5 = 13;

//mode
int mode;
int RMSpeed;
int LMSpeed;

//Left Motor
#define LMEn 3 //enable on motor connected to pwm pin
#define LM1 6 //input 1 left motor
#define LM2 5 //input 2 left motor

//Right Motor
#define RMEn 11 //enable on motor connected to pwm pin
#define RM1 10 //input 1 right motor
#define RM2 9 //input 2 right motor

//Values for MODE - the decision the robot makes during the course
# define  NOLINE  0 //cannot find line
# define  RCOR 1 //right turn
# define  LCOR 2 //left turn
# define  SR 3 //sharp right turn
# define  SL 4 //sharp left turn
# define  GAP 5 //gap - move forward
# define  ONLINE 6 //on the line with no error
# define  FOLLOWSR 7 //on the line with slight error - correction needed
# define  FOLLOWR 8 //on the line with error - correction needed
# define  FOLLOWSL 9 //on the line with error - correction needed
# define  FOLLOWL 10 //on the line with error - correction needed
# define LEFT 11
# define RIGHT 12
# define INTERSECTION 13
# define GAP 14
# define STOP 30
# define DELAYTIME 100


int sread1;
int sread2;
int sread3;
int sread4;
int sread5;
void printr (int sen1, int sen2, int sen3, int sen4, int sen5);
void LED(int sen1, int sen2, int sen3, int sen4, int sen5);
//Calculations
#define THRESH  250
int senpos[]={0, 0, 0, 0, 0}; //position array 1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // defining sensors 1-5
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
// defining motor pins
  pinMode(LMEn,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RMEn,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
}
