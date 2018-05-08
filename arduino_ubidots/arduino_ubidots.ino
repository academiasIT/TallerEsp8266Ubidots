#include <Arduino.h>

#include "UbidotsMicroESP8266.h"
#include "DHT.h"

#define TOKEN  ""  // Ubidots TOKEN
#define ID_T "" // Temperatura ID 
#define ID_H "" // Humedad ID
#define ID_SL ""// led ID 

#define WIFISSID "essid" //Wi-Fi SSID
#define PASSWORD "passwd" //Wi-Fi password

#define DHTPIN 2 //pin en donde se conectara el pin de datos del sensor DHT11
#define DHTYPE DHT11 //tipo de sensor DHT11

#define LAMP 5//pin en donde se conectara el led

DHT dht(DHTPIN, DHTYPE);
Ubidots client(TOKEN);

void setup() {
  // put your setup code here, to run once:
  pinMode(LAMP,OUTPUT);
  pinMode(DHTPIN,INPUT);
  digitalWrite(LAMP,HIGH);
  
  Serial.begin(115200);
  client.wifiConnection(WIFISSID, PASSWORD);
  
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if(isnan(t) || isnan(h)){
    Serial.println("Error al leer el sensor DHT 11");
  }else{
    Serial.print("Temp: ");
    Serial.println(t);
    Serial.print("Humedad: ");
    Serial.println(h);

    client.add(ID_T, t);
    client.add(ID_H, h);

    client.sendAll(false);
  }
  
  float swLamp = client.getValue(ID_SL);
  Serial.print(swLamp);
  if(swLamp==1.0){
    Serial.println("Led on");
    digitalWrite(LAMP,LOW);
  } else {
    Serial.println("Led off");
    digitalWrite(LAMP,HIGH);
  }
  
  delay(3000);
}
