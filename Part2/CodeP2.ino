/* 
 *  Reading the one axis soft flex sensor from Bend Labs in polled mode
 *  By: Colton Ottley @ Bend Labs
 *  Date: June 18th, 2019
 *  
 *  This sktech configures the one axis soft flex sensor from Bendlabs
 *  to simultaneously supply bend (angular displacement) and stretch
 *  (linear displacement) data via a polling setup.
 *  
 *  When reading data from the sensor in polled mode, instead of interrupt mode,
 *  each sample read triggers the sensor to take another sample and go back to 
 *  sleep. This results in a one sample interval delay between the sampling of
 *  the sensor position and the data that is read out. 
 *  
 *  Minimum sample interval is 2ms (500 Hz sample rate)
 *  
 *  Sensor is not 5V tolerant use only with 3.3V boards
 *  
 *  Refer to one_axis_quick_start_guide.pdf for wiring instructions
 */


// Iclude libraries for bend sensor and microcontroller

#include "Arduino.h"


//Define the input pins for the sensors

         // Bendlabs sensor.  

#define RUBBER_SENSOR (A0)               //  Adafruit Rubber Cord Sensor analog input
#define PRESSURE_SENSOR (A1)             //  MPX5100 Series Integrated Silicon Pressure Sensor analog input (0 to 100 kPa)







//Pressure sensor calibration factors  MPX5100 Series Integrated Silicon Pressure Sensor analog input (0 to 100 kPa)  Vout=Vs(P * 0.009 + 0.04),  Vs=5V = 1024,  P = 
 
const float SensorOffset = 4.44;  //pressure sensor offset
const float SensorGain = 113.77;   // pressure sensor proportional relation 0.109

//Resistor sensor calibration factors  
const float SensorOffset2 = 330;  //resistance offset
const float SensorGain2 = 337590;   // resistance gain


void setup() {

  
/*
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

 */
    
  Serial.begin(115200);             // Starting Serial communication with computer baudrate 115200 bps

  pinMode(RUBBER_SENSOR, INPUT);    // Defining sensor inputs for ADC (Analog digital converter)
  pinMode(PRESSURE_SENSOR, INPUT);  // Defining sensor inputs for ADC (Analog digital converter)


}

void loop() {

  
  //Defining varialbes for bendlabs sensor data processing


  // Read data from the one axis ads sensor


    // read the input on analog pin 0:
    float pressure_sensorValue = (analogRead(PRESSURE_SENSOR)*SensorGain-SensorOffset); //Do maths for calibration

    // read the input on analog pin 1:
    float resistance_sensorValue = (SensorGain2/analogRead(RUBBER_SENSOR)-SensorOffset2); //Do maths for calibration

    //

    Serial.print(",");
    Serial.print(pressure_sensorValue);    // pressure data in kpa
    Serial.print(",");
    Serial.println(0);
    Serial.println(resistance_sensorValue);  // Stretch data
    
  
  // Check for received hot keys on the com port


  // Delay 5ms to keep 100 Hz sampling rate between bend and stretch, Do not increase rate past 500 Hz.
  delay(5);
}



/* 
 *  If the current sample is less that 0.5 degrees different from the previous sample
 *  the function returns the previous sample. Removes jitter from the signal. 
 */
