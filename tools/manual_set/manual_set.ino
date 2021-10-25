#define RLED 9
#define GLED 10
#define BLED 11
#define WLED 6

#define DVORAK_CMD
#ifdef DVORAK_CMD
#define R_UP 'G'
#define R_DN 'H'
#define G_UP 'C'
#define G_DN 'T'
#define B_UP 'R'
#define B_DN 'N'
#define W_UP 'F'
#define W_DN 'D'
#else
#define R_UP 'U'
#define R_DN 'J'
#define G_UP 'I'
#define G_DN 'K'
#define B_UP 'O'
#define B_DN 'L'
#define W_UP 'Y'
#define W_DN 'H'
#endif

#define ITER 5

struct {
        short r;
        short g;
        short b;
        short w;
} ledColour;

inline void printCol() {
        char str[100];
        sprintf(str, "r: %d, g: %d, b: %d, w: %d\n\r", ledColour.r, ledColour.g, ledColour.b, ledColour.w);
        Serial.print(str);
}

void setup() {
        Serial.begin(9600);
        pinMode(RLED, OUTPUT);
        pinMode(GLED, OUTPUT);
        pinMode(BLED, OUTPUT);

        ledColour.r = 0;
        ledColour.g = 0;
        ledColour.b = 0;
        ledColour.w = 0;
}

void loop() {
        if (Serial.available()) {
                char in = Serial.read();
                switch(in) {
                case R_UP:
                        if (ledColour.r + ITER <= 255) ledColour.r += ITER;
                        break;
                case G_UP:
                        if (ledColour.g + ITER <= 255) ledColour.g += ITER;
                        break;
                case B_UP:
                        if (ledColour.b + ITER <= 255) ledColour.b += ITER;
                        break;
                case W_UP:
                        if (ledColour.w + ITER <= 255) ledColour.w += ITER;
                        break;
                case R_DN:
                        if (ledColour.r - ITER >= 0) ledColour.r -= ITER;
                        break;
                case G_DN:
                        if (ledColour.g - ITER >= 0) ledColour.g -= ITER;
                        break;
                case B_DN:
                        if (ledColour.b - ITER >= 0) ledColour.b -= ITER;
                        break;
                case W_DN:
                        if (ledColour.w - ITER >= 0) ledColour.w -= ITER;
                        break;
                default:
                        break;
                }
                printCol();
        }
        analogWrite(RLED, ledColour.r);
        analogWrite(GLED, ledColour.g);
        analogWrite(BLED, ledColour.b);
        analogWrite(WLED, ledColour.w);
}



                        
