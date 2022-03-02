#include <Adafruit_NeoPixel.h>
#include <math.h>

#include <SPFD5408_Adafruit_GFX.h>    
#include <SPFD5408_Adafruit_TFTLCD.h> 
#include <SPFD5408_TouchScreen.h>


#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

#define YP A3  
#define XM A2  
#define YM 9   
#define XP 8  

#define PIN 21
#define NUM_LEDS 165
#define BRIGHTNESS 100

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

#define LCD_RESET A4

#define  BLACK  0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void  EmitCyan();
void  EmitWhite();
void  EmitGreen();
void  EmitYellow();
void  EmitPink();
void  EmitBlack();

uint16_t width = 0;
uint16_t height = 0;
uint16_t x = 40;
uint16_t y = height - 20;
uint16_t w = 75;
uint16_t h = 20;

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#define BOXSIZE 40
#define PENRADIUS 3
#define BUTTONS 9
#define BUTTON_Red 0
#define BUTTON_DarkRed 1
#define BUTTON_RED 2
#define BUTTON_DarkGreen 3
#define BUTTON_DeepRed 4
#define BUTTON_Blue 5
#define BUTTON_LightBlue 6
#define BUTTON_LightBlue1 7

Adafruit_GFX_Button buttons[BUTTONS];

uint16_t buttons_y = 0;
#define MINPRESSURE 10
#define MAXPRESSURE 1000

void setup() {
  
  Serial.begin(9600);
  Serial.println(F("Paint!"));
  tft.reset();
  tft.begin(0x9341); // SDFP5408
  strip.begin();
  strip.show(); 
  tft.setRotation(0); 
  tft.fillScreen(BLACK);
  tft.setCursor (40, 20);
  tft.setTextSize (3);
  tft.setTextColor(WHITE);
  tft.println("CiferTech");
  tft.setCursor (65, 85);
  width = tft.width() - 1;
  height = tft.height() - 100;
  initializeButtons();
  showCalibration();
}

void loop() {
  
  int i = 0;
  TSPoint p;
  
  digitalWrite(13, HIGH);
  p = waitOneTouch();
  digitalWrite(13, LOW);
  p.x = mapXValue(p);
  p.y = mapYValue(p);

  for (uint8_t b = 0; b <BUTTONS; b++) {

    if (buttons[b].contains(p.x, p.y)) {

    switch  (b) {
    case BUTTON_Red:
        EmitPink();
        showCalibration();
      break;

    case BUTTON_DarkRed:
        EmitCyan();
        showCalibration();
      break;
      
    case BUTTON_RED:
        EmitBlack();
        showCalibration();
      break;
      
    case BUTTON_DarkGreen:
        EmitGreen();
        showCalibration();
      break;
 
    case BUTTON_Blue:
       EmitBlue();
       showCalibration();
      break;
      
    case BUTTON_LightBlue:     
       EmitYellow();
       showCalibration();    
      break;
      
    case BUTTON_DeepRed:    
       EmitDeepRed();       
       showCalibration();         
      break;
    }
  }
}
}
void initializeButtons() {

  uint16_t x = 40;
  uint16_t y = height - 20;
  uint16_t w = 75;
  uint16_t h = 40;
  uint8_t spacing_x = 5;
  uint8_t textSize = 2;

  char buttonlabels[7][20] = {"", "", "", "", "", "", ""};
  uint16_t buttoncolors[15] = {MAGENTA, CYAN, WHITE, GREEN, RED, BLUE, YELLOW};

  for (uint8_t b = 0; b < 9; b++) {
    if (b < 3)
    {
      buttons[b].initButton(&tft,           
       x + b * (w + spacing_x), y,           
       w, h, BLACK, buttoncolors[b], WHITE,  
       buttonlabels[b], textSize);
      Serial.print(  h);
      
    }// text
    if (b == 3)
    {
      uint16_t x = 40;
      uint16_t y = height + 30 ;
      uint16_t w = 75;
      uint16_t h = 40;

      buttons[b].initButton(&tft,          
      x + 0 * (w + spacing_x) , y,          
      w, h, BLACK, buttoncolors[b], WHITE,  
      buttonlabels[b], textSize);
    }
    if (b == 4)
    {
      uint16_t x = 40;
      uint16_t y = height + 30 ;
      uint16_t w = 75;
      uint16_t h = 40;

      buttons[b].initButton(&tft,             
        x + 1 * (w + spacing_x) , y,         
        w, h, BLACK, buttoncolors[b], WHITE,  
        buttonlabels[b], textSize);
    }
    if (b == 5)
    {
      uint16_t x = 40;
      uint16_t y = height + 30 ;
      uint16_t w = 75;
      uint16_t h = 40;

      buttons[b].initButton(&tft,           
       x + 2 * (w + spacing_x) , y,         
       w, h, BLACK, buttoncolors[b], WHITE, 
       buttonlabels[b], textSize);
    }
    if (b == 6)
    {
      uint16_t x = 120;
      uint16_t y = height + 80 ;
      uint16_t w = 230;
      uint16_t h = 40;

      buttons[b].initButton(&tft,           
       x + 0 * (w + spacing_x) , y,         
       w, h,BLACK, buttoncolors[b], WHITE,  
       buttonlabels[b], textSize);
    }
    if (b == 7)
    {
      uint16_t x = 1000;
      uint16_t y = 1000 ;
      uint16_t w = 0;
      uint16_t h = 0;
      buttons[b].initButton(&tft,           
       x + 2 * (w + spacing_x) , y,         
       w, h,BLACK, buttoncolors[b], WHITE,  
       buttonlabels[b], 0);
    }
  }
   buttons_y = y;
}

// Map the coordinate X
uint16_t mapXValue(TSPoint p) {
  uint16_t x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
  //x+=1;
  return x;
}
uint16_t mapYValue(TSPoint p) {

  uint16_t y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
  //y-=2;
  return y;
}
TSPoint waitOneTouch() {
  TSPoint p;
  do {
    p = ts.getPoint();
    pinMode(XM, OUTPUT); 
    pinMode(YP, OUTPUT);
  } while ((p.z < MINPRESSURE ) || (p.z > MAXPRESSURE));
  return p;
}
void showCalibration() {
  tft.setCursor (40, 0);   
      for (uint8_t i = 0; i < 8; i++) {
        buttons[i].drawButton();
    }
  }

void  EmitDeepRed()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i, 255, 0, 0);
  strip.show();
  }
}
void  EmitCyan()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,0, 255, 255);
  strip.show();
  }
}
void  EmitWhite()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,255, 255, 255);
  strip.show();
  }
}
void  EmitGreen()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,0, 255, 0);
  strip.show();
  }
}
void  EmitBlue()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,0, 0, 255);
  strip.show();
  }
}
void  EmitYellow()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,255, 255, 0);
  strip.show();
  }
}
void  EmitPink()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,255, 0, 255);
  strip.show();
  }
}
void  EmitBlack()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
  strip. setPixelColor(i,255, 255, 255);
  strip.show();
  }
}
