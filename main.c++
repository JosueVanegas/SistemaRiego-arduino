#include <DHT.h>
#define bomba 3
#define fotoResistencia A0
#define sensorAmbiente 2
#define sensorHumedad A2
#define DHTTYPE DHT11
DHT dht(sensorAmbiente, DHTTYPE);
void setup() {
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  dht.begin();
}

void loop() {
  int valorFotoResistencia = analogRead(fotoResistencia)-1000;
  int valorSensorHumedad = analogRead(sensorHumedad);
  float temperatura = dht.readTemperature();
  Serial.println(temperatura);
  Serial.println(valorSensorHumedad);
  Serial.println(valorFotoResistencia);
  if (temperatura <=32 && valorFotoResistencia <= 19 && valorSensorHumedad >=800 ) {
   digitalWrite(bomba, HIGH);
   Serial.print("regando");
   delay(5000);
   digitalWrite(bomba, LOW);
 }
  delay(2000);
}
