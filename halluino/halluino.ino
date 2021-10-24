#include "helpers.h"
// Available helpers
// fadeTo
// changeTo
// increaseBy

void userFunction1() {
  // put your code here
  fire();

}

void userFunction2() {
  // put your code here
  // Hex value: #800080
  changeTo(0x80, 0x00, 0x80, 0x00);
  delay(500);
  // Hex value: #FFA500
  changeTo(0xFF, 0xA5, 0x00, 0x00);
  delay(500);
}

void userFunction3() {
  // put your code here

}

void loop() {
  for (int i = 0; i < 100; i++) {
    userFunction1();
  }

  for (int i = 0; i < 100; i++) {
    userFunction2();
  }

  for (int i = 0; i < 100; i++) {
    userFunction3();
  }
}

void setup() {
  initialise();
}

void fire() {
  // Get a random number for intensity of fire
  int brightness = random(120);

  // Randomly-picked values with a bias for red and orange (red and green)
  int newRed = brightness + 135;
  int newGreen = brightness / 4;
  int newBlue = brightness / 32;

  // Use the helper function
  //     red     green     blue     white
  fadeTo(newRed, newGreen, newBlue, 0);
  delay(random(100) + 100);
}
