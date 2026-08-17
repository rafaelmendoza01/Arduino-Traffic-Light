const int GreenLight = A5;
const int OrangeLight = A4;
const int RedLight = A3;
const int Buzzer = A2;
const int Button = 2;
bool pedestrian = false;

const int PedestrianRed = A1;
const int PedestrianGreen = A0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GreenLight, OUTPUT);
  pinMode(RedLight, OUTPUT);
  pinMode(OrangeLight, OUTPUT);
  pinMode(PedestrianRed, OUTPUT);
  pinMode(PedestrianGreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Button, INPUT);
  attachInterrupt(digitalPinToInterrupt(Button),Pedestrian, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GreenLight, HIGH);
  digitalWrite(PedestrianRed, HIGH);

  if(pedestrian){
    // this section changes state of the light to ted
    digitalWrite(GreenLight, LOW);
    digitalWrite(OrangeLight, HIGH);
    delay(1000);
    digitalWrite(OrangeLight, LOW);
    digitalWrite(RedLight, HIGH);

    //this section waits for time before turning back to green
    digitalWrite(Buzzer, HIGH);
    pedestrianCrossSound();
    digitalWrite(Buzzer, LOW);
    delay(5000);


    //this section will turn the state back to green
    digitalWrite(OrangeLight, HIGH);
    delay(1000);
    digitalWrite(OrangeLight, LOW);
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, HIGH);
    pedestrian = false;
  }
}


void Pedestrian(){
  pedestrian = true;
}

//this also controls the pedestrian's Lights
void pedestrianCrossSound(){
  digitalWrite(PedestrianRed, LOW);
    for(int i = 0; i < 2; i++){
    tone(Buzzer, 500);
    delay(500);
    noTone(Buzzer);
    delay(500);
  }

  digitalWrite(PedestrianGreen, HIGH);
  // Rapid chirping
  for(int i = 0; i < 35; i++){
    tone(Buzzer, 973);
    delay(25);
    noTone(Buzzer);
    delay(25);

    tone(Buzzer, 1200);
    delay(35);
    noTone(Buzzer);
    delay(25);

  }

  for(int i = 0; i < 15; i++){
    tone(Buzzer, 1000);  // 1000 Hz beep
    delay(200);

    noTone(Buzzer);
    delay(800);          // Long interval

  }
  
  for(int i = 0; i < 10; i++){
  // Lower "woodpecker" component
    tone(Buzzer, 500);
    delay(100);

    noTone(Buzzer);
    delay(50); 
  }

  digitalWrite(PedestrianGreen, LOW);
  digitalWrite(PedestrianRed, HIGH);

}
