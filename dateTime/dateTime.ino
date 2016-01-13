#include <Wire.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <DS1307RTC.h>
void setup() {
  Serial.begin(115200);
  pinMode(12, OUTPUT); // defino el relé de la luz del balcon
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");
  Alarm.alarmRepeat(22,32,0, BalconOn);  // alarma diaria
  Alarm.alarmRepeat(07,47,0, BalconOff);  // alarma diaria
  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // alarma semanal
  Serial.println("Setup complete.");
}
void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000);
}
void BalconOn(){
  digitalWrite(12, HIGH);
  Serial.println("Encendiendo luz del balcon");
}
void BalconOff(){
  digitalWrite(12, LOW);    
  Serial.println("Apagando luz del balcon");
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
