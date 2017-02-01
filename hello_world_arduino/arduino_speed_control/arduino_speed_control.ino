//encoder constants
#define encoder_left 5
#define encoder_right 6

//motor standards
#define motor_direction_left 12
#define motor_direction_right 13
#define motor_speed_left 3
#define motor_speed_right 11
#define motor_break_left 9
#define motor_break_right 8
#define motor_current_left 0
#define motor_current_right 1

//LED
#define LED 13

void setup() {
  //setup LED
  pinMode(LED,OUTPUT);
  
  //setup encoders
  pinMode(encoder_left,INPUT);
  pinMode(encoder_right,INPUT);

  //setup motors
  pinMode(motor_direction_left,OUTPUT);
  pinMode(motor_direction_right,OUTPUT);

  //speed is analog and does not need to be initialized

  pinMode(motor_break_left,OUTPUT);
  pinMode(motor_break_right, OUTPUT);

  pinMode(motor_current_left, INPUT);
  pinMode(motor_current_right, INPUT);
  digitalWrite(motor_break_left,LOW);

  //playground
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int motor_speed = 0;

  while(true)
  {
    analogWrite(motor_speed_left,motor_speed);
    motor_speed += directionOfChange(1,digitalRead(encoder_left));
    Serial.print(motor_speed);
    Serial.write("\n");
  }
}

int directionOfChange(bool reading1, bool reading2)
{
  int change = 0;
  
 if (reading1 && !reading2)
  {
    change = 1;
  }
  else if (!reading1 && reading2)
  {
    change = -1;
  }

  return change;
}

