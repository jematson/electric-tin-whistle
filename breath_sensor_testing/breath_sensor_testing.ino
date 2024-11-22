const int clkOut = 12; //4
const int clkIn = 11; //3

unsigned long sensorValue = 0;

void pulse() {
  digitalWrite(clkIn, LOW);
  digitalWrite(clkIn, HIGH);
  digitalWrite(clkIn, LOW);
}

bool outLow() {
  return digitalRead(clkOut) == LOW;
}

unsigned long readSensor() {
  sensorValue = 0; // clear sensor data
  while(!outLow()); // wait for out to be low, data ready
  for (int i = 0; i < 24; i++) {
    pulse();
    sensorValue <<= 1; // shift left by 1 bit
    if(digitalRead(clkOut)) {
      sensorValue |= 1;
    }
  }
  pulse();
  return sensorValue;
}

void setup() {
  Serial.begin(57600);
  pinMode(clkOut, INPUT_PULLUP);
  pinMode(clkIn, OUTPUT);
}

void loop() {
  unsigned long pressure = readSensor();
  //pressure -= 886000;
  //pressure = (pressure * 100) / 40000;
  pressure /= 1000;
  Serial.println(pressure);
  delay(100);
}


