#include"HpTech.h"

String hptechObject::lookInside(){
      String str;
      serializeJson(doc,str);
      return str;
      }  

void hptechObject::sendJson(){
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      const char* server="https://hptech25.herokuapp.com/espsave";
      String json;
      serializeJson(doc,json);
      http.begin(server);
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST(json);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      http.end();
    
    }else{
      
      Serial.println("NOT CONNECTED TO INTERNET");
      }  
    
} 

void hptechObject::setKey(String key)
                    {doc["key"]=key;
                    KEY=key;
                    }

String hptechObject::getJson(){
	 doc2.clear();
	 JsonArray arr_doc2 = doc2.to<JsonArray>();
     String REQ= "{\"key\":\"" + KEY +"\"}";
     char * serverName = "https://hptech25.herokuapp.com/project_status";
     HTTPClient http;
     http.begin(serverName);
     http.addHeader("Content-Type", "application/json"); // HEADER FOR JSON POST-REQUESTS
     String key=doc["key"];
     int httpResponseCode = http.POST(REQ);          // POSTING JSON DATA
   
    if (httpResponseCode  > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode );
    String json = http.getString();
	json.remove(0,1);               // REMOVING '[' FROM STARTIG POSITION...another way => use jSONarray 
    json.remove(-1,1);
	StaticJsonDocument<512> data;
    deserializeJson(data, json);
    String info= data["info"]; 
    data.clear();
    deserializeJson(data,info);
  
	JsonArray inforoot = data.as<JsonArray>();//
	  //******************     
    for (JsonObject a : inforoot) 
	  {                 //  
          StaticJsonDocument <100> temp;
		  for (JsonPair kv : a) 
			 {
			  temp[kv.key()]=kv.value();
			  arr_doc2.add(temp);
			  temp.clear();
			  }
      }
    return info;
    }
   }

void hptechObject::clear(){
    doc.clear();
    doc["key"]=KEY;
   info= doc.createNestedArray("data");
     }

String hptechObject::extract(String KEY)
		  {
			 // serializeJson(doc2,Serial);
			//  Serial.println("extraction start...");
			 JsonArray inforoot = doc2.as<JsonArray>();//
	  //******************                             //
			  for (JsonObject a : inforoot) 
			  {                 //  
				 for (JsonPair kv : a)
					 {
				     String key=kv.key().c_str();
					 //Serial.print(key);
					 //Serial.print(":");
					 //Serial.println(KEY);
					 if(KEY==key)
				      { return kv.value();}
				    }
		     }
			 return "not found";
			 
	}	 
