const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 7;
const int echoPin2 = 8;
// defines variables

long duration1;
int distance1;
long duration2;
int distance2;

void check(int,int);
void right();
void foreward();
void backward();
void left();

int motorpin1=2;
int motorpin2=3;
int motorpin3=4;
int motorpin4=5;

void uturn();

void setup() {
    pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
    pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
    pinMode(motorpin1, OUTPUT);
    pinMode(motorpin2, OUTPUT); 
    pinMode(motorpin3, OUTPUT);
    pinMode(motorpin4, OUTPUT);
    Serial.begin(9600); // Starts the serial communication
}

void loop() {
    
    // Clears the trigPin
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration1 = pulseIn(echoPin1, HIGH);
    // Calculating the distance
    distance1= duration1*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance1: ");
    Serial.println(distance1);

   // likewise for second ultrasonic sensor
   
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2= duration2*0.034/2;
    Serial.print("Distance2: ");
    Serial.println(distance2);

    //calling the check function to check
    check(distance1,distance2);
}

void check(int d1,int d2)
{
  // both values lies between 1-2 cms from wall then the wheels moves foreward..............
  if(d1<2.5 && d2<2.5){foreward();}

  // if one of the distance is greater than 3cms from wall then we need to check which of the sensor is far from the wall
  if( d1>2.5 )
  {
    if( d2<2.5 ) // the backward sensor is nearer to wall --> i.e the robot is going to take turn in the direstion such that the  
    {
      while(d2<2.5 && d2>1.5)
      {
       uturn();
      }  
    }  
  }

   
}

void right()
{ 
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
}

void foreward()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
}

void left()
{ 
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
}

void backward()
{
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
}


void uturn()
{
  /*
   we have to check with the practical work and then edit this block of code
   */
}
