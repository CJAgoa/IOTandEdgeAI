#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// DHT11 sensor setup
#define DHTPIN ??        
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi credentials
const char* ssid = "???";           
const char* password = "????";   

// MQTT Broker settings
const char* mqtt_server = "??????";  
WiFiClient espClient;
PubSubClient client(espClient);

// Setup Wi-Fi connection
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin(??, ????);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
}

// MQTT reconnect function
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Connected to MQTT Broker");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);  // Start Serial Monitor at 115200 baud rate
  dht.begin();           // Initialize the DHT11 sensor
  setup_wifi();          // Connect to Wi-Fi
  client.setServer(???, ????);  
}

void loop() {
  if (!client.connected()) {
    reconnect();  // Reconnect to the MQTT broker if disconnected
  }
  
  client.loop();  // Keep the connection alive
  
  // Read temperature and humidity from DHT11 sensor
  float temperature = dht.readTemperature();  // Get temperature in Celsius
  float humidity = dht.readHumidity();       // Get humidity percentage
  
  // Check if reading was successful
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Convert temperature and humidity to strings
  char temp_str[8];
  char hum_str[8];
  dtostrf(temperature, 1, 2, temp_str);  // Convert temperature float to string
  dtostrf(humidity, 1, 2, hum_str);     // Convert humidity float to string

  client.publish("?????????", ?????);  
  client.publish("???????????", ?????);     
  
  delay(10000);  // Wait for 5 seconds before sending the next data
}

