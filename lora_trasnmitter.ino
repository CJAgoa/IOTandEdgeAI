#include <SPI.h>
#include <LoRa.h>

#define SS 15    // D8
#define RST 16   // D0
#define DIO0 5   // D1
int pot = ??;


void setup() {
  Serial.begin(9600);
  pinMode(pot,INPUT);
  while (!Serial);

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(????)) {  // for 433 MHz module
    Serial.println("LoRa init failed. Check connections.");
    while (true);
  }

  Serial.println("LoRa init succeeded.");
}

void loop() {
  int val = map(analogRead(pot),??????);
  LoRa.beginPacket();  
  LoRa.print(??);
  LoRa.endPacket();
  delay(3000);
}

