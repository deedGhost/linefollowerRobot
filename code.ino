#define R_SENSOR 6
#define L_SENSOR 7
#define SPEED 180
int enableR_Motor=9;
int r_Pin1=2;
int r_Pin2=3;
int enableL_Motor=11;
int l_Pin1=4;
int l_Pin2=5;
void rotation(int,int);

void setup()
{
  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  pinMode(enableR_Motor, OUTPUT);
  pinMode(r_Pin1, OUTPUT);
  pinMode(r_Pin2, OUTPUT);
  pinMode(enableL_Motor, OUTPUT);
  pinMode(l_Pin1, OUTPUT);
  pinMode(l_Pin2, OUTPUT);

  pinMode(R_SENSOR, INPUT);
  pinMode(L_SENSOR, INPUT);
  
  rotation(0,0);   
  Serial.begin(9600);
}

void loop()
{
  int r_SensorValue = digitalRead(R_SENSOR);
  int l_SensorValue = digitalRead(L_SENSOR);
  
  if (r_SensorValue == LOW && l_SensorValue == LOW)
  {
    rotation(SPEED,SPEED);
  }
  else if (r_SensorValue == HIGH && l_SensorValue == LOW )
  {
    rotation(-SPEED,SPEED); 
  }
  else if (r_SensorValue == LOW && l_SensorValue == HIGH )
  {
    rotation(SPEED,-SPEED); 
  } 
  else 
  {
    rotation(0,0);
  }
}

void rotation(int r_Speed,int l_Speed)
{
  if (r_Speed < 0)
  {
    digitalWrite(r_Pin1,LOW);
    digitalWrite(r_Pin2,HIGH);    
  }
  else if (r_Speed > 0)
  {
    digitalWrite(r_Pin1,HIGH);
    digitalWrite(r_Pin2,LOW);      
  }
  if (l_Speed < 0)
  {
    digitalWrite(l_Pin1,LOW);
    digitalWrite(l_Pin2,HIGH);    
  }
  else if (l_Speed > 0)
  {
    digitalWrite(l_Pin1,HIGH);
    digitalWrite(l_Pin2,LOW);      
  }
  else
  {
    digitalWrite(r_Pin1,LOW);
    digitalWrite(r_Pin2,LOW);
    digitalWrite(l_Pin1,LOW);
    digitalWrite(l_Pin2,LOW);       
  }
 analogWrite(enableR_Motor,abs(r_Speed));
 analogWrite(enableL_Motor,abs(l_Speed));
 }
