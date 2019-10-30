#include <ESP8266WiFi.h>

// Initialize sensor parameters

// Initialize network parameters
const char* ssid = "VaaYS";
const char* password = "CLBKhoaHocTre2019";
const char* host = "192.168.11.4"; // as specified in Host.ino
const int httpPort = 80;
int text_send ;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Connecting to Network");
  WiFi.mode(WIFI_STA);                      // Mode Station
  WiFi.begin(ssid, password);               // Matching the SSID and Password
  delay(1000);

  // Waiting to connect to wifi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Status : Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("-------------------------------------");
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(host);
}
void loop() {
  sent_text();
  delay(200);
}
void sent_text()
{
  int data_assignment = 0;
  WiFiClient client;
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  if (Serial.available()) {
    text_send = Serial.read();
    if (text_send == '1')
    {
      data_assignment = 1;
    }
    else if (text_send == '2')
    {
      data_assignment = 2;
    }
    else if (text_send == '3')
    {
      data_assignment = 3;
    }
    else if (text_send == '4')
    {
      data_assignment = 4;
    }
    else {
      data_assignment = 0;
    }
  }
  if (data_assignment == 1)
  {
    //  Serial.print("Long");
    client.println("Up");
  }
  else if (data_assignment == 2)
  {
    client.println("Down");
  }
  else if (data_assignment == 3)
  {
    client.println("Right");
  }
  else if (data_assignment == 4)
  {
    client.println("Left");
  }
  client.println("Null");
}
