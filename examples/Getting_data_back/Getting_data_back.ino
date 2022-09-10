//This example shows how to fetch data from hptech

#include <HpTech.h >
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password ="REPLACE_WITH_YOUR_PASSWORD";

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

hptechObject obj;                                // creating an object

obj.setKey("REPLACE_WITH_YOUR_SECRET_KEY");     // set project secret key
Serial.println(obj.getJson()) ;                //getting data from server  
String field="DATA";
String val=obj.extract(field);                // extracting a particular field from Fetched data;       
Serial.println("excrated value is");
Serial.println(val);

} 
void loop() { 
  // write your loop code here
  
  }
