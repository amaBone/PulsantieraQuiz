int pinStopTone = 12;


int tonePin = 52;
unsigned int tonePitch[]={4000,2000};
unsigned long toneTimeDiff[]={1200,650};
unsigned long toneTimer[]={0,0};
int toneState = 0;
bool canITone = 0;
int pushPins[] = {1,2,3,4,5,6,7,46};


int ledPins[]= {22,24,26,28,30,32,34,38};
int resetButton = 9;
int replayButton = 10;
int state = 0;
int winner = 0;
bool thereIsAWinner=0;
bool playerPool[] = {1,1,1,1,1,1,1,1};
int losersCount = 0;
void startup(){
   for(int i = 0;i<8;i++){
    if ((playerPool[i])){
     digitalWrite(ledPins[i], HIGH);
    delay(120);
    digitalWrite(ledPins[i], LOW);
    }
  }
  
  
  
 blinka();
  
}



void blinka(){
    for(int i = 0;i<8;i++){
      if ((playerPool[i])){
    digitalWrite(ledPins[i], HIGH);
      }
   
  }
  
    delay(220);
  
   for(int i = 0;i<8;i++){
    if ((playerPool[i])){
    digitalWrite(ledPins[i], LOW);
    }
  }
  
  delay(160);
}

void lookForButton(){ // state 1
  for (int i = 0;i<8;i++){
    if ((playerPool[i])){
    if(!digitalRead(pushPins[i])){
      thereIsAWinner=1;
      winner = i;
      state = 2;
      digitalWrite(ledPins[winner], HIGH);
      canITone = 1;
    }
    }
  }
  
}

void afterGame(){ //state 2
 bool choosen = 0;
      
    if (!(digitalRead(resetButton))){
      choosen = resetButton;
    }

    if (!(digitalRead(replayButton))){
      choosen = replayButton;
    }


  if (choosen == replayButton){
    digitalWrite(13,HIGH);
    removePlayer(winner);
    
  }
  if (choosen == resetButton){
    resetPlayerPool();
    
  }
  
}

void resetPlayerPool(){
  canITone = 0;
  noTone(tonePin);
  losersCount = 0;
  for (int i=0;i<8; i++){
    playerPool[i] = true;
  }
  winner = 0;
  thereIsAWinner = 0;
  state = 0;

  blinka();
  blinka();
}

void removePlayer(int player){
  losersCount++;
  playerPool[player] = 0;
  thereIsAWinner = 0;
  state = 1;
  if (losersCount>6){
    resetPlayerPool();
  }
  blinka();
  blinka();
}

void tonize()
{
  if (canITone){
    if (toneState == 0){
      //inizia a suonare  da adesso
      toneState=1;
      toneTimer[0] = millis();
      tone(tonePin,tonePitch[0]);
    } 
    if (toneState == 1){
      if ( (millis()-toneTimer[0]) > toneTimeDiff[0]){
        toneState = 2;
        toneTimer[1] = millis();
        tone(tonePin,tonePitch[1]);
      }
    }
    if (toneState == 2){
      if ( (millis()-toneTimer[1]) > toneTimeDiff[1]){
        toneState = 1;
        toneTimer[0] = millis();
          tone(tonePin,tonePitch[0]);      }
    }
  }
    
  if (canITone == 0){
    noTone(tonePin);
  }
  
}

void setup()
{ 
 
  
  for(int i = 0;i<8;i++){
   pinMode(ledPins[i],OUTPUT);
   pinMode(pushPins[i],INPUT_PULLUP);
  }

  pinMode(13,OUTPUT);
  pinMode(tonePin,OUTPUT);
  
  pinMode(pinStopTone,INPUT_PULLUP);
  
  pinMode(resetButton,INPUT_PULLUP);
  pinMode(replayButton,INPUT_PULLUP);
}


void loop()
{ 
  if (state == 0){
    startup();
    blinka();
    blinka();
    state = 1;

  }
  
  if (state ==1){
    
    lookForButton();
    
  }
  
  if (state == 2){
    
     tonize();
    
  }

  if (!(digitalRead(resetButton))){
      digitalWrite(13,HIGH);
      resetPlayerPool();
    }

   if ((digitalRead(pinStopTone))){
     canITone=0;
    }
}
