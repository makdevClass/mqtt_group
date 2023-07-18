/*

 Basic MQTT example

 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-mqtt-upload-listen/
 */

#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

char ssid[] = "Studio5G";     // your network SSID (name)
char pass[] = "mykevin630529";  // your network password
int status  = WL_IDLE_STATUS;    // the Wifi radio's status

char mqttServer[]     = "broker.hivemq.com";
char clientId[]       = "amebaClient";
char publishTopic[]   = "outTopic/319";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
char payload[500];
int x;

void sendMQTT()
{
  if (!mqttClient.connected()) {
      Serial.println("Attempting MQTT connection");
      mqttClient.connect(clientId);  
  }

    if (mqttClient.connected()) {
        sprintf(payload,"TEST[%d]",x);
        mqttClient.publish(publishTopic, payload);
    }  

}

void reconnectWiFi()
{
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }
}

void setup() {
    Serial.begin(115200);
    reconnectWiFi();

    mqttClient.setServer(mqttServer, 1883);

    // Allow the hardware to sort itself out
    delay(1500);
}

void loop() {

    reconnectWiFi();
    sendMQTT();
    mqttClient.loop();
    delay(5000);
    x++;
}
