const int Length=25;
int PinBuzzer = 7;
int PinBuzzer2 = 4;

double Cmap[15] = {
    0, 261.6,
    293.6,
    329.6,
    349.2,
    392.0,
    440.0,
    493.8,
    523.2,
    587.2,
    659.2,
    698.4,
    784,
    880,
    987.6,
};
int NotesVec[Length]={5,5,6,5,8,7,5,5,6,5,9,8,5,5,12,10,8,7,6,11,11,10,8,9,8};
int DelayVec[Length]={1,1,2,2,2,4,1,1,2,2,2,4,1,1,2,2,2,2,2,1,1,2,2,2,4}; 

int Single_Note=400;

void Notes_Translation(int notes,double multi){
    double duration=Single_Note*multi;
    tone(PinBuzzer,Cmap[notes]);
    tone(PinBuzzer2,Cmap[notes]);
    delay(duration);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PinBuzzer,OUTPUT);
  pinMode(PinBuzzer2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    for(int i=0;i!=Length;++i){
      digitalWrite(PinBuzzer,HIGH);
      Notes_Translation(NotesVec[i],DelayVec[i]);
      digitalWrite(PinBuzzer,LOW);
      delay(20);
      i++;
      digitalWrite(PinBuzzer2,HIGH);
      Notes_Translation(NotesVec[i],DelayVec[i]);
      digitalWrite(PinBuzzer2,LOW);
      delay(20);
    }
        
      
}
