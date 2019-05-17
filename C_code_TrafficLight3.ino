int redLightCAR = 5; //on pin 5
int amberLightCAR = 4;
int greenLightCAR = 3;
int redLightPED = 7;
int greenLightPED = 6;
int button = 8;
int timeToCross = 5000;

void setup() {
  pinMode(redLightCAR, OUTPUT);
  pinMode(amberLightCAR, OUTPUT);
  pinMode(greenLightCAR, OUTPUT);
  pinMode(redLightPED, OUTPUT);
  pinMode(greenLightPED, OUTPUT);

  pinMode(button, INPUT);

  digitalWrite(redLightPED, HIGH); //start the flow chart from here
  digitalWrite(greenLightCAR, HIGH);
}

void loop() {
    if (digitalRead(button) == LOW) { //when the button is pressed
      trafficLight(); //call the function
      delay(3000); //3secs
  }
}

void trafficLight() {
  digitalWrite(redLightCAR, HIGH);
  digitalWrite(greenLightPED, HIGH);
  delay(timeToCross); 
  for (int i=0; i<10; i++) { //for loop for flashing just the green PED light
    digitalWrite(greenLightPED, LOW);
    delay(500);
    digitalWrite(greenLightPED, HIGH);
    delay(500);
  }
  digitalWrite(amberLightCAR, HIGH);
  delay(2000); 
  digitalWrite(redLightCAR, LOW); 
  digitalWrite(greenLightPED, LOW);
  digitalWrite(amberLightCAR, LOW); 
  digitalWrite(greenLightCAR, HIGH);
  digitalWrite(redLightPED, HIGH);
  delay(4000);
  digitalWrite(greenLightCAR, LOW);
  digitalWrite(amberLightCAR, HIGH);
  delay(2000);
  digitalWrite(amberLightCAR, LOW); 
}
