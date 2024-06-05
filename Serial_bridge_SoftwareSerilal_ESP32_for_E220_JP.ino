/*
Serial bridge for E220-900T22S-JP Config read 

E220 is connected via softwware serial (port name: LoraSer)
espsoftwareserial : https://github.com/plerup/espsoftwareserial/

PLatform is Wemos D1 mini ESP32
HarwareSerial can be used as Serial2

For binary data transfer, use RS232 TEST tools
http://nonsoft.la.coocan.jp/Download/Rs232cTool/index.html


Jay Teramoto 2024.6.5 (Comp)
*/

#include <SoftwareSerial.h>
#define M0pin D5
#define M1pin D6
#define Tx    D7
#define Rx    D8
SoftwareSerial LoraSer(Tx,Rx);

void setup() {

  pinMode(M0pin,OUTPUT);
  pinMode(M1pin,OUTPUT);
  digitalWrite(M0pin,HIGH);
  digitalWrite(M1pin,HIGH);
  
  Serial.begin(9600);
  LoraSer.begin(9600);
  Serial.println("E220 Config read/write via SoftwareSerial on ESP32 ");

}

void loop() {

  while (LoraSer.available()) {
    Serial.print(char(LoraSer.read()));
  }
  while (Serial.available()) {
    LoraSer.print(char(Serial.read()));
  }
}
