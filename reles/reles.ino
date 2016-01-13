void setup()
{
// Indicamos el pin que va a activar o desactivar la bobina del relé
pinMode(8, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
}
void loop()
{
//Ojo las bobinas de los relés se activan cuando a las entradas del módulo tienen GND
digitalWrite(12, HIGH);
delay(1000);
digitalWrite(12, LOW); // Activamos la bobina del relé
delay(1000);
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW); // Activamos la bobina del relé
delay(1000);
digitalWrite(10, HIGH);
delay(1000);
digitalWrite(10, LOW); // Activamos la bobina del relé
delay(1000);
digitalWrite(9, HIGH);
delay(1000);
digitalWrite(9, LOW); // Activamos la bobina del relé
delay(1000);
}
