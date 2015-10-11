
#define debounceDelayMs 50


//RGB LED mappings:
int red = 10;
int green = 7;
int blue = 7;

//Asign solenoid to a pin
int solenoid = ?;

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

//one instance for each box:
boxState


// 1 min = 60000 milliseconds
//time the light will be active
unsigned long lightTime = 180000;



void setup(){

//I/O setup:
pinMode(solenoid, OUTPUT);
}


void loop(){

  delay(debounceDelayMs);
  
  //update the state machine
  switchState();
  
  
  //First toilet
  switch(boxsState){
        //state ZERO is default state, so it should just set the box as closed so it can be openened at any time.
         case ZERO:
            isBoxOpen = false;
            break:
            
        case ONE:
            isBoxOpen = false;
            if (!isBoxOpen) openBox;
            isBoxOpen = true;
            break:
            
        case TWO:
            break:
            
        case THREE:
            break:
            
        case FOUR:
            break:
            
        case FIVE:
            break:

  	}
}


//fire up the solenoid, to open the box
void openBox(){
  digitalWrite(solenoid, HIGH);
  
}

void switchState(int i){
  if(i == 0) boxState = ZERO;
  if(i == 1) boxState = ONE;
  if(i == 2) boxState = TWO;
  if(i == 3) boxState = THREE;
  if(i == 4) boxState = FOUR;
  if(i == 5) boxState = FIVE;
}

