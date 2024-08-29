int left_wheelA = 5; int left_wheelB = 9;
int right_wheelA = 6; int right_wheelB = 10;

int S2 = 12;
int S3 = 7;
int S4 = 4;

//new code
int left ;
int centre;
int right;
void setup() {
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  Serial.begin(115200);
  //  Serial.begin(115200); // Starts the serial communication
  pinMode(left_wheelA, OUTPUT); pinMode(left_wheelB, OUTPUT);
  pinMode(right_wheelA, OUTPUT); pinMode(right_wheelB, OUTPUT);
}
void loop() {
  left = digitalRead(S2);
  centre = digitalRead(S3);
  right = digitalRead(S4);

  Serial.print(left);
  Serial.print(right);
  Serial.println(centre);

  if (left == HIGH && centre == LOW && right == HIGH) {
    Serial.println("ON Line, Go straight!!");
    analogWrite(left_wheelA, 90); analogWrite(left_wheelB, 80);
    analogWrite(right_wheelA, LOW); analogWrite(right_wheelB, LOW);
  } else if (left == LOW && centre == HIGH && right == HIGH) {
    Serial.println("Moving on right side, turn left");
    analogWrite(left_wheelA, 0); analogWrite(left_wheelB, 90);
    analogWrite(right_wheelA, 0); analogWrite(right_wheelB, LOW);
  } else if (left == HIGH && centre == HIGH && right == LOW) {
    Serial.println("Moving on leftt side, turn right");
    analogWrite(left_wheelA, 100); analogWrite(left_wheelB, 0);
    analogWrite(right_wheelA, LOW); analogWrite(right_wheelB, LOW);
  }  else {
    Serial.println("No Line found");
    analogWrite(left_wheelA, LOW); analogWrite(left_wheelB, LOW);
    analogWrite(right_wheelA, LOW); analogWrite(right_wheelB, LOW);
  }
}
