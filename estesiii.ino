#include <Servo.h>
Servo servo1, servo2, servo3, servo4;
int i;
int state=0;

  float matriz[4][41]{
    { 85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85, 75,65,55,45,35,25,15,5,5,5,5,5,5,5,0,0,0,0},
    {  0, 2, 3, 6, 8,10,12,12,12,15,15,15,12,9,6,3,1,1,1,1,1,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {  0, 8, 10, 15, 20, 25, 30, 35, 37,37,37,37,43,43,43,35,30,25,20,15,10,5,0, 0,0,0,0,0,0,5,10,10,10,10,10,10,10,10,10,10,10},
    {100,100,100,100,105,110,110,110,115,120,125,127,128,128,128,128,128,128,128,128,128,128,128, 128,128,128,128,128,128,128,128,126,124,122,110,105,105,100,100,100,100},
  };

void setup() {
  servo1.attach(8); //basedeclaracion de puerto donde va conectado el servo
  servo2.attach(9);//arriba y abajo
  servo3.attach(10);//adelante atras
  servo4.attach(11); //garra
  Serial.begin(9600); 
}

void loop() {


if(Serial.available()>0){
    state = Serial.read();
}


if(state == 'I'){

    for(i=0;i<41;i++){
  
        servo1.write(matriz[0][i]);
        servo2.write(matriz[1][i]);
        servo3.write(matriz[2][i]);
        servo4.write(matriz[3][i]); 
        delay(100);
        state=0;              
}
}

        servo1.write(85);
        servo2.write(0);
        servo3.write(0); //Pocicion inicial del brazo
        servo4.write(100); 
        delay(15); 
}
