const int m1_enablePin = 9;
const int m1_1pin = 2;
const int m1_2pin = 3;

const int m2_enablePin = 10;
const int m2_1pin = 4;
const int m2_2pin = 5;

void setup() {
  pinMode(m1_enablePin , OUTPUT);
  pinMode(m1_1pin , OUTPUT);
  pinMode(m1_2pin , OUTPUT);
  pinMode(m2_enablePin , OUTPUT);
  pinMode(m2_1pin , OUTPUT);
  pinMode(m2_2pin , OUTPUT);

  digitalWrite(m1_enablePin, HIGH);
  digitalWrite(m2_enablePin, HIGH);
}

void loop() {
  digitalWrite(m1_1pin, HIGH); //backwards state
  digitalWrite(m1_2pin, LOW);
  digitalWrite(m2_1pin, HIGH);
  digitalWrite(m2_2pin, LOW);
  delay(2000);
  digitalWrite(m1_1pin, LOW); //forwards state
  digitalWrite(m1_2pin, HIGH);
  digitalWrite(m2_1pin, LOW);
  digitalWrite(m2_2pin, HIGH);
  delay(2000);
  digitalWrite(m1_1pin, LOW); //stopped
  digitalWrite(m1_2pin, LOW);
  digitalWrite(m2_1pin, LOW);
  digitalWrite(m2_2pin, LOW);
  delay(2000);
  

}
void turnRight(){
  digitalWrite(m1_1pin, HIGH); //backwards state
  digitalWrite(m1_2pin, LOW);
  digitalWrite(m2_1pin, HIGH);
  digitalWrite(m2_2pin, LOW);
}
