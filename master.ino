#include <SmartInventor.h> 
 
int baseLevelLeft;
int baseLevelCenter;
int baseLevelRight; 

void setup() {  
    SmartInventor.DCMotorUse();  
 
    baseLevelLeft = analogRead(21) - 50;  
    baseLevelCenter = analogRead(20) - 50;  
    baseLevelRight = analogRead(19) - 50;   
    
    pinMode(11, OUTPUT);  
    pinMode(12, OUTPUT);  
    pinMode(14, OUTPUT);  
    pinMode(15, OUTPUT);  
    pinMode(17, OUTPUT);  
    pinMode(18, OUTPUT);
} 

void loop() {  
    // check sensors  
    int leftSensor = analogRead(21);  
    int centerSensor = analogRead(20);  
    int rightSensor = analogRead(19);
       
    //if right, turn right  
    if(rightSensor < baseLevelRight)  
    {    
        // Right LEDs on    
        digitalWrite(11, HIGH);    
        digitalWrite(12, HIGH);
             
        //move right    
        SmartInventor.DCMotor(M1, CW, 100);    
        delay(6);    
        SmartInventor.DCMotor(M1, STOP, 0);    
        delay(2);  
           
        // Right LEDs off    
        digitalWrite(11, LOW);    
        digitalWrite(12, LOW);  
    }  
    
    // if left, turn left  
    else if(leftSensor < baseLevelLeft)  
    {    
        // left LEDs on    
        digitalWrite(17, HIGH);    
        digitalWrite(18, HIGH);  
           
        // move left    
        SmartInventor.DCMotor(M1, CCW, 100);    
        delay(6);    
        SmartInventor.DCMotor(M1, STOP, 0);    
        delay(2);    
         
        // left LEDs off    
        digitalWrite(17, LOW);    
        digitalWrite(18, LOW);  
    }  
    
    // if center, shoot  
    else if(centerSensor < baseLevelCenter)  
    {    
        // center LEDs on    
        digitalWrite(14, HIGH);    
        digitalWrite(15, HIGH);   
          
        // shoot    
        SmartInventor.DCMotor(M2, CW, 100);    
        delay(300);    
        SmartInventor.DCMotor(M2, STOP, 0);    
        delay(100);    
         
        // center LEDs off    
        digitalWrite(14, LOW);    
        digitalWrite(15, LOW);  
    } 
}
