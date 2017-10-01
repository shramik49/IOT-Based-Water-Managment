#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"
const int sensor = A0;
float water;
// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "nrdy5p4zss";
// Your network name and password.
char ssid[] = "DI-ext";
char password[] = "44332211";

void setup() {

  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
}
void loop() {
  water = analogRead(sensor);
   Serial.println(water);
  delay(100);
  Cayenne.run();
}
CAYENNE_OUT(V1)
{
    Cayenne.virtualWrite(V1, water);
}
