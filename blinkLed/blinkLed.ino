int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //dilealnenetodoslosdiasqueeshermosisimo();
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(5000);
  
}
