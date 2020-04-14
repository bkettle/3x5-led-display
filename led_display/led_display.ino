#include <string.h>

// int led_pins[] = {0, 1, 2, 3, 4,  |||  5, 6, 7, 8, 9, ||| 10, 14, 15, 16, 18};
int led_pins[] = {0, 5, 10, 1, 6, 14, 2, 7, 15, 3, 8, 16, 4, 9, 18};

bool space[15] = {0};

bool A[15] = {0, 1, 0,
              1, 0, 1,
              1, 0, 1,
              1, 1, 1,
              1, 0, 1};

bool B[15] = {1, 1, 0,
              1, 0, 1,
              1, 1, 0,
              1, 0, 1,
              1, 1, 0};

bool C[15] = {0, 1, 1,
              1, 0, 0,
              1, 0, 0,
              1, 0, 0,
              0, 1, 1};

bool D[15] = {1, 1, 0,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              1, 1, 0};

bool E[15] = {1, 1, 1,
              1, 0, 0,
              1, 1, 1,
              1, 0, 0,
              1, 1, 1};

bool F[15] = {1, 1, 1,
              1, 0, 0,
              1, 1, 1,
              1, 0, 0,
              1, 0, 0};

bool G[15] = {0, 1, 1,
              1, 0, 0,
              1, 1, 0,
              1, 0, 1,
              0, 1, 1};

bool H[15] = {1, 0, 1,
              1, 0, 1,
              1, 1, 1,
              1, 0, 1,
              1, 0, 1};

bool I[15] = {1, 1, 1,
              0, 1, 0,
              0, 1, 0,
              0, 1, 0,
              1, 1, 1};

bool J[15] = {1, 1, 1,
              0, 1, 0,
              0, 1, 0,
              1, 1, 0,
              1, 1, 0};

bool K[15] = {1, 0, 1,
              1, 0, 1,
              1, 1, 0,
              1, 0, 1,
              1, 0, 1};

bool L[15] = {1, 0, 0,
              1, 0, 0,
              1, 0, 0,
              1, 0, 0,
              1, 1, 1};

bool M[15] = {1, 0, 1,
              1, 1, 1,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1};

bool N[15] = {1, 0, 0,
              1, 1, 1,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1};

bool O[15] = {0, 1, 0,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              0, 1, 0};

bool P[15] = {1, 1, 0,
              1, 0, 1,
              1, 1, 0,
              1, 0, 0,
              1, 0, 0};

bool Q[15] = {0, 1, 1,
              1, 0, 1,
              0, 1, 1,
              0, 0, 1,
              0, 0, 1};

bool R[15] = {1, 1, 0,
              1, 0, 1,
              1, 1, 0,
              1, 1, 0,
              1, 0, 1};

bool S[15] = {0, 1, 1,
              1, 0, 0,
              0, 1, 0,
              0, 0, 1,
              1, 1, 0};

bool T[15] = {1, 1, 1,
              0, 1, 0,
              0, 1, 0,
              0, 1, 0,
              0, 1, 0};

bool U[15] = {1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              1, 1, 1};

bool V[15] = {1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              0, 1, 0,
              0, 1, 0};  

bool W[15] = {1, 0, 1,
              1, 0, 1,
              1, 0, 1,
              1, 1, 1,
              1, 0, 1};

bool X[15] = {1, 0, 1,
              1, 0, 1,
              0, 1, 0,
              1, 0, 1,
              1, 0, 1};

bool Y[15] = {1, 0, 1,
              1, 0, 1,
              0, 1, 0,
              0, 1, 0,
              0, 1, 0};

bool Z[15] = {1, 1, 1,
              0, 0, 1,
              0, 1, 0,
              1, 0, 0,
              1, 1, 1};

bool excl[15] = {0, 1, 0,
              0, 1, 0,
              0, 1, 0,
              0, 0, 0,
              0, 1, 0};

// this ascii table starts at 32
bool* ascii[100] = {space, excl, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, 
                    P, Q, R, S, T, U, V, W, X, Y, Z};

int str_state = 0;
unsigned long str_timer = 0;
int curr_str_ptr = 0;

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
  writeString("HAPPY BIRTHDAY DAISY!",400);
  delay(1000);
}

void writeString(char* str, int delay_time) {
  /* given a char array starting at ptr
   * and a delay in milliseconds, blinks
   * out the pattern using writeChar
   */
//  for (int i=0; i<strlen(str); i++) {
//    writeChar(str[i]);
//    delay(delay_time);
//    clearLEDs();
//    delay(20);
//  }
  if (millis() - str_timer > delay_time) {
    clearLEDs();
    delay(20);
    str_timer = millis();
    writeChar(str[i]);
    curr_str_ptr += 1;
    curr_str_ptr %= strlen(str);
  }
}

void writeChar(char ch) {
  /* given a character, looks it up
   *  in the 'ascii' array and calls
   *  writeArray on the pointer there
   */
  bool* arr = ascii[((int) ch) - 32];
  Serial.print("writing char "); Serial.print(ch); Serial.print(" index "); Serial.println(((int) ch) - 32);
  writeArray(arr);
}

void writeArray(bool* arr) {
  /* given a pointer to an array of 15 bools,
   *  will write each one to the array of leds
   *  in the order given by led_pins 
   */
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
