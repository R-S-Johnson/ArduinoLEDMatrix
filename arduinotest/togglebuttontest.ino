
int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int led = 13;
int status = false;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
}

void loop() {
  // put your main code her e, to run repeatedly:
  if (digitalRead(button1) == HIGH) {
    status = !status;
    digitalWrite(led, status);
    Serial.print("button pressed");
    delay(500);
  }
  else if (digitalRead(button2) == HIGH) {
    status = !status;
    digitalWrite(led, status);
    Serial.print("button pressed");
    delay(500);
  }
  else if (digitalRead(button3) == HIGH) {
    status = !status;
    digitalWrite(led, status);
    Serial.print("button pressed");
    delay(500);
  }
  else if (digitalRead(button4) == HIGH) {
    status = !status;
    digitalWrite(led, status);
    Serial.print("button pressed");
    delay(500);
  }
}
