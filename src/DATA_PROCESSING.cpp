#include <iostream> 
#include <fstream> 
#include <map> 
#include <string> 
#include <memory>
#include "DATA_PROCESSING.h"
#include <FL/fl_ask.H>

#include <json/json.h>
#include <json/value.h>

    std::map <std::string, double> setup::serialValues;
 
setup::setup(){
}

std::string setup::serialRead(){
    std::string jsonString; 

     #ifndef WIRING_PI

        #include <wiringPi.h> 
        #include <wiringSerial.h> 

        wiringPiSetup();

        int serialPort;

        jsonString.clear(); 

        // Open the serial port (adjust the port name and baud rate as needed)
        if ((serialPort = serialOpen("/dev/ttyS0", 9600)) < 0) {
            std::cout << "Unable to open serial port\n" << std::endl;
        }
        // Read serial data and store it in a string
        char incomingChar;

        while (true) {
            if (jsonString.length() < 255) {  // Limit the string length to avoid overflow

                // Read character by character until a newline character is encountered
                while ((incomingChar = serialGetchar(serialPort)) != '\n') {
                    jsonString += incomingChar;
                }
            } else {
                // Handle the case where the string is too long
                std::cout << "Received data is too long, clearing buffer\n";
                jsonString.clear();
            }
        }

        // Close the serial port (this will never be reached in this example)
        serialClose(serialPort);

    #endif

    return jsonString; 
}

void setup::jsonStringToMap(const std::string& jsonString) {

    Json::Reader reader;
    Json::Value root;

  bool parseSuccess = reader.parse(jsonString, root, false);

  if (parseSuccess)
  {
    serialValues["latitude"] = root["latitude"].asDouble(); 
    serialValues["longitude"] = root["longitude"].asDouble(); 
    serialValues["elevation"] = root["elevation"].asDouble(); 
    serialValues["accel_x"] = root["accel_x"].asDouble(); 
    serialValues["accel_y"] = root["accel_y"].asDouble(); 
    serialValues["accel_z"] =root["accel_z"].asDouble(); 
    serialValues["gyro_x"] = root["gyro_x"].asDouble(); 
    serialValues["gyro_y"] = root["gyro_y"].asDouble(); 
    serialValues["gyro_z"] = root["gyro_z"].asDouble(); 
    serialValues["mag_x"] = root["mag_x"].asDouble(); 
    serialValues["mag_y"] = root["mag_y"].asDouble(); 
    serialValues["mag_z"] = root["mag_z"].asDouble(); 
    serialValues["temp"] = root["temp"].asDouble(); 
  }
}
