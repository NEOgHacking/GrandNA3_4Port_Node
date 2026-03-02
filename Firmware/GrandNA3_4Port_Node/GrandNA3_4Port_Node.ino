#include <SPI.h>
#include <Ethernet.h>
#include <ArtnetEther.h>
#include <DmxOutput.h>

// --- Configuration ---
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 };
IPAddress ip(192, 168, 1, 100); // Set to your network range

// --- Hardware Config ---
const int eth_cs = 29;
const int dmxOutPins[4] = {39, 35, 43, 47};
const int dmxEnPins[4]  = {38, 34, 42, 46};

// Global Artnet Object
ArtnetEtherReceiver artnet; 
uint8_t dmxBuffer[4][512];
DmxOutput dmxOut[4];

void setup() {
  // SPI1 Setup for RP2350
  SPI1.setRX(28);
  SPI1.setTX(31);
  SPI1.setSCK(30);
  
  Ethernet.init(eth_cs);
  Ethernet.begin(mac, ip);

  artnet.begin();

  // Subscribe to 4 Universes (Subnet 0, Universe 0-3)
  for (int i = 0; i < 4; i++) {
    artnet.subscribe(i, [i](const uint8_t* data, uint16_t size) {
      // Copy incoming Art-Net data to the buffer for Core 1 to use
      memcpy(dmxBuffer[i], data, size > 512 ? 512 : size);
    });
  }
}

void loop() {
  artnet.parse(); // Continuously check for Art-Net packets
}

// --- CORE 1: DMX Engine ---
void setup1() {
  for (int i = 0; i < 4; i++) {
    pinMode(dmxEnPins[i], OUTPUT);
    digitalWrite(dmxEnPins[i], HIGH); // Enable Transmit
    dmxOut[i].begin(dmxOutPins[i]);
  }
}

void loop1() {
  for (int i = 0; i < 4; i++) {
    dmxOut[i].write(dmxBuffer[i], 512);
  }
  delay(25); // Maintain ~40Hz
}