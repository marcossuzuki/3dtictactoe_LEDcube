#include "Tlc5940.h"

float tempo=200;
float tempoinput=300;
const int parada=100;
const int paradainput=300;
boolean play1[3]={0,0,1};
boolean play2[3]={1,0,0};
boolean RGB1[3][3][3] = {{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
boolean RGB2[3][3][3] = {{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
boolean RGB3[3][3][3] = {{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
int Pins[] = {A2,A3,A4,A5,0,4,2};
int x=1, y=1, z=1;
int zerox=1, zeroy=1, zeroz=1;
boolean pressed=1;
boolean pisca1[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
boolean pisca2[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
boolean pisca3[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
char velha[3][3][3]={{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}};
int cont=3;
int brilho=2095;
boolean confirm=0;
char letra='X';

void setup()
{
  Tlc.init();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  for(int i=0; i<7;i++){
   pinMode(Pins[i], INPUT_PULLUP);
  }
}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

void loop(){
    input();
    if(letra=='X'){
      pisca(play1);
      }
    else{
      pisca(play2);
      }
      
    if (confirm==1){
     confirm=0;
     if(velha[x][y][z]==' '){
      velha[x][y][z]=letra;
      bool vencedor=vencer(letra);
      if(vencedor==1){
        resetFunc();
      }
      if(letra=='X'){
        Movimento(play1);
        letra='O';
      }
      else{
        Movimento(play2);
        letra='X';
      }
    }
    }
    updateLed(RGB1,pisca1,5);
    updateLed(RGB2,pisca2,6);
    updateLed(RGB3,pisca3,7);
} 

bool vencer(char let){
  return((velha[0][0][0]==let && velha[0][1][0]==let && velha[0][2][0]==let) ||
         (velha[0][0][0]==let && velha[1][1][0]==let && velha[2][2][0]==let) ||
         (velha[0][0][0]==let && velha[1][0][0]==let && velha[2][0][0]==let) ||
         (velha[0][1][0]==let && velha[1][1][0]==let && velha[2][1][0]==let) ||
         (velha[0][2][0]==let && velha[1][2][0]==let && velha[2][2][0]==let) ||
         (velha[1][0][0]==let && velha[1][1][0]==let && velha[1][2][0]==let) ||
         (velha[2][0][0]==let && velha[2][1][0]==let && velha[2][2][0]==let) ||
         (velha[2][0][0]==let && velha[1][1][0]==let && velha[0][2][0]==let) ||
         (velha[0][0][1]==let && velha[0][1][1]==let && velha[0][2][1]==let) ||
         (velha[0][0][1]==let && velha[1][1][1]==let && velha[2][2][1]==let) ||
         (velha[0][0][1]==let && velha[1][0][1]==let && velha[2][0][1]==let) ||
         (velha[0][1][1]==let && velha[1][1][1]==let && velha[2][1][1]==let) ||
         (velha[0][2][1]==let && velha[1][2][1]==let && velha[2][2][1]==let) ||
         (velha[1][0][1]==let && velha[1][1][1]==let && velha[1][2][1]==let) ||
         (velha[2][0][1]==let && velha[2][1][1]==let && velha[2][2][1]==let) ||
         (velha[2][0][1]==let && velha[1][1][1]==let && velha[0][2][1]==let) ||
         (velha[0][0][2]==let && velha[0][1][2]==let && velha[0][2][2]==let) ||
         (velha[0][0][2]==let && velha[1][1][2]==let && velha[2][2][2]==let) ||
         (velha[0][0][2]==let && velha[1][0][2]==let && velha[2][0][2]==let) ||
         (velha[0][1][2]==let && velha[1][1][2]==let && velha[2][1][2]==let) ||
         (velha[0][2][2]==let && velha[1][2][2]==let && velha[2][2][2]==let) ||
         (velha[1][0][2]==let && velha[1][1][2]==let && velha[1][2][2]==let) ||
         (velha[2][0][2]==let && velha[2][1][2]==let && velha[2][2][2]==let) ||
         (velha[2][0][2]==let && velha[1][1][2]==let && velha[0][2][2]==let) ||
         (velha[0][0][0]==let && velha[0][0][1]==let && velha[0][0][2]==let) ||
         (velha[0][0][0]==let && velha[1][0][1]==let && velha[2][0][2]==let) ||
         (velha[1][0][0]==let && velha[1][0][1]==let && velha[1][0][2]==let) ||
         (velha[2][0][0]==let && velha[2][0][1]==let && velha[2][0][2]==let) ||
         (velha[2][0][0]==let && velha[1][0][1]==let && velha[0][0][2]==let) ||
         (velha[0][1][0]==let && velha[0][1][1]==let && velha[0][1][2]==let) ||
         (velha[0][1][0]==let && velha[1][1][1]==let && velha[2][1][2]==let) ||
         (velha[1][1][0]==let && velha[1][1][1]==let && velha[1][1][2]==let) ||
         (velha[2][1][0]==let && velha[2][1][1]==let && velha[2][1][2]==let) ||
         (velha[2][1][0]==let && velha[1][1][1]==let && velha[0][1][2]==let) ||
         (velha[0][2][0]==let && velha[0][2][1]==let && velha[0][2][2]==let) ||
         (velha[0][2][0]==let && velha[1][2][1]==let && velha[2][2][2]==let) ||
         (velha[1][2][0]==let && velha[1][2][1]==let && velha[1][2][2]==let) ||
         (velha[2][2][0]==let && velha[2][2][1]==let && velha[2][2][2]==let) ||
         (velha[2][2][0]==let && velha[1][2][1]==let && velha[0][2][2]==let) ||
         (velha[0][0][0]==let && velha[1][1][1]==let && velha[2][2][2]==let) ||
         (velha[0][0][2]==let && velha[1][1][1]==let && velha[2][2][0]==let) ||
         (velha[0][2][0]==let && velha[1][1][1]==let && velha[2][0][2]==let) ||
         (velha[0][2][2]==let && velha[1][1][1]==let && velha[2][0][0]==let) ||
         (velha[0][1][0]==let && velha[1][1][1]==let && velha[1][2][2]==let) ||
         (velha[0][1][2]==let && velha[1][1][1]==let && velha[1][2][0]==let) ||
         (velha[1][0][0]==let && velha[1][1][1]==let && velha[1][2][2]==let) ||
         (velha[1][0][2]==let && velha[1][1][1]==let && velha[1][2][0]==let) ||
         (velha[0][0][0]==let && velha[0][1][1]==let && velha[0][2][2]==let) ||
         (velha[0][0][2]==let && velha[0][1][1]==let && velha[0][2][0]==let) ||
         (velha[2][0][0]==let && velha[2][1][1]==let && velha[2][2][2]==let) ||
         (velha[2][0][2]==let && velha[2][1][1]==let && velha[2][2][0]==let));
  }

void pisca(boolean play[2]){
    if(zeroz==0){
    pisca1[zerox][zeroy][0]=0;
    pisca1[zerox][zeroy][1]=0;
    pisca1[zerox][zeroy][2]=0;
    }
    if(zeroz==1){
    pisca2[zerox][zeroy][0]=0;
    pisca2[zerox][zeroy][1]=0;
    pisca2[zerox][zeroy][2]=0;
    }
    if(zeroz==2){
    pisca3[zerox][zeroy][0]=0;
    pisca3[zerox][zeroy][1]=0;
    pisca3[zerox][zeroy][2]=0;
    }
    if(z==0){
        pisca1[x][y][0]=play[0];
        pisca1[x][y][1]=play[1];
        pisca1[x][y][2]=play[2];
    }
    if(z==1){
        pisca2[x][y][0]=play[0];
        pisca2[x][y][1]=play[1];
        pisca2[x][y][2]=play[2];
    }
   if(z==2){
        pisca3[x][y][0]=play[0];
        pisca3[x][y][1]=play[1];
        pisca3[x][y][2]=play[2];
    }
  }

void Movimento(boolean play[2]){
    if(z==0){
        RGB1[x][y][0]=play[0];
        RGB1[x][y][1]=play[1];
        RGB1[x][y][2]=play[2];
    }
    if(z==1){
        RGB2[x][y][0]=play[0];
        RGB2[x][y][1]=play[1];
        RGB2[x][y][2]=play[2];
    }
   if(z==2){
        RGB3[x][y][0]=play[0];
        RGB3[x][y][1]=play[1];
        RGB3[x][y][2]=play[2];
    }
}

void input(){
 if(millis()>=tempoinput){
    tempoinput=millis()+paradainput;
    if (analogRead(A0)>800 && analogRead(A1)>400 && analogRead(A1)<700){ //eixo y
      zerox=x;
      zeroy=y;
      zeroz=z;
      y++;
      if(y==3){
        y=0;
      }
    }
    if(analogRead(A0)<300 && analogRead(A1)>400 && analogRead(A1)<600){
      zerox=x;
      zeroy=y;
      zeroz=z;
      y--;
      if(y==-1){
        y=2;
      }
    }
  
    if (analogRead(A1)>800 && analogRead(A0)>200 && analogRead(A0)<800){ //eixo x
      zerox=x;
      zeroy=y;
      zeroz=z;
      x--;
      if(x==-1){
        x=2;
      }
    }
    if(analogRead(A1)<200 && analogRead(A0)>200 && analogRead(A0)<800){
      zerox=x;
      zeroy=y;
      zeroz=z;
      x++;
      if(x==3){
        x=0;
      }
    }
    if (digitalRead(Pins[4])==0 && digitalRead(Pins[6])==1 && digitalRead(Pins[5])==1){
      zerox=x;
      zeroy=y;
      zeroz=z;
      z++;
      if(z==3){
        z=0;
      }
     }
    if (digitalRead(Pins[6])==0 && digitalRead(Pins[4])==1 && digitalRead(Pins[5])==1){
      zerox=x;
      zeroy=y;
      zeroz=z;
      z--;
      if(z==-1){
        z=2;
      }
     }
  }
  if (digitalRead(Pins[5])==0 && digitalRead(Pins[6])==1 && digitalRead(Pins[4])==1 && pressed==0){
   pressed=1;
   confirm=1;
  }
  else if (digitalRead(Pins[5])==1 && pressed==1){
   pressed=0;
 }
 if (digitalRead(Pins[1])==0 && digitalRead(Pins[2])==0 && pressed==0){
   pressed=1;
   resetFunc();
  }
  else if (digitalRead(Pins[5])==1 && digitalRead(Pins[2])==0 && pressed==1){
   pressed=0;
 }
  while(digitalRead(Pins[3])==0){
    if(letra=='X'){
      if(analogRead(A0)<300 && analogRead(A1)>800){
        play1[0]=0;
        play1[1]=1;
        play1[2]=1;
      }
      else if(analogRead(A0)>800 && analogRead(A1)>800){
        play1[0]=1;
        play1[1]=1;
        play1[2]=0;
      }
      else if(analogRead(A0)>800 && analogRead(A1)<300){
        play1[0]=1;
        play1[1]=0;
        play1[2]=1;
      }
      else if(analogRead(A1)>800){
        play1[0]=0;
        play1[1]=1;
        play1[2]=0;
      }
      else if(analogRead(A0)<300){
        play1[0]=0;
        play1[1]=0;
        play1[2]=1;        
      }
      else if(analogRead(A0)>800){
        play1[0]=1;
        play1[1]=0;
        play1[2]=0;
    }
    else if(analogRead(A1)<300){
        play1[0]=1;
        play1[1]=1;
        play1[2]=1;
   }
 }
   else{
      if(analogRead(A0)<300 && analogRead(A1)>800){
        play2[0]=0;
        play2[1]=1;
        play2[2]=1;
      }
      else if(analogRead(A0)>800 && analogRead(A1)>800){
        play2[0]=1;
        play2[1]=1;
        play2[2]=0;
      }
      else if(analogRead(A0)>800 && analogRead(A1)<300){
        play2[0]=1;
        play2[1]=0;
        play2[2]=1;
      }
      else if(analogRead(A1)>800){
        play2[0]=0;
        play2[1]=1;
        play2[2]=0;
      }
      else if(analogRead(A0)<300){
        play2[0]=0;
        play2[1]=0;
        play2[2]=1;        
      }
      else if(analogRead(A0)>800){
        play2[0]=1;
        play2[1]=0;
        play2[2]=0;
     }
     else if(analogRead(A1)<300){
        play2[0]=1;
        play2[1]=1;
        play2[2]=1;
 }
}
  updateLed(RGB1,pisca1,5);
  updateLed(RGB2,pisca2,6);
  updateLed(RGB3,pisca3,7);
}
}

void updateLed(boolean RGB[3][3][3],boolean pisca[3][3][3], int pin){
  digitalWrite(pin,HIGH);
  Tlc.clear();
  for(int i=0; i<3;i++){
    for(int j=0; j<3;j++){
      for(int k=0; k<3;k++){
       Tlc.set(k+(3*j)+(9*i), RGB[i][j][k]*brilho);
  }}}
  for(int i=0; i<3;i++){  
   for(int j=0; j<3;j++){ 
    for(int k=0; k<3;k++){
     if(pisca[i][j][k]==1){
       if(millis()>=tempo){
        Tlc.set(k+(3*j)+(9*i), brilho);
       }
       else{
        Tlc.set((k+3*j+9*i), 0);
       }
     }
   }}}
  
  if(millis()>=tempo+parada){
    tempo=millis()+parada;
  }
  Tlc.update();
  delay(cont);
  digitalWrite(pin,LOW); 
  delay(cont);
  digitalWrite(pin,HIGH);
}
