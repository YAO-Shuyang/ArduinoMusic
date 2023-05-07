int PinBuzzer=6;
int PinButton=2;
int ButtonState=0;
double Gmap[22] = { //G大调
    0, 261.6,
    293.6,
    329.6,
    370.0,
    392.0,
    440.0,
    493.8,
    523.2,
    587.2,
    659.2,
    740,
    784,
    880,
    987.6,
    1046.4,
    1174.4,
    1318.4,
    1480,
    1568,
    1760,
    1975.2
};
int NotesVec[184]={
  5,6,7,5,9,7,6,9,6,5,3,7,5,4,4,
  3,4,5,6,2,5,6,7,8,8,7,6,5,6,5,6,7,5,9,7,
  6,9,6,5,3,3,4,5,2,2,3,4,5,6,2,5,6,7,
  8,8,7,6,5,5,7,8,9,9,9,9,
  9,10,9,8,7,7,7,7,7,8,7,6,5,5,5,4,
  3,4,4,5,6,6,7,6,7,6,7,8,9,9,9,

  9,9,10,9,8,7,7,7,7,8,7,6,5,4,3,3,4,5,6,
  2,5,6,7,6,6,6,5,5,5,6,
  7,5,9,7,6,9,6,5,3,7,5,4,4,
  3,4,5,6,2,5,6,7,8,8,7,6,5,6,5,6,
  7,5,9,7,6,9,6,5,3,3,4,5,2,0,2,
  3,4,5,6,2,5,6,7,8,8,7,6,5,5
};

int DelayVec[184]={
  1,1,1,1,3,1,2,2,2,1,1,3,1,4,2,
  2,2,1,1,2,2,1,1,2,1,1,1,1,4,2,2,1,1,3,1,
  2,2,2,1,1,2,1,1,4,2,2,2,1,1,2,2,1,1,
  2,1,1,1,1,10,1,1,2,2,2,2,
  1,1,1,1,2,2,2,2,1,1,1,1,2,2,1,1,
  2,2,1,1,2,1,1,1,1,4,1,1,2,2,2,

  2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,1,1,
  2,2,1,1,3,1,1,1,10,1,1,
  1,1,3,1,2,2,2,1,1,3,1,4,2,
  2,2,1,1,2,2,1,1,2,1,1,1,1,4,1,1,
  1,1,3,1,2,2,2,1,1,2,1,1,4,1,1,
  2,2,1,1,2,2,1,1,2,1,1,1,1,10
};

int Single_Note=250;

void Notes_Translation(int notes,double multi){
    double duration=Single_Note*multi;
    if(notes!=0){    
      tone(PinBuzzer,Gmap[notes]);
      delay(duration);
      pinMode(PinBuzzer,INPUT);
      delay(10);
    }
    else{
      pinMode(PinBuzzer,INPUT);
      delay(duration);
      delay(10);
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PinBuzzer,OUTPUT);
  pinMode(PinButton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ButtonState = digitalRead(PinButton);
  if(ButtonState == HIGH){
    digitalWrite(PinBuzzer,LOW);
  }
  else{
    digitalWrite(PinBuzzer,HIGH);
    for(int i=0;i!=184;++i)
      Notes_Translation(NotesVec[i],DelayVec[i]);
  }   

}
