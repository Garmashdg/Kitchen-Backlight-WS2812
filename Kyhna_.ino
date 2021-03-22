


#include "FastLED.h"          // библиотека для работы с лентой

#define LED_COUNT 111          //общее число све тодиодов в кольце/ленте


#define LED_COUNT1 57        //число светодиодов в первом отрезке ленты



#define LED_DT 13   //пин ленты
/////////////
//






int ledMode = 1; //переменная режимов
int max_bright = 255; //яркость


 const int bon = 2; //
 const int bm = 3;  // назначение кнопок
 const int bons = 4;//
 const int bms = 5;//

 //Служебные переменные
 volatile bool Flag_press = 0;
  volatile bool Flag_presss = 0;

   volatile bool Flag_kbon = 0;
  volatile bool Flag_kbons = 0;
 int bs=0;
 int bss = 0;
 int kbon = 0;
 int kbm =0 ;
 int kbons = 0;
 int kbms = 0 ;
 int i;
 ////////////////
 int a=30; //скорость изменения режимов в секундах
 int aa= 1000;
int b= 0;
unsigned long changeModef=0;
unsigned long changeModes=0;
int changeModecount=0;
unsigned long milage=0;
 //////////
 int leddone = 0;
 int leddones = 0; 
unsigned long milliss=0;
     
int sit=0;
int mil=0;

int rgbp=1;
int R=0;
int G=0;
int B=0;
int speedchange= 0; // скорость эффектов


////////////////Переменные эффектов
int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

int thisdelay = 20;          //-FX LOOPS DELAY VAR
int thisstep = 10;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int thisindex = 0;
int thisRED = 0;
int thisGRN = 0;
int thisBLU = 0;

int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 0;                //-HUE (0-255)
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR








////////////////



void setup()
{
  pinMode(bon, INPUT);  
   pinMode(bm, INPUT); 
   pinMode(bons, INPUT); 
   pinMode(bms, INPUT); 
  Serial.begin(9600);              // открыть порт для связи
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость

  LEDS.addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT);  // настрйоки для нашей ленты (ленты на WS2811, WS2812, WS2812B)

  for (int i = 0 ; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 0, 255, 0); // зеленый цвет
                        }
                        LEDS.show();// отослать команду
                        delay(1000);
                        for (int i = 0 ; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // зеленый цвет
                        }
                        LEDS.show();// отослать команду
                        delay(1000);
  //Предустановки
 Serial.println("setupdone////////////////////");
}
////////////////////////////////////////////////////////////////////////////////
  void changeMode()
  {
    
    milliss=millis();
    if(changeModecount==0)
    {
      milage=milliss;
      changeModef=aa*a;
      changeModes=milliss+changeModef;

    }
changeModecount=HIGH;
if(milliss>=milage&&milliss<=changeModes)
{

}
else
{
    changeModecount=LOW;
  ledMode++;

}
if (ledMode>4)
{
  ledMode=1;
}






   
  }

void getkey()
{
  kbon = digitalRead(bon);
  kbons= digitalRead(bons);
   
 
/////////////////////////////
    if(kbon == HIGH)
    {
    Flag_kbon = 0;
    }
//Переключение режима подсветки для двух частей ленты
      if((kbon == LOW) && (Flag_kbon == 0))
      {
        int count_press = 0;
        while(1)
        {
          kbon = digitalRead(bon);
              if(kbon == LOW)
        {
        count_press ++;
            if (count_press == 100)
            {
Flag_kbon=1;
kbon==LOW;
break;
            }
        }
              else
              {
                kbon==HIGH;
              Flag_kbon = 0;
              break;
              }
    }
      }

  
//////////////////////////////
    if(kbons == HIGH)
    {
    Flag_kbons = 0;
    }
//Переключение режима подсветки для двух частей ленты
      if((kbons == LOW) && (Flag_kbons == 0))
      {
        int count_press = 0;
        while(1)
        {
          kbons = digitalRead(bons);
              if(kbons == LOW)
        {
        count_press ++;
            if (count_press == 100)
            {
Flag_kbons=1;
kbons==LOW;
break;
            }
        }
              else
              {
                kbons==HIGH;
              Flag_kbons = 0;
              break;
              }
    }
      }
//////////////////////////////


  
}
//Получение сост кнопок.
void getbs()
{
     getkey();
  kbm = digitalRead(bm);
  
  kbms = digitalRead(bms); 
 
  //Переключение режима подсветки для двух частей ленты
    if(kbm == HIGH)
    {
    Flag_press = 0;
    }
//Переключение режима подсветки для двух частей ленты
      if((kbm == LOW) && (Flag_press == 0))
      {
        int count_press = 0;
        while(1)
        {
          kbm = digitalRead(bm);
              if(kbm == LOW)
        {
        count_press ++;
            if (count_press == 100)
            {
            Flag_press = 1;
              if (bs == 0)
              {
              bs= HIGH;
              break;
              }
                else
                {
                bs = LOW;
                break;
                }
            }
        }
              else
              {
              Flag_press = 0;
              break;
              }
    }
      }
  
//////////////////////////////
    if(kbms == HIGH)
    {
    Flag_presss = 0;
    }
//Переключение режима подсветки для двух частей ленты
      if((kbms == LOW) && (Flag_presss == 0))
      {
        int count_press = 0;
        while(1)
        {
          kbms = digitalRead(bms);
              if(kbms == LOW)
        {
        count_press ++;
            if (count_press == 500)
            {
            Flag_presss = 1;
              if (bss == 0)
              {
              bss= HIGH;
              break;
              }
                else
                {
                bss = LOW;
                break;
                }
            }
        }
              else
              {
              Flag_presss = 0;
              break;
              }
    }
      }

  
}
/////////////////////
  void sitwhile()
  {

  }
