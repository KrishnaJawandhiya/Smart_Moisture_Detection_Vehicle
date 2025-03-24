#include <Servo.h>.
int La = 2; 
int Rb = 3;
int motor = 5;
int Lb = 6;
int Ra = 7; 
int IR = 8;
int red = 9;
int flame=11;
int ms=A0;
int data;
int test;
int test1;
int test2;
int test3;
int test5;
int ur;
Servo myServo;
Servo myServo1;
long duration;
int distance;
int ms_data;

void setup()
{
  Serial.begin(9600);
  pinMode(La, OUTPUT);
  pinMode(Rb, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(Lb, OUTPUT);
  pinMode(Ra, INPUT);
  pinMode(ms,INPUT);
  pinMode(IR, INPUT);
  pinMode(red,OUTPUT);
  pinMode(flame,INPUT);
  myServo.attach(4);
  myServo1.attach(10);
}

void loop()
{
  ms_data = analogRead(ms);
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
    ir_check();
    // ur=calculateDistance();
    // if(distance >= 2){
    if(data == 'R')
    {
      digitalWrite(Ra, HIGH);
      digitalWrite(Rb, LOW);
      digitalWrite(Lb, LOW);
      digitalWrite(La, LOW);
      ir_check();
    }
    else{
       if(data == 'L')
      {
        digitalWrite(Lb, LOW);
        digitalWrite(La, HIGH);
        digitalWrite(Rb, LOW);
        digitalWrite(Ra, LOW);
        ir_check();
     }
      else{

      if(data=='F')
      {
        ir_check();
        if(test5==0 && data=='F'){
        digitalWrite(Ra, HIGH);
        digitalWrite(La, HIGH);
        digitalWrite(Rb, LOW);
        digitalWrite(Lb, LOW);
        }
        else{
          break;
        }
      } 
      else
      {
        if(data=='D'){
          for(int i=0;i<=90;i++){  
            myServo.write(i); 
            delay(30); 
            // ir_check();                                                                                                                    
          }
        }
        else{
         if(data=='U'){
          for(int i=90;i>0;i--){  
            myServo.write(i);
            delay(30);
            test = 1;
            if(test == 1){
              moistiure_check();
              test=0;
              }
              // ir_check();
            // digitalWrite(motor, LOW);
          }
        }
        else{
          if(data=='K'){
            test2=0;
            if(test2==0){
              fire_check();
              test2=1;
            }
            
            // ir_check();
          }
          else{
            if(data=='B'){
              digitalWrite(La, LOW);
              digitalWrite(Ra, LOW);
              digitalWrite(Rb, HIGH);
              digitalWrite(Lb, HIGH);
              ir_check();
            }
            
             
              else{
                if(data=='C'){
                  digitalWrite(motor, HIGH);
                  delay(20);
                if(digitalRead(flame)==LOW){
                  test3=0;
            if(test3==0){
              fire_check();
              test3=1;
            }
                }
                }
                
                else{
                  if(data=='S'){
                  // test5=1;
                  ir_check();
                }
                  else{
                digitalWrite(Ra, LOW);
                digitalWrite(La, LOW);
                digitalWrite(Lb, LOW);
                digitalWrite(Rb, LOW);
                digitalWrite(motor, LOW);
                digitalWrite(red, LOW);
                test5=0;
                }}
                // ir_check();
              }
          }
          }            
            }
          }
        }
      }
    }
  // }
  // else{
  //   for(int i=90;i>0;i--){  
  //   myServo.write(i);
  // }
  // }
}


int moistiure_check(){
  while(ms_data>=600){
    digitalWrite(motor,HIGH);
    for(int i=0;i<=90;i++){  
            myServo1.write(i); 
            delay(30);}
    for(int i=90;i>=0;i--){  
            myServo1.write(i); 
            delay(30);}
    ms_data = analogRead(ms);
    if(ms_data<=600){
      break;
    }
  }
}

int ir_check(){
  if(digitalRead(IR)==LOW){
    while(1){
    digitalWrite(Rb, LOW);
    digitalWrite(Lb, LOW); 
    digitalWrite(La, LOW);
    digitalWrite(Ra, LOW); 
    digitalWrite(red, HIGH);
    test5=0;
      if(digitalRead(IR)==HIGH){
        return test5=1;
        break;
      }
    }
  }
}

int flame_check(){
  if(digitalRead(flame)==LOW){
    while(1){
      fire_check();
      if(digitalRead(flame)==HIGH){
        break;
      }
    }
  }
}

int fire_check(){
  while(1){
            digitalWrite(motor, HIGH); 
            for(int i=0;i<=90;i++){  
            myServo1.write(i); 
            delay(30);}
            for(int i=90;i>=0;i--){  
            myServo1.write(i); 
            delay(30);
            }
            if(digitalRead(flame)==HIGH){
              break;
            }
            }
}

// int calculateDistance(){ 
//   digitalWrite(trigPin, LOW); 
//   delayMicroseconds(2);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(trigPin, HIGH); 
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
//   distance= duration*0.034/2;
//   return distance;
// }