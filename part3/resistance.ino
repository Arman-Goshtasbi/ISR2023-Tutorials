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

 #define RUBBER_SENSOR (A0)   //Defining the input pins for the sensors

  const float res_offset = 330;
  const float res_gain = 337590;


 
 
 
void setup() {

  

    
  Serial.begin(115200);             // Starting Serial communication with computer baudrate 115200 bps

  pinMode(RUBBER_SENSOR, INPUT);    // Defining sensor inputs for ADC (Analog digital converter)

}
 


void loop() {

  
 
    // Start Edit
    //float test = analogRead(RUBBER_SENSOR);
    float resistive_sensorValue = (res_gain/analogRead(RUBBER_SENSOR))-res_offset;    
    Serial.print(resistive_sensorValue);    

  

    Serial.print(",");

    
    Serial.println(0);

  // Delay 5ms to keep 100 Hz sampling rate between bend and stretch, Do not increase rate past 500 Hz.
    delay(500);
}


/* Function parses received characters from the COM port for commands */
