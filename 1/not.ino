// Not
// Serial input: 0, 1

const int in1 = 2;
const int out1 = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(out1, INPUT);
}

void loop()
{
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
  
  	int bit1 = input[0] - '0';
  
  	digitalWrite(in1, bit1);
  
  	Serial.print("Pin2: ");
  	Serial.print(bit1);
    
    int state = digitalRead(out1);
  
  	Serial.print("\t\tPin4: ");
  	Serial.print(state);
  	Serial.print("\n");
  }
}