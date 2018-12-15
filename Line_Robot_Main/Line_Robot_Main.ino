// Project: Line Following Robot 
// Name : Amy Wu
// Date : 11/8/2018
// Version : 1.1
// Description: Line Following Robot with Sensors in "v" formation with attempt to implement PID control

//Variables

//Sensors
#define S1 A1 //left sensor//analog pin 1
#define S2 A2 //left middle sensor//analog pin 2
#define S3 A3 //middle sensor//analog pin 3
#define S4 A4 //right middle sensor//analog pin 4
#define S5 A5 //right sensor//analog pin 5


//Left Motor
#define LMEn 5 //enable on motor connected to pwm pin
#define LM1 6 //input 1 left motor
#define LM2 7 //input 2 left motor

//Right Motor
#define RMEn 8 //enable on motor connected to pwm pin
#define RM1 9 //input 1 right motor
#define RM2 10 //input 2 right motor

//Analog
#define BLACK 1 //line colour
#define WHITE 0 //paper colour
#define SENTINAL 0
#define ON 1
#define OFF 0

//Values for MODE - the decision the robot makes during the course
# define NOLINE = 0 //cannot find line
# define RCOR = 1 //right 90 degree turn
# define LCOR = 2 //left 90 degree turn
# define SR = 3 //sharp right turn
# define SL = 4 //sharp left turn
# define GAP = 5 //gap - move forward
# define ONLINE = 6 //on the line with no error
# define FOLLOW = 7 //on the line with error - correction needed
int error; //error for PID control 

//Calculations
#define offread 20
#define avg
#define compare
#define nr 5; //number of readings from the sensor
int senpos[5]={0, 0, 0, 0, 0}; //position array 

//Function Prototypes

//Function: Average Sensor Reading
//---------------------------------
//Description: takes in sensorpin and readings and takes the average of number of readings from Sensorpin and returns the average, if the value is > error tolerance, it takes another reading
int ASR (int SensorPin, int readings, int errortol);

//Function: Position Array
//---------------------------------
//Description: takes in the averaged sensor readings and inputs them into the position array
int posArr (int sen1avg, int sen2avg, int sen3avg, int sen4avg, int sen5avg);

void setup() {
  // put your setup code here, to run once:

// defining sensors 1-5
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
// defining motor pins
  pinMode(LMEn, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RMEn, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

 
