#include <SPI.h>
#include <LoRa.h>

// LoRa pin definitions for ESP8266
#define SS      15
#define RST     16
#define DIO0    5

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(???)) {  // Use 433E6 for 433 MHz module
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = ?????;
  if (packetSize) {
    // received a packet
    Serial.print("Received packet: ");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI (signal strength)
    Serial.print(" with RSSI ");
    Serial.println(???????);
  }
}
