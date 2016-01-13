#include "SoftwareSerial.h"
SoftwareSerial BT1(3, 2); // RX | TX

void setup(){
  int index = 0;
     while(ordenes[index] != "END")
        {  WIFI1.println(ordenes[index++]);
           while ( true)
              {   String s = GetLineWIFI();
                  if ( s!= "") Serial.println(s);
                  if ( s.startsWith("no change"))  
                          break;
                  if ( s.startsWith("OK"))  
                          break;
                  if ( s.startsWith("ready"))  
                         break;
                  // if (millis()-T >10000) break; 
              }
          Serial.println("....................");
      }
  }

void loop()
  {  String B= "." ;
     if (BT1.available())
         { char c = BT1.read() ;
           Serial.print(c);
         }
     if (Serial.available())
         {  char c = Serial.read();
            BT1.print(c);
         }
   }
