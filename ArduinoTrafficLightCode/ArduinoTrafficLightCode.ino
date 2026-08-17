const int GreenLight = 13;
const int OrangeLight = 12;
const int RedLight = 11;
const int Button = 2;
bool pedestrian = false;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GreenLight, OUTPUT);
  pinMode(RedLight, OUTPUT);
  pinMode(OrangeLight, OUTPUT);
  pinMode(Button, INPUT);
  attachInterrupt(digitalPinToInterrupt(Button),Pedestrian, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GreenLight, HIGH);

  if(pedestrian){
    // this section changes state of the light to ted
    digitalWrite(GreenLight, LOW);
    digitalWrite(OrangeLight, HIGH);
    delay(1000);
    digitalWrite(OrangeLight, LOW);
    digitalWrite(RedLight, HIGH);

    //this section waits for time before turning back to green
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
