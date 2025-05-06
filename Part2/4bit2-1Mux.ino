// 4bit 2:1 Mux
// https://app.cirkitdesigner.com/project/1668be76-a935-4829-b215-81bfc842d9cc

const int inA[] = {2, 3, 4, 5};
const int inB[] = {6, 7, 8, 9};
const int sel = 10;
const int notEnable = 11;

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(inA[i], OUTPUT);
        pinMode(inB[i], OUTPUT);
    }

    pinMode(sel, OUTPUT);
    pinMode(notEnable, OUTPUT);

    digitalWrite(notEnable, LOW);
}

void loop() {
    int a[] = {1, 0, 1, 0};
    int b[] = {0, 1, 0, 1};

    for (int s = 0; s < 2; s++) {
        digitalWrite(sel, s);

        for (int i = 0; i < 4; i++) {
            digitalWrite(inA[i], a[i]);
            digitalWrite(inB[i], b[i]);
        }

        delay(1000);
    }

}