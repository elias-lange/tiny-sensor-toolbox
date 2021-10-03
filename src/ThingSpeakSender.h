#include <HTTPClient.h>
#include <WiFi.h>


class ThingSpeakSender {
 public:
  ThingSpeakSender(const char* ssid, const char* password, const char* apiKey)
   : ssid(ssid), password(password), apiKey(apiKey) {
    // Nothing to do.
  }

  bool sendMeasurement(String value1) {
    String url = String("https://api.thingspeak.com/update?api_key=") + String(apiKey) + String("&field1=") + value1;

    boolean success = false;
    WiFiClient client;
    WiFi.mode(WIFI_STA);
    LOG("Connecting to WiFi with SSID '%s' ...", ssid);
    WiFi.begin(ssid, password);
    delay(5000);

    if (WiFi.status() == WL_CONNECTED) {
      LOG("Sending to ThingSpeak ...");
      HTTPClient http;
      http.begin(url.c_str());
      int response = http.GET();
      if (response == 200) {
        success = true;
        LOG("Sent successfully.");
      } else {
        LOG("HTTP Error: %d.", response);
      }
      http.end();
    } else {
      LOG("No connection to WiFi with SSID '%s'.", ssid);
    }
    client.stop();
    return success;
  }

 private:
  const char* ssid;
  const char* password;
  const char* apiKey;
};