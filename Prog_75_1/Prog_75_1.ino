#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX
String W =" "; 
char w ;

void setup()
   { 
     Serial.begin(115200);
     BT1.begin(115200); 
     pinMode(12, OUTPUT);
     pinMode(11, OUTPUT); // defino el relé de la luz del living
     pinMode(10, OUTPUT); // defino el relé de la fiesta!!!
     pinMode(9, OUTPUT);
     delay(5000);
     BT1.println("AT+CIPSERVER=1,80");
   }

void loop()
   { 
     if (BT1.available())        // Lo que entra por WIFI - Serial
         { w = BT1.read() ;
           Serial.print(w);      // Vamos montando un String con lo que entra
           W = W + w ;
         }
     if (Serial.available())    // Lo que entra por Serial - WIFI
          {  char s = Serial.read();
             BT1.print(s);
          }
    if ( w == '\n')                     // Sin han pulsado intro
       { if ( W.indexOf("12?0") > 0 )
             { digitalWrite(12, LOW) ;
               Serial.println("Invirtiendo pin 12");
             }
         if ( W.indexOf("12?1") > 0 )
             { digitalWrite(12, HIGH) ;   
               Serial.println("Invirtiendo pin 12");
             }
         W = "" ;  w = ' ' ;
       }
}


