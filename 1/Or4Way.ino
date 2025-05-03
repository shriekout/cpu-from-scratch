// Or 4bit
// Serial input: 0000

void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++)
  	pinMode(i+2, OUTPUT);
  
  pinMode(8, INPUT);
}

void loop()
{
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    for (int i = 0; i < 4; i++)
      digitalWrite(i+2, input[i] == '1' ? HIGH : LOW);
    
    int state = digitalRead(8);
    Serial.print(state);
    Serial.print("\n");
  }
}