void setup() {
        pinMode(9, OUTPUT);
}

void loop() {
        int testpins[] = {6, 9, 10, 11};
        for (int i = 0; i < 4; i++) {
                for (int x = 0; x < 255; x += 5) {
                        analogWrite(testpins[i], x);
                        delay(50);
                }
                analogWrite(testpins[i], 0);
        }
        delay(500);
}
