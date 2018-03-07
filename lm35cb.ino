#include <SevSeg.h>      //mengambil library SevSeg

SevSeg sevseg;

int refreshTime = 2000; //berapa lama tampilan akan berganti? 1000 = 1 Detik

unsigned long timer;
float celsius = 0, kelvin = 0, fahrenheit = 0;

void setup()
{
  Serial.begin(9600);
sevseg.Begin(1,2,3,4,5,6,7,8,9,10,11,12,13);      //untuk common katoda, ubah digit awal menjadi (0, 2, ….dst)
}

void loop()
{
sevseg.PrintOutput();
//untuk mengatur LM35 agar menampilkan derajat Celsius
celsius = (5.0 * analogRead(0) * 100.0) / 1024;

unsigned long mils=millis();
if (mils-timer>=refreshTime) {
timer=mils;
//Menampilkan ke 7 Segmen
sevseg.NewNum(celsius,(byte) 2);
Serial.println(celsius);

}
}
