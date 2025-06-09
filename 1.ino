String voice;

#define RED    9
#define GREEN 10
#define BLUE  11

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Turn off all colors initially
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

void loop() {
  while (Serial.available()) {
    delay(10); // stability delay
    char c = Serial.read();
    if (c == '#') break;
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println("Received: " + voice);

    if (voice == "*red") {
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    } 
    else if (voice == "*green") {
      analogWrite(RED, 0);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 0);
    }
    else if (voice == "*blue") {
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 255);
    }
    else if (voice == "*off") {
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    }

    voice = ""; // Reset input string
  }
}
