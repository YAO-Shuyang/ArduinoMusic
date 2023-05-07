
int PinBuzzer=6;
int PinButton=2;
int ButtonState=0;
double Cmap[8] = {
    0, 261.6,
    293.6,
    329.6,
    349.2,
    392.0,
    440.0,
    493.8
};
int NotesVec[42]={1,1,5,5,6,6,5,4,4,3,3,2,2,1,5,5,4,4,3,3,2,5,5,4,4,3,3,2,1,1,5,5,6,6,5,4,4,3,3,2,2,1};
int DelayVec[42]={1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2}; 

int Single_Note=500;

void Notes_Translation(int notes,double multi){
    double duration=Single_Note*multi;
    tone(PinBuzzer,Cmap[notes]);
    delay(duration);
    pinMode(PinBuzzer,INPUT);
    delay(20);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PinBuzzer,OUTPUT);
  pinMode(PinButton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ButtonState == HIGH){
    digitalWrite(PinBuzzer,LOW);
  }
  else{
    digitalWrite(PinBuzzer,HIGH);
    for(int i=0;i!=42;++i)
      Notes_Translation(NotesVec[i],DelayVec[i]);
  }   

}
