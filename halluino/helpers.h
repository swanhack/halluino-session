#ifndef HELPERS_H
// RGBW strip pins
#define RGB_W 6
#define RGB_R 9
#define RGB_G 10
#define RGB_B 11

/// Strip state
struct strip_state {
  uint8_t rval;
  uint8_t gval;
  uint8_t bval;
  uint8_t wval;
};

// The current state of the strip.
struct strip_state active_state = {0x00, 0x00, 0x00, 0x00};

inline void get_iterator_array(const struct strip_state start, const struct strip_state end,
                               uint8_t *iterators) {
  for (int i = 0; i < 4; i++) {
    if (*(&start.rval + i) < * (&end.rval + i))
      iterators[i] = 1;
    else
      iterators[i] = -1;
  }
}

inline void applyState(const struct strip_state newState) {
  analogWrite(RGB_R, newState.rval);
  analogWrite(RGB_G, newState.gval);
  analogWrite(RGB_B, newState.bval);
  analogWrite(RGB_W, newState.wval);

  active_state.rval = newState.rval;
  active_state.gval = newState.gval;
  active_state.bval = newState.bval;
  active_state.wval = newState.wval;
}

void initialise() {
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(RGB_W, OUTPUT);
}

// Fade the strip to a specific state
void internal_fadeTo(const struct strip_state *state) {
  // What we iterate R, G, and B by
  uint8_t rgb_iterators[4];
  get_iterator_array(active_state, *state, &rgb_iterators[0]);

  int change_occurred = 1;
  while (change_occurred) {
    change_occurred = 0;
    if (active_state.rval != state->rval) {
      active_state.rval += rgb_iterators[0];
      change_occurred = 1;
    }

    if (active_state.gval != state->gval) {
      active_state.gval += rgb_iterators[1];
      change_occurred = 1;
    }

    if (active_state.bval != state->bval) {
      active_state.bval += rgb_iterators[2];
      change_occurred = 1;
    }

    if (active_state.wval != state->wval) {
      active_state.wval += rgb_iterators[3];
      change_occurred = 1;
    }

    analogWrite(RGB_R, active_state.rval);
    analogWrite(RGB_G, active_state.gval);
    analogWrite(RGB_B, active_state.bval);
    analogWrite(RGB_W, active_state.wval);
    delay(3);
  }

}

void changeTo(int r, int g, int b, int w) {
  const struct strip_state newState = {r, g, b, w};
  applyState(newState);
}

void increaseBy(int r, int g, int b, int w) {
  struct strip_state newState = active_state;
  newState.rval += r;
  newState.gval += g;
  newState.bval += b;
  newState.wval += w;
  applyState(newState);
}

void fadeTo(int r, int g, int b, int w) {
  const struct strip_state newState = {r, g, b, w};
  internal_fadeTo(&newState);
}
#endif
