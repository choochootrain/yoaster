// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int prevState = 0;
int state = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  prevState = state;
  state = digitalRead(pushButton);
  
  if (state && !prevState) {
      Serial.println(1);
  } else if (!state && prevState) {
      Serial.println(2); 
  }
  
  delay(10);
}



