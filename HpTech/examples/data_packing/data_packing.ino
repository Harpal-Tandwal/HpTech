//this example shows how we can pack and clear our data
// FROM HpTech-version 1.0.0

#include <HpTech.h>
hptechObject  obj;

void setup() {
  Serial.begin(115200);

  obj.setKey("62fdb3f41846f14332fc614c");
  obj.pack("FIELD_1","VALUE_1");
  obj.pack("FIELD_2","VALUE_2");
  Serial.println(obj.lookInside());
  
  obj.clear();
  
  Serial.println("after clearing it becomes");
  obj.pack("FIELD_3","VALUE_3");
  Serial.println(obj.lookInside());
  
}

void loop() {
  

}
