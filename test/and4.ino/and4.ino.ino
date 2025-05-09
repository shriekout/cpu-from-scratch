// 74Hc08 - AND Gate

const int bits = 4;
const int outA[] = {2, 3, 4, 5};
const int outB[] = {6, 7, 8, 9};
const int inR[] = {10, 11, 12, 13};

String inputLine = "";
String binStr[2];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < bits; i++) {
    pinMode(outA[i], OUTPUT);
    pinMode(outB[i], OUTPUT);
    pinMode(inR[i], INPUT);
  }
}

void loop() {
  if (Serial.available()) {
    inputLine = Serial.readStringUntil('\n');
    inputLine.trim();  // 앞뒤 공백 제거

    int spaceIndex = inputLine.indexOf(' ');

    if (spaceIndex != -1) {
      binStr[0] = inputLine.substring(0, spaceIndex);
      binStr[1] = inputLine.substring(spaceIndex + 1);
      
      for (int i = 0; i < bits; i++) {
        digitalWrite(outA[i], binStr[0][i] - '0');
        digitalWrite(outB[i], binStr[1][i] - '0');
      }

      delay(10);

      for (int i = 0; i < bits; i++) {
        int state = digitalRead(inR[i]);
        Serial.print(state);
      }

      Serial.println();
    }
  }
}
