/* 
 *  Soft Robotics Course
 *  Tutorial 1
 *  Part 3
 *  TAs: Aida Parvaresh, Jonathan Tirado, Arman Goshtasbi
 *  
 *  
 *  For better practice, this given code is just the pseudo code 
 *  Please try to follow the comments and write the required part
 *  
 *  
 *  If you are facing challenge in coding, Just ask the TAs.
 */



 #include "Arduino.h" 

 #define Wheatstone_1 (A0)   //Defining the input pins for the sensors
 #define Wheatstone_2 (A1)   //Defining the input pins for the sensors

 const float R1 = 330; 
 const float R2 = 330; // resistance value of R2
 const float R4 = 330; 
 float R_L = R1/(R1+R2);
 
 
void setup() {

  

    
  Serial.begin(115200);             // Starting Serial communication with computer baudrate 115200 bps

  pinMode(Wheatstone_1, INPUT);    // Defining sensor inputs for ADC (Analog digital converter)
  pinMode(Wheatstone_2, INPUT);    // Defining sensor inputs for ADC (Analog digital converter)

 

}

void loop() {

    float delta = analogRead(Wheatstone_2) - analogRead(Wheatstone_1);
    float alpha = 0.5-(delta/1023);
    float resistance_sensorValue = ((1-alpha)/alpha)*R4;
    
    

    Serial.print(resistance_sensorValue);    // Resistance data in Kilo ohm


  // Delay 5ms to keep 100 Hz sampling rate between bend and stretch, Do not increase rate past 500 Hz.
  delay(5);
}


/* Function parses received characters from the COM port for commands */