////////////////
void ledmods()
      {
         
        
        getbs();
        getkey();

        ////////////////////////////
              if(ledMode==1)
              {
                        getbs();
        getkey();




                  
                  

                  getbs();


 
                   //         Serial.println("milisif");
                            if(rgbp==1)
                            {
                                                            if(G!=0)
                              {
                               G=G-5;
                               
                              }
                            R++;
                            }
                            if(rgbp==2)
                            {
                              
                              if(R!=0)
                              {
                               R=R-5;
                               
                              }
                              B++; 
                            }
                            if(rgbp==3)
                            {
                              if(B!=0)
                              {
                               B=B-5;
                               
                              }
                              G++;
                            }
                            
                            
                      
                          
                          if(B==255)
                          {
                            rgbp=3;
                            
                          }
                          if(R==255)
                          {
                            rgbp=2;
                          
                          }
                          if(G==255)
                          {
                            rgbp=1;
                          }
                                for (int i = leddone ; i < leddones; i++ ) 
                                    {
                                      
                                        leds[i] = CRGB( R, G, B); //  цвет
                                        LEDS.show();// отослать команду
              
                                      }
                                      
///////////////////////////////////////////////

    /////////////////
                
                         changeMode();             
              }
   ///////////////////////
 if(ledMode==2)
 {

    getbs();
  

  
                          //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for (int idex = leddone ; idex < leddones; idex++ ) {
    leds[idex] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
  



changeMode();
  
 }
  ////////////////////
  if(ledMode==3)
  {

      getbs();
    
while(1)
{
  getbs();
     idex++;
  ihue = ihue + thisstep;
  if (idex >= leddones) {
    idex = leddone;
  }
  if (ihue > 255) {
    ihue = 0;
  }
  leds[idex] = CHSV(ihue, thissat, 255);
  LEDS.show();
  changeMode();
  delay(thisdelay);
  if(ledMode!=3)
  {
    break;
  }
   if(sit==1)
                        {
                          getkey();
                          
                          if(kbon==HIGH)
                          {
                            break;
                          }
                          if(bs==HIGH||bss==HIGH)
                          {
                            break;
                          }
                          if(kbons==LOW)
                          {
                           break; 
                          }
                                                    if(kbon==LOW&&kbons==LOW)
                          {
                            break;
                          }
                        }
                                                   if(sit==2)
                                                  {
                                                    getkey();
                                                            if(kbons==HIGH)
                                                            {
                                                              break;
                                                            }
                                                    if(bss==HIGH||bs==HIGH)
                                                    {
                                                      break;
                                                    }
                                                        if(kbon==LOW)
                                                          {
                                                           break; 
                                                          }
                                                                                    if(kbon==LOW&&kbons==LOW)
                          {
                            break;
                          }
                                                    
                                                  }
    if(sit==3)
    {
      getkey();
      if(kbon==HIGH||kbons==HIGH)
      {
        break;
      }
        if(bs==HIGH||bss==HIGH)
        {
          break;
        }
      
    }
    if(sit==4)
    {
      getkey();
      if(bs==HIGH||bss==LOW)
      {
        break;
      }
      if(kbon==HIGH||kbons==HIGH)
      {
        break;
      }
    }
    if(sit==5)
    {
      getkey();
      if(bs==LOW||bss==HIGH)
      {
        break;
      }
      if(kbon==HIGH||kbons==HIGH)
      {
        break;
      }
    }
}
  }
  ///////////////////
  if(ledMode==4)
  {
     
    
    
      getbs();
    

                  /////////////////
                    for (int i = leddone; i < leddones; i++ ) {
    tcount = tcount + .1;
    if (tcount > 3.14) {
      tcount = 0.0;
    }
    ibright = int(sin(tcount) * 255);
    leds[i] = CHSV(thishue, thissat, ibright);
    LEDS.show();
    delay(thisdelay);
  }
/////////////////////////////
changeMode();
    
  }
  ////////////////


      }
        
      
