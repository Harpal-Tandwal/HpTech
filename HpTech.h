//objective of this library:- easy communiction with hptech server




//member function:
//                 1. pack() =>to wrap key value pairs into a JSON OBJECT
 //                2  POST()=> TO SEND DATA TO HPTECH SERVER
 //                3. GET()=> TO FETCH DATA FROM HP TECH SERVER   
     



#ifndef HPTECH_H
#define HPTECH_H

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include"Arduino.h"

class hptechObject{
  
  private:
  
          StaticJsonDocument<1024> doc;
		  StaticJsonDocument<1024> doc2;
		  JsonArray info= doc.createNestedArray("data");
          String servername="https://iot-backend-xvij.onrender.com";
          String KEY="";
         
 public:

          template <typename KEY,typename value> // adding keyvalue pair in static json documnt
          void pack(KEY key, value val)
          {StaticJsonDocument<100> tempDoc;
           tempDoc[key]=val;
           info.add(tempDoc);
          }
		  
		  

		  
              
           String lookInside();  //  RETURN  JSON STRING
           void sendJson();   //sending json to hptech server
           void setKey(String);
           String getJson();
           void clear();
		   String extract(String KEY);
 };
 #endif
