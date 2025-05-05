// 2bit Full Adder
// https://www.tinkercad.com/things/8QgbeXrIaKe-2bit-full-adder?sharecode=QaQMzCHVt59Uk4qf-Qwo1iv3-SACrxu9BEW-CUPpe5A

const int bits = 2;

int outA[] = {2, 3};
int outB[] = {6, 7};
int inSum[] = {10, 11};
int inCarry = A0;

void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; i < bits; i++) {
  	pinMode(outA[i], OUTPUT);
    pinMode(outB[i], OUTPUT);
    pinMode(inSum[i], INPUT);
  }
  pinMode(inCarry, INPUT);
}

void loop()
{
  int sum[bits];
  int carry;
  
  for (int i = 0; i < (1 << bits); i++) {
    for (int j = 0; j < (1 << bits); j++) {
      
      for (int k = 0; k < bits; k++) {
      	int x = (i >> k) & 1;
        Serial.print(x);
        digitalWrite(outA[k], x);
      }
      
      Serial.print("\t");
      
      for (int k = 0; k < bits; k++) {
      	int y = (j >> k) & 1;
        Serial.print(y);
        digitalWrite(outB[k], y);
      }
      
      delayMicroseconds(10);  // 안정화 대기

      Serial.print("\t");
      
      for (int k = 0; k < bits; k++) {
      	sum[k] = digitalRead(inSum[k]);
        Serial.print(sum[k]);
      }
      
      Serial.print("\t");
      carry = digitalRead(inCarry);
      Serial.print(carry);
      
      Serial.println();
    }
  }
  
  Serial.print("===");
  Serial.println();
}