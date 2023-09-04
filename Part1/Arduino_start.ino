#include <math.h>

/*
 * some frequency f has a period of 1/f seconds.
 * 
 * 2*pi*f radians/second at frequency f
 * At 1Hz, there are 2*pi radians in one second
 * At 1kHz, 2*pi*1000 radians/second.
 * 
 * Divide by 2*pi*f by 1000 to find radians/millisecond, or
 * divide by 10e6 for radians/microsecond
 * Calculate number of milliseconds elapsed between calls,
 * multiply by required 2*pi*f/1000 to get the delta(angle)
 * and add to previous angle.
 * calculate sin/cos/tan for the current angle
 * 
 * 
 */

// Only adjust the frequency! 
const double frequency = 1; // 1Hz
 
long milliSeconds;
long previousMilliSeconds;
long elapsed;
double angle;
double previousAngle;
double radiansPerMillisecond;
double pi = M_PI;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {;} // waiting for arduino to open the com port
 
  // radians per millisecond is a constant for a given frequency,
  // so we only need to calculate it once to save processor time
  radiansPerMillisecond = radiansPerMilliSecond(frequency);

  // set up the delta(t) and delta(angle) values
  angle = 0;
  previousAngle = 0;
   milliSeconds = millis();
  previousMilliSeconds = milliSeconds;

  Serial.print("Signal_1");
  Serial.print(',');
  Serial.println("Signal_2");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  milliSeconds = millis();
  elapsed = milliSeconds - previousMilliSeconds;
  previousMilliSeconds = milliSeconds;
  angle = previousAngle + deltaRadians(elapsed, radiansPerMillisecond);
  previousAngle = angle;
  

  Serial.print(3*sin(4*angle));
  Serial.print(',');
  Serial.println(2*sin(2*angle));
  delay(10);


}

// functions

double radiansPerMilliSecond(double frequency) {

  return (double) 2.0*pi*frequency/1000;

}

double deltaRadians(long elapsed, double radiansPerMs) {
  return radiansPerMs * elapsed;
}
