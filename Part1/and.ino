// And, Or, Nand, Xor
// Serial input: 00, 01, 10, 11
// And https://www.tinkercad.com/things/4Ggw7kltjnw-and-gate?sharecode=ILP4fLBGpug0d_gXlIQcTE2rO6C_2SqIt15GT9omTKY
// Or https://www.tinkercad.com/things/4CzvIPLXybS-or-gate?sharecode=g5mlyS2ecJivW67Su8YYe5ib9DWMpTzM6aShnnO6KfM
// Nand https://www.tinkercad.com/things/gCuinGkQDVQ-nand?sharecode=z2y_B3_GSfmQFUAv9Tb5FZ9O6Vp3E-U6akISbYWVqV8
// Xor https://www.tinkercad.com/things/kzP8M8I8ucS-xor?sharecode=39B-nbLnSKt8sMUUD6GshVDaHpp1zk9vdKorpzSHgZc

const int in1 = 2;
const int in2 = 3;
const int out1 = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(out1, INPUT);
}

void loop()
{
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
  
  	int bit1 = input[0] - '0';
  	int bit2 = input[1] - '0';
  
  	digitalWrite(in1, bit1);
  	digitalWrite(in2, bit2);
  
  	Serial.print("Pin2: ");
  	Serial.print(bit1);
  	Serial.print("\t\tPin3: ");
  	Serial.print(bit2);
    
    int state = digitalRead(out1);
  
  	Serial.print("\t\tPin4: ");
  	Serial.print(state);
  	Serial.print("\n");
  }
}