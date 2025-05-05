// 1bit Full Adder
// https://www.tinkercad.com/things/bvAJWsbxQQl-1bit-full-adder?sharecode=syOgQGtUoE2v-EYeFxNevbP1ViOYaDICMG4hNtATkrI

void setup()
{
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, INPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Serial.print(i);
      Serial.print(j);
      digitalWrite(2, i);
      digitalWrite(6, j);
      
      int sum = digitalRead(10);
      Serial.print("\t");
      Serial.print(sum);
      
      int carry = digitalRead(A0);
      Serial.print("\t");
      Serial.print(carry);
      Serial.print("\n");
    }
  }
  
  Serial.print("===========\n");
  
  delay(1000);
}