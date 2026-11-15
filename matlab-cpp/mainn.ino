//#include <arduino.h>
#include "opkene_main.h"
#include "app_main.h"
#include <fnmatch.h>
//#include "Matrix_Import_From_TXT.h"
//#include "opkene.h"
#include <FS.h>
#include <SPIFFS.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif defined ESP32
#include <WiFi.h>
#include "SPIFFS.h"
#endif

#include "ESP8266FtpServer.h"

const char* ssid = "REPLACE_SSID";
const char* password = "REPLACE_PASSWORD";


FtpServer ftpSrv;   //set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial

#define FORMAT_SPIFFS_IF_FAILED true

void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
    Serial.printf("Listing directory: %s\r\n", dirname);

    File root = fs.open(dirname);
    if(!root){
        Serial.println("- failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println(" - not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels -1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("\tSIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}
void setup() {

  Serial.begin(115200);
WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  /////FTP Setup, ensure SPIFFS is started before ftp;  /////////
  /////FTP Setup, ensure SPIFFS is started before ftp;  /////////
#ifdef ESP32       //esp32 we send true to format spiffs if cannot mount
  if (SPIFFS.begin(true)) {
#elif defined ESP8266
  if (SPIFFS.begin()) {
#endif
      Serial.println("SPIFFS opened!");
      ftpSrv.begin("REPLACE_FTP_USER","REPLACE_FTP_PASSWORD");    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
  }    

  
  if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
        Serial.println("SPIFFS Mount Failed");
        return;
    }
  Serial.println("sonuc");
  //Serial.println("kkkk");
  listDir(SPIFFS, "/", 0);
   opkene_main();

  listDir(SPIFFS, "/", 0);

}
void loop() {
ftpSrv.handleFTP();        //make sure in loop you call handleFTP()!!  
// server.handleClient();   //example if running a webserver you still need to call .handleClient();
}
