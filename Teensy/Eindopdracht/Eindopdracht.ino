#define LED 5
#define POT 14

int potValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(POT);
  Serial.println("/freq " + String(potValue));
  delay(10);
}
