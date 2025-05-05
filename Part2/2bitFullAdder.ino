// 2bit Full Adder
// https://www.tinkercad.com/things/8QgbeXrIaKe-2bit-full-adder?sharecode=QaQMzCHVt59Uk4qf-Qwo1iv3-SACrxu9BEW-CUPpe5A

const int bits = 2;

int outA[] = {2, 3};
int outB[] = {6, 7};
int inSum[] = {10, 11};
int inCarry = A0;

void printResult(int *val);

void setup()
{
  int x[bits], y[bits];
  int sum[bits];
  int carry;
  
  Serial.begin(9600);
  
  for (int i = 0; i < bits; i++) {
  	pinMode(outA[i], OUTPUT);
    pinMode(outB[i], OUTPUT);
    pinMode(inSum[i], INPUT);
  }
  pinMode(inCarry, INPUT);
  
  for (int i = 0; i < (1 << bits); i++) {
    for (int j = 0; j < (1 << bits); j++) {
      
      for (int k = 0; k < bits; k++) {
      	x[k] = (i >> k) & 1;
        digitalWrite(outA[k], x[k]);
      }
      
      for (int k = 0; k < bits; k++) {
      	y[k] = (j >> k) & 1;
        digitalWrite(outB[k], y[k]);
      }
      
      delay(1);  // 안정화 대기
      
      for (int k = 0; k < bits; k++) {
      	sum[k] = digitalRead(inSum[k]);
      }
      
      carry = digitalRead(inCarry);
      
      // 결과 출력
      Serial.print("A=");
      printResult(x);
      Serial.print(" B=");
      printResult(y);
      Serial.print(" | Sum=");
      printResult(sum);
      Serial.print(" Carry=");
      Serial.println(carry);
    }
  }
}

void loop()
{
}

void printResult(int *val)
{
  for (int i = bits-1; i >= 0; i--)
    Serial.print(*(val+i));
}