#include <ArduinoJson.h>


void setup() {
  // put your setup code here, to run once:
  //DynamicJsonDocument  doc(1024);
  StaticJsonDocument<400> doc;
  String OutString;

  Serial.begin(115200);
  
  doc["name"] = "Alice";
  doc["age"] = 25;
  doc["isStudent"] = true;

  JsonArray hobbies = doc.createNestedArray("hobbies");
  hobbies.add("reading");
  hobbies.add("painting");
  hobbies.add("hiking");

  JsonObject address = doc.createNestedObject("address");
  address["street"] = "456 Elm St";
  address["city"] = "Los Angeles";
  address["country"] = "USA";
  doc["favoriteFoods"] = nullptr;

  serializeJson(doc, OutString);
  Serial.print("SerialOut: ");
  Serial.println(OutString);

  /*
   SerialOut:
   {"name":"Alice","age":25,"isStudent":1,"hobbies":["reading","painting","hiking"],"address":{"street":"456 Elm St","city":"Los Angeles","country":"USA"},"favoriteFoods":null}
  */
}

void loop() {
  // put your main code here, to run repeatedly:

}
