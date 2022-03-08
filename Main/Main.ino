#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    256
#define Bt 16
CRGB leds[NUM_LEDS];
//--------------------------------------------------------WiFi setup
const char *ssid     = "**";
const char *password = "**";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.nict.jp",60*60*9, 30*60*1000);
//--------------------------------------------------------Campus
int Campus[3][Bt][Bt]{
{  
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
},
{  
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
},
{  
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}
};
//--------------------------------------------------------Picture
bool HelloWorld[Bt][Bt]={
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
bool Fuku[Bt][Bt]={
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
bool WIFIOK[Bt][Bt]={
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
};
//--------------------------------------------------------Fonts
bool abt_one[5][3]={
  {0, 1, 0},
  {1, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {1, 1, 1}
};
bool abt_two[5][3]={
  {1, 1, 1},
  {0, 0, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 1, 1}
};
bool abt_three[5][3]={
  {1, 1, 1},
  {0, 0, 1},
  {1, 1, 1},
  {0, 0, 1},
  {1, 1, 1}
};
bool abt_four[5][3]={
  {1, 0, 0},
  {1, 1, 0},
  {1, 1, 0},
  {1, 1, 1},
  {0, 1, 0}
};
bool abt_five[5][3]={
  {1, 1, 1},
  {1, 0, 0},
  {1, 1, 1},
  {0, 0, 1},
  {1, 1, 1}
};
bool abt_six[5][3]={
  {1, 1, 1},
  {1, 0, 0},
  {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1}
};
bool abt_seven[5][3]={
  {1, 1, 1},
  {1, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1}
};
bool abt_eight[5][3]={
  {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1}
};
bool abt_nine[5][3]={
  {1, 1, 1},
  {1, 0, 1},
  {1, 1, 1},
  {0, 0, 1},
  {1, 1, 1}
};
bool abt_o[5][3]={
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1}
};
//--------------------------------------------------------Cursor
int Cursor[2]={0,0};
//--------------------------------------------------------SETUP
void setup() {
  int hang=3;
  int lie=2;
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);  
  LEDsetup();
  cleanAll();
  WiFi.begin(ssid,password);
  while ( WiFi.status() != WL_CONNECTED ) {
  Campus[1][hang][lie]=20;
  displayShow();
  if(lie>=14){
    hang=hang+2;
    lie=2;
  }
  else{
    lie=lie+2;
  }
  delay (250);
  Serial.print ( "." );
  }
  paintBucket(0,0,0);
  printWiFiOK(2000, 25,16,0);
  timeClient.begin();

}
//--------------------------------------------------------LOOP
void loop() {
PrintClock(10,10,10);
}
//----------------------------------------------------------FUNCTIONS--
void LEDsetup(void){
  int delaytime=500;
  for(int i=0; i<256; i++){
    leds[i]=CRGB(125,0,0);
  }
      FastLED.show();
    delay(delaytime);
  for(int i=0; i<256; i++){
    leds[i]=CRGB(0,125,0);
  }
      FastLED.show();
    delay(delaytime);
    for(int i=0; i<256; i++){
    leds[i]=CRGB(0,0,125);
  }
      FastLED.show();
    delay(delaytime);
    for(int i=0; i<256; i++){
    leds[i]=CRGB(125,125,125);
  }
      FastLED.show();
    delay(delaytime);
    for(int i=0; i<256; i++){
    leds[i]=CRGB(0,0,0);
  }
      FastLED.show();
    delay(delaytime);
    cleanAll();
    delay(500);
}

void displayShow(void){
  int r,c,LEDnum;
  for(r=0;r<Bt;r++){
    for(c=0;c<Bt;c++){
      if(r%2==0){//偶数行的Lednum=行数*15+列数,偶数行的Lednum=行数*15+(16-列数),因为灯条的方向是每行左右交互的.
        LEDnum=16*r+c;
      }
      else{
        LEDnum=16*r+15-c;
      }
      leds[LEDnum]=CRGB(Campus[0][r][c],Campus[1][r][c],Campus[2][r][c]);   
    }
  }
  FastLED.show();
}

void cleanAll(void){
  int r,c,l;  
  for(l=0;l<3;l++){
    for(r=0;r<Bt;r++){
      for(c=0;c<Bt;c++){
        Campus[l][r][c]=0;
      }
    }
  } 
  displayShow();
}

void paintBucket(int R,int G,int B){
  int r,c;
  for(r=0;r<Bt;r++){
      for(c=0;c<Bt;c++){
        Campus[0][r][c]= R;  
        Campus[1][r][c]= G;
        Campus[2][r][c]= B; 
      }
  }
}

void printNum(int Num, int R, int G, int B){
switch (Num){
  case 1:
    for(int c=0; c<5; c++){
      for(int r=0; r<3; r++){
        if(abt_one[c][r]==1){
        Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
        Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
        Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
        }
      }
    }
  break;
  case 2:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_two[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 3:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_three[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 4:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_four[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 5:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_five[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 6:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_six[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 7:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_seven[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 8:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_eight[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }  
  break;
  case 9:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_nine[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
  case 0:
  for(int c=0; c<5; c++){
    for(int r=0; r<3; r++){
      if(abt_o[c][r]==1){
      Campus[0][c+Cursor[0]][r+Cursor[1]]=R;
      Campus[1][c+Cursor[0]][r+Cursor[1]]=G;
      Campus[2][c+Cursor[0]][r+Cursor[1]]=B;
      }
    }
  }
  break;
}

Cursor[1]=Cursor[1]+3;

if(Cursor[1]<=12){
  Cursor[1]++;
}
else{
  Cursor[1]=0;
  Cursor[0]=Cursor[0]+6;
}

}

void SetCursor(int i, int j){
Cursor[0]=i;
Cursor[1]=j;
}

void printZEROtoTwo(int StayTime){
 cleanAll();
  SetCursor(1,0);
  for (int i=0;i<8;i++){
    printNum(i,0,70,0);
    displayShow();
    delay(1000);
  }
delay(StayTime);
}

void printWiFiOK(int stayTime, int R, int G, int B){
  cleanAll();
  for(int r=0;r<Bt;r++){
      for(int c=0;c<Bt;c++){
        Campus[0][r][c]= WIFIOK[r][c]*R;  
        Campus[1][r][c]= WIFIOK[r][c]*G;
        Campus[2][r][c]= WIFIOK[r][c]*B; 
      }
  }
  displayShow();
  delay(stayTime);
}

void PrintClock(int R, int G, int B){
 timeClient.update();

  int hours = timeClient.getHours();
  int minu =  timeClient.getMinutes();
  int sece =  timeClient.getSeconds();

  int Hu,Hd,Mu,Md,Su,Sd;

  Serial.printf("hour:%d minu:%d sece:%d\n", hours,minu,sece);
  paintBucket(0,0,0);
    Hu=hours/10%10;
    Hd=hours/1 %10;
    Mu=minu/10%10;
    Md=minu/1 %10;
    Su=sece/10%10;
    Sd=sece/1 %10;

  SetCursor(1,0);
  printNum(Hu,0,20,0);
  printNum(Hd,0,20,0);
  SetCursor(1,9);
  printNum(Mu,0,20,0);
  printNum(Md,0,20,0);
  SetCursor(8,4);
  printNum(Su,0,20,0);
  printNum(Sd,0,20,0);
  displayShow();

  delay(100);
}
