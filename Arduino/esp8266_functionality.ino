
#define BLYNK_TEMPLATE_ID "TMPL3OxwiQO1S"
#define BLYNK_TEMPLATE_NAME "Temp Hum Moisture"
#define BLYNK_AUTH_TOKEN "JZKJLyCegLdweofausCFG0Sc4bPoK1A1"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mohan"; // Wifi name
char pass[] = "123456789"; // Wifi password

DHT dht(4, DHT11); // DHT11 on pin D4
BlynkTimer timer;

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(100L, sendSensor);
}

void sendSensor() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Blynk.virtualWrite(V0, h);
    Blynk.virtualWrite(V1, t);
}

void loop() {
    Blynk.run();
    timer.run();
}
