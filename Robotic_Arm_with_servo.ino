#include <Servo.h>
Servo Bservo;            // base servo 
Servo Aservo;            // arm servo 
Servo Wservo;            // wrist servo
int servoBpin = 8;       // base servo pin
int servoApin = 9;       // arm servo pin 
int servoWpin = 10;      // wrist servo pin 
int base=90;
int wrist=90;
int arm=90;
int Xval ;
int Yval;
int axleX = A0;
int axleY = A1;
int axleZ = A2;
int basepin = 2;
int wristpin = 3;
int baseON = 1;
int wristON = 0;


void setup()
{
  Bservo.attach(servoBpin);
  Aservo.attach(servoApin);
  Wservo.attach(servoWpin);
  pinMode(basepin,INPUT);
  pinMode(wristpin,INPUT);Serial.begin(9600);
  
}

void loop()
{
   Xval = analogRead(axleX);                  // reads x value 
   Yval = analogRead(axleY);                  // reads y value
   int baseValue= digitalRead(basepin);
   int wristValue = digitalRead(wristpin);
 //Serial.println(baseValue);

  Xval = map(Xval,0,1023,0,180); //  maps the value 0 to 180
  Yval = map(Yval,0,1023,0,180); // maps the value 0 to 180

//Serial.println(Xval);
//Serial.println(Yval);

                                          
                         // decide which part has to move arm or wrist                       
  if (baseValue == 0){  // arm will move     
    baseON=1;
    wristON=0;
  }

  if (wristValue == 0){  // wrist will move
    baseON=0;
    wristON=1;
  }
    if (Yval > 100 && arm<151){
      
      arm=arm+10;
      
    }
   if (Yval<70){
      
      arm=arm-10;
      
    }

  


  if (baseON == 1){                                 //ARM opertaion
    if (Xval > 100 ){                               // base operation 
    base=base+10;
  }
 if (Xval<70  ){
    base=base-10;
  }
 }

if (wristON == 1){                               // WRIST operation
    if (Xval > 100&& wrist<91  ){
     
      wrist=wrist+10;
      
    }
     if (Xval<70){
      
      wrist=wrist-10;
      
    }
 }  

Serial.println(arm);
  Bservo.write(base);
  Aservo.write(arm);
  Wservo.write(wrist);
  

  delay(1000);
  
}
