/* Interface Accelerometer with NodeMCU
 * By TheCircuit
 */

const int yPin = A0;    //y-axis of the Accelerometer 

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

}

void loop() {
  
  int y = analogRead(yPin);
  delay(100);

  Serial.print("Y-axis : ");
  Serial.println(y);

}
