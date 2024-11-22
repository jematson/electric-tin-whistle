/*
  Electric Tin Whistle Code
  by Jenae Matson
  Description: Code for an electric tin whistle instrument using an Arduino Nano.
*/

// Assign frequency values to musical notes
typedef enum {
  D = 294,
  E = 330,
  F = 370,
  G = 392, 
  A = 440,
  B = 494,
  C = 523,
  c = 554,
  d = 587,
  e = 659,
  f = 740,
  g = 784,
  a = 880,
  b = 988
} notes;

// Define lower pressure values for low/high octaves
const int low_threshold = 10500;
const int mid_threshold = 11000;

// Pin declarations
const int hole1 = 10;
const int hole2 = 7;
const int hole3 = 3;
const int hole4 = 9;
const int hole5 = 5;
const int hole6 = 11;
const int sound = 2;
const int clkOut = 12;
const int clkIn = 8;

// Initialize the pressure sensor value
unsigned long sensorValue = 0;

void setup() {
  Serial.begin(57600);
  Serial.println("Starting up...");
  pinMode(hole1, INPUT_PULLUP);
  pinMode(hole2, INPUT_PULLUP);
  pinMode(hole3, INPUT_PULLUP);
  pinMode(hole4, INPUT_PULLUP);
  pinMode(hole5, INPUT_PULLUP);
  pinMode(hole6, INPUT_PULLUP);
  pinMode(clkOut, INPUT_PULLUP);
  pinMode(clkIn, OUTPUT);
  pinMode(sound, OUTPUT);
  Serial.println("Setup done...");
}

void loop() {
  // Get the current pressure sensor input
  unsigned long currPressure = sensorToPressure();
  Serial.println(currPressure);

  // Check buttons and play corresponding notes
  if (currPressure > low_threshold && currPressure < mid_threshold) {   // only play notes if the play button is down
    //Serial.println("low octave");
    if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5) && check_pin(hole6)) { // D
      tone(sound, D);
    } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5)) {  // E
      tone(sound, E);
    } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4)) {  // F#
      tone(sound, F);
    } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3)) {  // G
      tone(sound, G);
    } else if (check_pin(hole1) && check_pin(hole2)) {  // A
      tone(sound, A);
    } else if (check_pin(hole1)) {  // B
      tone(sound, B);
    } else if (check_pin(hole2) && check_pin(hole3)) {  // C
      tone(sound, C);
    } else if (!check_pin(hole1) && !check_pin(hole2) && !check_pin(hole3) && !check_pin(hole4) && !check_pin(hole5) && !check_pin(hole6)) {  // c#
      tone(sound, c);
    } else {
      noTone(sound);
    }
  } else if(currPressure >= mid_threshold) {
    if (!check_pin(hole1) && !check_pin(hole2) && !check_pin(hole3) && !check_pin(hole4) && !check_pin(hole5) && !check_pin(hole6)) { // D
      tone(sound, c);
    } else if(check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5) && check_pin(hole6)) { // d
      tone(sound, d);
    } else if(check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5)) { // e
      tone(sound, e);
    } else if(check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4)) { // f#
      tone(sound, f);
    } else if(check_pin(hole1) && check_pin(hole2) && check_pin(hole3)) { // g
      tone(sound, g);
    } else if(check_pin(hole1) && check_pin(hole2)) { // a
      tone(sound, a);
    } else if(check_pin(hole1)) { // b
      tone(sound, b);
    } else {
      noTone(sound);
    }
  } else {
    noTone(sound);
  }
}

// Check if the given button is being pressed down
bool check_pin(const int pin) {
  if(!digitalRead(pin)){
    return true;
  } else {
    return false;
  }
}

// Pulse one 
void pulse() {
  digitalWrite(clkIn, LOW);
  digitalWrite(clkIn, HIGH);
  digitalWrite(clkIn, LOW);
}

// Get the current pressure sensor reading
unsigned long sensorToPressure() {
  sensorValue = 0; // clear sensor data
  while(!(digitalRead(clkOut) == LOW)); // wait for out to be low, data ready
  for (int i = 0; i < 24; i++) {
    pulse();
    sensorValue <<= 1; // shift left by 1 bit
    if(digitalRead(clkOut)) {
      sensorValue |= 1;
    }
  }
  pulse();
  //sensorValue -= 886000;
  //sensorValue = (sensorValue * 100) / 40000;
  sensorValue /= 100;
  return sensorValue;
}

// System Testing

// Check buttons
/*
  if (check_pin(hole1)) {
    Serial.println("hole1");
  } else if (check_pin(hole2)) {
    Serial.println("hole2");
  } else if (check_pin(hole3)) {
    Serial.println("hole3");
  } else if (check_pin(hole4)) {
    Serial.println("hole4");
  } else if (check_pin(hole5)) {
    Serial.println("hole5");
  } else if (check_pin(hole6)) {
    Serial.println("hole6");
  }
*/

// Check a single octave
/*
  if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5) && check_pin(hole6)) { // D
    tone(sound, D);
    Serial.println("D");
  } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4) && check_pin(hole5)) {  // E
    tone(sound, E);
    Serial.println("E");
  } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3) && check_pin(hole4)) {  // F#
    tone(sound, F);
    Serial.println("F");
  } else if (check_pin(hole1) && check_pin(hole2) && check_pin(hole3)) {  // G
    tone(sound, G);
    Serial.println("G");
  } else if (check_pin(hole1) && check_pin(hole2)) {  // A
    tone(sound, A);
    Serial.println("A");
  } else if (check_pin(hole1)) {  // B
    tone(sound, B);
    Serial.println("B");
  } else if (check_pin(hole2) && check_pin(hole3)) {  // C
    tone(sound, C);
    Serial.println("C");
  } else if (!check_pin(hole1) && !check_pin(hole2) && !check_pin(hole3) && !check_pin(hole4) && !check_pin(hole5) && !check_pin(hole6)) {  // c#
    //tone(sound, c);
  } else {
    noTone(sound);
  }
*/
