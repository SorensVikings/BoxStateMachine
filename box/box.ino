
#define delayTime 50


//RGB LED mappings:
int red = 11;
int green = 8;
int blue = 3;

//Asign solenoid to a pin
int solenoid = 7;

//bool to check if box is open so that the solenoid doesn't hammer away
bool isBoxOpen = false;


//An enum to store the different states of the box
enum boxState{
  ZERO,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE
};

boxState box;

// 1 min = 60000 milliseconds
//time the light will be active
unsigned long lightTime = 180000;



void setup(){

//I/O setup:
pinMode(solenoid, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}


void loop(){
  
  digitalWrite(7, HIGH);
  
  delay(5000);
  
  //update the state machine
  updateBoxState();  
  
  //First toilet
  switch(box){
        //state ZERO is default state, so it should just set the box as closed so it can be openened at any time.
         case ZERO:
            break;
            
        case ONE:
            if (!isBoxOpen) openBox();
            break;
            
        case TWO:
            if (!isBoxOpen) openBox();
            greenLightOn();
            break;
            
        case THREE:
            if (!isBoxOpen) openBox();
            flashGreen();
            break;
            
        case FOUR:
            if (!isBoxOpen) openBox();
            flashGreen();
            flashRed();
            break;
            
        case FIVE:
            break;
            
        

  	}
}



void waitForBoxClose() {
 
  bool wait = true;
  
  while(wait) {
   
   
    
  }
 
  
}


//fire up the solenoid, to open the box
void openBox(){
  digitalWrite(solenoid, HIGH);
  delay(delayTime);
  digitalWrite(solenoid, LOW);
  
}


void updateBoxState() {
  
    switchState(2);

  
}

void switchState(int i){
  if(i == 0) box = ZERO;
  if(i == 1) box = ONE;
  if(i == 2) box = TWO;
  if(i == 3) box = THREE;
  if(i == 4) box = FOUR;
  if(i == 5) box = FIVE;
  
  
}


void flashRed(){
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
}

void flashGreen(){
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
}


void redLightOn() {

    digitalWrite(red, HIGH);

}



void redLightOff() {

    digitalWrite(red, LOW);

}



void greenLightOn() {

    digitalWrite(green, HIGH);

}



void greenLightOff() {

    digitalWrite(green, HIGH);

}




void blueLightOn() {

    digitalWrite(blue, HIGH);

}


void blueLightOff() {

    digitalWrite(blue, LOW);

}
