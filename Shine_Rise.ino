#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#include <TinyRTClib.h>
#include <Adafruit_NeoPixel.h> 
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib


 
RTC_DS1307 rtc;
#define PIN 3
#define START_MINUTE 54
uint8_t alarm = 18;
// 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);


void setup () {
    //Serial.begin(57600);
    strip.begin();
    strip.show(); 
    //Wire.begin();
    //RTC.begin();
    TinyWireM.begin(); // Begin I2C 
    rtc.begin(); // Begin DS1307 real time clock
 //  if (! RTC.isrunning()) {
//    Serial.println("RTC is NOT running!");
 // following line sets the RTC to the date & time this sketch was compiled
rtc.adjust(DateTime(__DATE__, __TIME__));
} 
 

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//


//

 void loop () {
    DateTime now = rtc.now();
    uint8_t minute = now.minute();
    if(now.hour() == alarm) {
       if(now.minute() >= START_MINUTE && now.minute() < START_MINUTE+2 ) {
       
        
       colorWipe(strip.Color(10, 5, 10), 10); 
       
       colorWipe(strip.Color(5, 0, 15), 50); 
       colorWipe(strip.Color(10, 0, 30), 100); 
       colorWipe(strip.Color(15, 0, 45), 200); 
       colorWipe(strip.Color(20, 0, 60), 300); 
       colorWipe(strip.Color(30, 0, 80), 400); 
       
       
       colorWipe(strip.Color(40, 0, 100), 400);
        
       colorWipe(strip.Color(60, 0, 100), 100); 
       colorWipe(strip.Color(80, 0, 90), 150); 
       colorWipe(strip.Color(100, 20, 70), 200);  
       colorWipe(strip.Color(110, 40, 40), 300); 
       
       colorWipe(strip.Color(110, 60, 20), 500);
       
       colorWipe(strip.Color(110, 60, 0), 100); 
       colorWipe(strip.Color(120, 60, 10), 200); 
       colorWipe(strip.Color(130, 70, 10), 300); 
       colorWipe(strip.Color(130, 80, 10), 400); 
       
       colorWipe(strip.Color(130, 90, 10), 500);
      
       colorWipe(strip.Color(130, 100, 20), 50);
       colorWipe(strip.Color(130, 110, 40), 100); 
       colorWipe(strip.Color(150, 120, 60), 200); 
       colorWipe(strip.Color(160, 130, 80), 300); 
       colorWipe(strip.Color(180, 150, 100), 400);
       
       colorWipe(strip.Color(180, 180, 180), 500);
        // Serial.println(now.minute(), DEC);
         
        
       }
       
      if(now.minute() >= START_MINUTE+2 && now.minute() < START_MINUTE+6) {
       // Serial.println("RainbowCycle"); 
        //colorWipe(strip.Color(10, 20, 30), 20);
        rainbowCycle(2);
        //colorWipe(strip.Color(10, 10, 10), 20); // clear out pixels
        //Serial.println(now.minute(), DEC);

      }
      
     if(now.minute() >= START_MINUTE+6 && now.minute() < START_MINUTE+9) {
     
         rainbow(100); 
        
     } 
       if(now.minute() >= START_MINUTE+9 && now.minute() < START_MINUTE+10) {
     
         colorWipe(strip.Color(250, 250, 00), 20); 
         colorWipe(strip.Color(0, 0, 0), 20);
         colorWipe(strip.Color(250, 0, 250), 20);
         colorWipe(strip.Color(0, 0, 0), 20);
         colorWipe(strip.Color(0, 250, 250), 20); 
         colorWipe(strip.Color(0, 0, 0), 20);
         colorWipe(strip.Color(250, 250, 250), 20); 
         colorWipe(strip.Color(0, 0, 0), 20); 
       
       
     } 
     
          if(now.minute() >= START_MINUTE+10 && now.minute() < START_MINUTE+11) {
            
        colorWipe(strip.Color(250, 250, 250), 20); 
         
    }
    
    
         if(now.minute() == START_MINUTE+11) {
       
         colorWipe(strip.Color(0, 0, 0), 20); 

         strip.show();
     }
     
    } 
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.println();
    delay(300);
}
