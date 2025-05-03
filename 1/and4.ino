// And4 https://www.tinkercad.com/things/7b7DuoETWAA-and4?sharecode=jnwDAN2ErF6gV4C3c1Fq9xt522QPlyYc02CbWWyfqQQ
// 0000 0000 => 0000 & 0000

void setup()
{
  Serial.begin(9600);
  
  for (int i = 2; i <= 9; i++)
  	pinMode(i, OUTPUT);
  
  for (int i = 10; i <= 13; i++)
    pinMode(i, INPUT);
}

void loop()
{
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    int spaceIndex = input.indexOf(' ');
    String bin1 = input.substring(0, spaceIndex);
    String bin2 = input.substring(spaceIndex + 1);
    
    for (int i = 0; i < 4; i++) {
      digitalWrite(i+2, bin1[i] == '1' ? HIGH : LOW);
      digitalWrite(i+6, bin2[i] == '1' ? HIGH : LOW);
    }
    
    int state[4];
    
    for (int i = 0; i < 4; i++) {
      state[i] = digitalRead(i+10);
      Serial.print(state[i]);
    }
    
    Serial.print("\n");
  }
}