/////////////////////////////////////////////////////////////

      void loop() 
      {
                  getbs();
//////////////////////
               if(kbon == LOW &&kbons==HIGH )  //1 возможная ситуация
               {
                       if(bs == HIGH)
                       {
                        
                        for (int i = 0 ; i < LED_COUNT1; i++ ) {
                          leds[i] = CRGB( 255, 255, 255); // Белый цвет
                        }
                        LEDS.show();// отослать команду
                        for (int i = LED_COUNT1; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // Выключено
                        }
                        LEDS.show();// отослать команду
                        
                          
                          
                        
                       }
                       else
                       {
                        sit = 1;
                        leddone= 0;
                        leddones = LED_COUNT1;
                                                for (int i = LED_COUNT1; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // Выключено
                        }
                        LEDS.show();// отослать команду
                        
                        ledmods();
                       }
               }
//////////////////////////
               if(kbon == HIGH &&kbons==LOW )// 2 возможная ситуация
               {
                       if(bss == HIGH)
                       {
                        
                        for (int i = LED_COUNT1 ; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 255, 255, 255); // Белый цвет
                        }
                        LEDS.show();// отослать команду
                        
                        for (int i = 0; i < LED_COUNT1; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // Выключено
                        }
                        LEDS.show();// отослать команду
                        
                          
                          
                        
                       }
                       else
                       {
                        sit = 2;
                        leddone= LED_COUNT1;
                        leddones = LED_COUNT;
                                                for (int i = 0; i < LED_COUNT1; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // Выключено
                        }
                        LEDS.show();// отослать команду
                        
                        ledmods();
                       }
               }
////////////////////////////
 if(kbon == HIGH &&kbons==HIGH )// 3 возможная ситуация
 {
                        for (int i = 0; i < LED_COUNT; i++ ) {
                          leds[i] = CRGB( 0, 0, 0); // Выключено
                        }
                        LEDS.show();// отослать команду

 sit=3; 
 }
 ///////////////////
  if(kbon == LOW &&kbons==LOW )// 4 возможная ситуация
 {
  if(bs==HIGH&&bss==HIGH)// 5 возможная ситуация
  {
        for (int i = 0; i < LED_COUNT; i++ ) 
        {
      leds[i] = CRGB( 255, 255, 255); // <БЕЛЫЙ цвет
        }
       LEDS.show();// отослать команду
  }
  if(bs==LOW&&bss==LOW) // 6 возможная ситуация
  {
    
                            leddone= 0;
                        leddones = LED_COUNT;
                        sit=3;
                   ledmods();      
    
  }
  if(bs==LOW&&bss==HIGH)// 7 возможная ситуация
  {
    
    leddone=0;
    leddones=LED_COUNT1;
    sit=4;
            for (int i = LED_COUNT1; i < LED_COUNT; i++ ) 
        {
      leds[i] = CRGB( 255, 255, 255); // <БЕЛЫЙ цвет
        }
       LEDS.show();// отослать команду
       ledmods();
  }
  if(bs==HIGH&&bss==LOW)// 8 возможная ситуация
  {
    
    leddone=LED_COUNT1;
    leddones=LED_COUNT;
    sit=5;
    for (int i = 0; i < LED_COUNT1; i++ ) 
        {
      leds[i] = CRGB( 255, 255, 255); // <БЕЛЫЙ цвет
        }
       LEDS.show();// отослать команду
    ledmods();
  }
  
 }
 ///////////////////
               
      }


















