#include <Wire.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <DS1307RTC.h>
#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX
String W =" "; 
char w ;
String ordenesESP8266[]=
  {  "AT+CWMODE=3",
     "AT+CWQAP",
     "AT+CWJAP=\"charly\",\"contrase\"",
     "AT+CIFSR" ,
     "AT+CIPMUX=1",
     "AT+CIPSERVER=1,80",
     "AT+CIPSTA?",
     "END"                 // Para reconocer el fin de los comandos AT
  };
void setup() {
  Serial.begin(115200);
  BT1.begin(115200);
  pinMode(12, OUTPUT); // defino el relé de la luz del balcon
  pinMode(11, OUTPUT); // defino el relé de la luz del living
  pinMode(10, OUTPUT); // defino el relé de la fiesta!!!
  pinMode(9, OUTPUT); // defino el relé de la valvula de riego
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");
  delay(5000);
  BT1.println("AT+CIPSTA?");
  delay(1000);
  BT1.println("AT+CIPMUX=1");
  delay(1000);
  BT1.println("AT+CIPSERVER=1,24576"); // levanta el server del ESP8266
  delay(1000);
  Alarm.alarmRepeat(00,32,0, BalconOn);  // alarma diaria
  Alarm.alarmRepeat(07,47,0, BalconOff);  // alarma diaria
  //Alarm.alarmRepeat(19,49,0, LivingOn);  // alarma diaria
  //Alarm.alarmRepeat(23,50,0, LivingOff);  // alarma diaria
  //Alarm.alarmRepeat(20,03,0, Regar);  // alarma diaria
  //Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // alarma semanal
  Serial.println("Setup complete.");
}
void  loop(){  
  //digitalClockDisplay();
  Alarm.delay(0);
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
       { if ( W.indexOf("ba") > 0 )
             Balcon();
         if ( W.indexOf("li") > 0 )
             Living();
         if ( W.indexOf("pa") > 0 )
             Party();
         W = "" ;  w = ' ' ;
       }
}
void Balcon(){
  digitalWrite(12, !digitalRead(12));
  Serial.println("Invirtiendo luz del balcon");
}
void BalconOn(){
  digitalWrite(12, HIGH);
  Serial.println("Encendiendo luz del balcon");
}
void BalconOff(){
  digitalWrite(12, LOW);    
  Serial.println("Apagando luz del balcon");
}
void Living(){
  digitalWrite(11, !digitalRead(11));
  Serial.println("Invirtiendo luz del living");
}
void LivingOn(){
  digitalWrite(11, HIGH);
  Serial.println("Encendiendo luz del living");
}
void LivingOff(){
  digitalWrite(11, LOW);    
  Serial.println("Apagando luz del living");
}
void Regar(){
  digitalWrite(9, HIGH);
  Serial.println("Abriendo valvula de riego por 5 minutos");
  delay(5*60000);
  digitalWrite(9, LOW);
  Serial.println("Cerrando valvula de riego");
}
void Party(){
  digitalWrite(10, HIGH);
  Serial.println("PARTY TIME!!!!!!");
  delay(15000);
  digitalWrite(10, LOW);
}
void WeeklyAlarm(){
  Serial.println("Alarm: - its Monday Morning");      
}
void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year()); 
  Serial.print(" ");
  printDays(weekday());
  Serial.println(); 
}
void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
void printDays(int weekday){
  // utility function for digital clock display: prints the day of the week
  switch(weekday){
  case 1:
    Serial.print("Domingo");
    break;
  case 2:
    Serial.print("Lunes");
    break;
  case 3:
    Serial.print("Martes");
    break;
  case 4:
    Serial.print("Miercoles");
    break;
  case 5:
    Serial.print("Jueves");
    break;
  case 6:
    Serial.print("Viernes");
    break;
  case 7:
    Serial.print("Sabado");
    break;
  }
}
