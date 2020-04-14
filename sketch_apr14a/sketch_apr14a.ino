// int led_pins[] = {0, 1, 2, 3, 4,  |||  5, 6, 7, 8, 9, ||| 10, 14, 15, 16, 18};
int led_pins[] = {0, 5, 10, 1, 6, 14, 2, 7, 15, 3, 8, 16, 4, 9, 18};

// this ascii table starts at 32
bool* ascii[100];

bool space[15] = {0};
ascii[0] = space;

bool A[15] = {0, 1, 0,
              1, 0, 1,
              1, 0, 1,
              1, 1, 1,
              1, 0, 1};
ascii[1] = A;

bool B[15] = {1, 1, 1,
              1, 0, 1,
              1, 1, 1,
              1, 0, 1,
              1, 1, 1};
ascii[2] = B;

bool C[15] = {0, 1, 1,
              1, 0, 0,
              1, 0, 0,
              1, 0, 0,
              0, 1, 1};
ascii[3] = C;

bool D[15] = {1, 1, 0,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              1, 1, 0};
ascii[4] = D;

bool E[15] = {1, 1, 1,
              1, 0, 0,
              1, 1, 1,
              1, 0, 0,
              1, 1, 1};
ascii[5] = E;

void setup() {
  // initialize all leds as outputs
  delay(1000);
  for (int i = 0; i<=15; i++) {
    Serial.print("setting index "); Serial.print(i);
    Serial.print(" with value "); Serial.println(led_pins[i]);
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  clearLEDs();
  writeArray(A);
  delay(500);
  clearLEDs();
}

void writeChar(char ch) {
  /* given a character, looks it up
   *  in the 'ascii' array and calls
   *  writeArray on the pointer there
   */
   arr = ascii[(int) ch - 32];
   writeArray();
}

void writeArray(bool* arr) {
  /* given a pointer to an array of 15 bools,
   *  will write each one to the array of leds
   *  in the order given by led_pins */
  for (int i = 0; i<15; i++) {
    digitalWrite(led_pins[i], arr[i]);
  }
}

void clearLEDs() {
  /* clears all leds */
  for (int i = 0; i<15; i++) {
    digitalWrite(led_pins[i], LOW);
  }
}
