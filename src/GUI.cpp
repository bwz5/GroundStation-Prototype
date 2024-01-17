#include "GUI.h"
#include <FL/fl_ask.H>


          /**
     * The main event loop. Will read the serial data, update the serialValues map, both using 
     * the serialRead function, and then update the graphs/displays accordingly. 
    */
    void eventLoop(Fl_Widget* w, void* usrData){ 
        setup DataProcess; // read the serial data here and then update the graph accordingly 
        std::string jsonString = "{\"latitude\":0,\"longitude\":0,\"elevation\":100,\"accel_x\":0,\"accel_y\":0,\"accel_z\":0,\"gyro_x\":0,\"gyro_y\":0,\"gyro_z\":0,\"mag_x\":0,\"mag_y\":0,\"mag_z\":0,\"temp\":100}"; 
        DataProcess.jsonStringToMap(jsonString); 

        
    }
   
    GUI::GUI(int width, int height, const char* title) : window(width, height, title){
        
        altitudeChart = new Fl_Chart(0,0,WIDTH/2, HEIGHT/2-20, "Altitude"); // the altitude graph
        GPS = new GPS_BOX(WIDTH/2, HEIGHT/2); // the GPS 
        startButton = new Fl_Button(WIDTH-100,HEIGHT/2 + 80,100,50,"Start Read");  // the start button that begins reading sensor data 
        longitudeDisplay = new Fl_Text_Display(WIDTH-100,HEIGHT/2 + 200,100,50, "Longitude: "); // longitude and latitude displays
        latitudeDisplay = new Fl_Text_Display(WIDTH-100,HEIGHT/2 + 300,100,50, "Latitude: "); 
        tempChart = new Fl_Chart(0,HEIGHT/2,WIDTH/2 , HEIGHT/2-20, "Temperature"); // the temperature graph
        testBox = new Fl_Box(600,600,100,50,"test"); 

        startButton->callback(eventLoop);
    }
    void GUI::show() {
        window.show();
    }
    void GUI::end() {
        window.end(); 
    }