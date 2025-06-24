#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>


const char* ssid = "?????";
const char* password = "???????";
// MQTT Broker settings
const char* mqtt_server = "???????";  
const int mqtt_port = ???;
const char* mqtt_dist_topic = "????????";


WiFiClient espClient;
PubSubClient client(espClient);
String distance = "0.0";
void setup() {
  // Start serial for debugging
  Serial.begin(115200);
 
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
 // Initialize MQTT
  client.setServer(????, ?????);
  client.setCallback(mqttCallback); 
}
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';  // Null-terminate the payload
  String message = String((char*)payload);
 
  if (String(topic) == mqtt_dist_topic) {
    distance = message;  
    Serial.print("Distance: ");
    Serial.println(????);
  }
 
}
void reconnect() {
  // Loop until we're connected
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      client.subscribe(mqtt_dist_topic); 
    } else {
      delay(5000);
    }
  }
}
void loop() {
   if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
