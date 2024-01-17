#include <iostream> 
#include <fstream> 
#include <map> 
#include <string> 
#include <memory>
#include "DATA_PROCESSING.h"
#include <FL/fl_ask.H>


#include <json/json.h>
#include <json/value.h>

setup::setup(){
    serialValues["latitude"] = 0.0; 
    serialValues["longitude"] = 0.0; 
    serialValues["elevation"] = 0.0; 
    serialValues["accel_x"] = 0.0; 
    serialValues["accel_y"] = 0.0; 
    serialValues["accel_z"] = 0.0; 
    serialValues["gyro_x"] = 0.0; 
    serialValues["gyro_y"] = 0.0; 
    serialValues["gyro_z"] = 0.0; 
    serialValues["mag_x"] = 0.0; 
    serialValues["mag_y"] = 0.0; 
    serialValues["mag_z"] = 0.0; 
    serialValues["temp"] = 100.0;  
}

void setup::serialRead(){
     #ifndef WIRING_PI

        #include <wiringPi.h> 
        #include <wiringSerial.h> 

        wiringPiSetupGpio();

    #endif
}

void setup::jsonStringToMap(const std::string& jsonString) {

    Json::Reader reader;
  Json::Value root;

  bool parseSuccess = reader.parse(jsonString, root, false);

  if (parseSuccess)
  {
    fl_message("parsing successful"); 
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
