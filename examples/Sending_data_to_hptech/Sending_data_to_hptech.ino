// This example shows how we can send data to -->HpTech<---

#include <HpTech.h >
const char* ssid = "REPALCE_WITH_YOUR_SSID";
const char* password ="REPALCE_WITH_YOUR_PASSWORD";

void setup() {
Serial.begin(115200);

WiFi.mode(WIFI_AP_STA);
WiFi.begin(ssid, password);
Serial.print("Connecting to WiFi ..");
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
Serial.print('.');
}
Serial.println(WiFi.localIP());
Serial.println("Setup done");

hptechObject obj;

obj.setKey("REPLACE_WITH_YOUR_SECRET_KEY");       // set project secret key,(without this you can't communicate with HpTech)

obj.pack("field_name","field_value");        // packing data

obj.sendJson();                             // sending data 

} void loop() { }
