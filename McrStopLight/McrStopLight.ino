#define USB_CFG_DEVICE_NAME     'D','i','g','i','B','l','i','n','k'
#define USB_CFG_DEVICE_NAME_LEN 9
#include <DigiUSB.h>
byte in = 0;
int Blue = 0;
int Red = 0;
int Green = 0;
int Yellow = 0;

int next = 0;

void setup() {
    DigiUSB.begin();
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(5,OUTPUT);
}


void loop() {
    setYellow();
    setGreen();
    DigiUSB.refresh();
    setYellow();
    setGreen();
    
    if (DigiUSB.available() > 0) {
       in = 0;
       
       in = DigiUSB.read();
       if (next == 0){
         if(in == 'r'){
           next = 1;
           DigiUSB.println("Start");
         }
         if(in == 'g'){
           next = 2;
           DigiUSB.println("Start");
         }
         if(in == 'b'){
           next = 3;
           DigiUSB.println("Start");
         }
         if(in == 'y'){
           next = 4;
           DigiUSB.println("Start");
         }
       }
       else if (next == 1){
            Red = in;
            DigiUSB.print("Red ");
            DigiUSB.println(in,DEC);
            next = 0;
       }
       else if (next == 2){
            Green = in;
            DigiUSB.print("Green ");
            DigiUSB.println(in,DEC);
            next = 0;
       }
       else if (next == 3){
            Blue = in;
            DigiUSB.print("Blue ");
            DigiUSB.println(in,DEC);
            next = 0;
       }
       else if (next == 4){
            Yellow = in;
            DigiUSB.print("Yellow ");
            DigiUSB.println(in,DEC);
            next = 0;
       }
    }

    setRed();
    setGreen();    
    setBlue();
    setYellow();
}

void setRed() {
  analogWrite(0, Red);
}
void setBlue() {
  analogWrite(1, Blue);
}

void setYellow(){
    if(Yellow == 0){
      digitalWrite(2,LOW);
      return;
    }
    else if(Yellow == 255){
      digitalWrite(2,HIGH);
      return;
    }
    // On period  
    for (int x=0;x<Yellow;x++){
    digitalWrite(2,HIGH);
    } 
    
    // Off period
    
    for(int x=0;x<(255-Yellow);x++){
    digitalWrite(2,LOW);
    }
} 

void setGreen(){
    if(Green == 0){
      digitalWrite(5,LOW);
      return;
    }
    else if(Green == 255){
      digitalWrite(5,HIGH);
      return;
    }
    // On period  
    for (int x=0;x<Green;x++){
    digitalWrite(5,HIGH);
    } 
    
    // Off period
    
    for(int x=0;x<(255-Green);x++){
    digitalWrite(5,LOW);
    }
} 

