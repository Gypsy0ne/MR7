const int Dry = 620, Wet = 255;
 
void setup() {
 Serial.begin(9600);
}
 
void loop() {
  int sensorRead=analogRead(A0);
  float sensorReadV=(sensorRead/1023.0)*5.0;
  int moisturePerc=map(sensorRead, Dry, Wet, 0, 100);
    Serial.print(moisturePerc);
    Serial.print("% (");
    Serial.print(sensorReadV);
    Serial.println("V)");
  delay(1000);
}
