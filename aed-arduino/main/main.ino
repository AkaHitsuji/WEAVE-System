#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

int led = 2;
int alarm = 14;
int trigger = 0;

const char* ssid = "AndroidAP";
const char* password = "dysonintern";

void setup() 
{
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(alarm,OUTPUT);
  connectWifi();
}

void loop() 
{
  if(trigger == 1){
    digitalWrite(alarm,HIGH);
    Serial.println("ALARM!!");
  }
  else if(trigger == 0){
    digitalWrite(alarm,LOW);
    Serial.println("Alarm off.");
  }
  
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http; //Object of class HTTPClient
    Serial.println("HTTP begin.");
    http.begin("http://192.168.43.217:5000/switch");
    Serial.println("Calling GET method.");
    int httpCode = http.GET();
    Serial.print("HTTP code:");
    Serial.println(httpCode);

    if (httpCode == 200) 
    {
      digitalWrite(led,LOW);
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());

      Serial.println("Parsing json...");
      int id = root["id"];
      int switchVal = root["switch"]; 
      Serial.print("Switch on:");
      Serial.println(switchVal);

      trigger = switchVal;

      Serial.println("End of parse.");
    }

    else{
      digitalWrite(led,LOW);
      delay(500);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
      digitalWrite(led,HIGH);
    }
    
    http.end(); //Close connection
    delay(2000);
  }
  
  else
  {
    connectWifi();    
  }
}

void connectWifi(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    digitalWrite(led,HIGH);
    delay(5000);
    Serial.println("Connecting...");    
  }
  digitalWrite(led,LOW);
}
