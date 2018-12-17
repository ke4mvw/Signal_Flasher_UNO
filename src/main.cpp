#include <Arduino.h>
int ledstate = 0b00100000; // initial state with bit 5 high;
int delay1 = 500; //first delay - usually the same as second delay
int delay2 = 500; //second delay - usually the same as first delay

void setup() {
  DDRB |= 0b00110000; // set bits 5 and 4 as outputs
}

void loop() {
  delay(delay1);
  ledstate &= 0b11001111; // BITWISE AND - change bit 5 and 4 to 0 - leave
                          // others unchanged
  PORTB =
      (ledstate |= 0b00100000); // BITWISE OR - change bit 5 to 1 - leave others unchanged
  delay(delay2);
  ledstate &= 0b11001111; // BITWISE AND - change bit 5 and 4 to 0 - leave
                          // others unchanged
  PORTB =
      (ledstate |= 0b00010000); // BITWISE OR - change bit 4 to 1 - leave others unchanged
}
