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



// Finish ending the code here 





void setup() {

  
  Serial.begin(115200);             // Starting Serial communication with computer baudrate 115200 bps
  pinMode(PRESSURE_SENSOR, INPUT);




 
void loop() {

// start editing here

    float vout = analogRead(PRESSURE_SENSOR)*5/1023;
    float pressure_sensorValue = (vout-0.02)/0.045;
// End editing here
    
    Serial.print(pressure_sensorValue);    // pressure data in kpa

  // Delay 5ms to keep 100 Hz sampling rate between bend and stretch, Do not increase rate past 500 Hz.
  delay(5);
}
