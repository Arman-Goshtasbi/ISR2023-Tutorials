/* 
 *  Soft Robotics Course
 *  Tutorial 1
 *  Part 2
 *  TAs: Aida Parvaresh, Jonathan Tirado, Arman Goshtasbi
 *  
 *  
 *  For better practice, this given code is just the pseudo code 
 *  Please try to follow the comments and write the required part
 *  
 *  
 *  If you are facing challenge in coding, Just ask the TAs.
 */




#include "Arduino.h" // Including libraries for microcontroller

#define PRESSURE_SENSOR (A1)   //Defining the input pins for the sensors


// Start editing the code here


    //MPX5100 Conversion equation  Vout=Vs(P * 0.009 + 0.04),  Vs=5V = 1023,  P = 
    // Define the offset and gains based on the equation above
    const float pressure_offset = 4.44;
    const float pressure_gain = 0.1086;


// Finish ending the code here 





void setup() {

  
  Serial.begin(115200);             // Starting Serial communication with computer baudrate 115200 bps
  pinMode(PRESSURE_SENSOR, INPUT);



}
 
void loop() {

    float pressure_sensorValue = (analogRead(PRESSURE_SENSOR)*pressure_gain-pressure_offset);    
    Serial.println(pressure_sensorValue);    // pressure data in kpa
    //Serial.print(",");

    
    //Serial.println(0);
    delay(500);
}
