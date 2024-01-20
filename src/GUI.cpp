#include "GUI.h"
#include <FL/fl_ask.H>
#include <FL/Fl_Text_Buffer.H>

void GUI::graphCurrentPosition(){
        altitudeChart->insert(position, setup::serialValues["elevation"], (std::to_string(setup::serialValues["elevation"]).c_str())); 
        tempChart->insert(position, setup::serialValues["temp"], (std::to_string(setup::serialValues["temp"]).c_str())); 

        updateDisplays(); 

        position += 1; 
    }

    void GUI::updateDisplays(){
        longitudeBuffer.remove(0,10); 
        latitudeBuffer.remove(0,10); 
        tempBuffer.remove(0,10); 
        elevationBuffer.remove(0,10); 
        accel_x_Buffer.remove(0,10); 
        accel_y_Buffer.remove(0,10); 
        accel_z_Buffer.remove(0,10); 

        gyro_x_Buffer.remove(0,10); 
        gyro_y_Buffer.remove(0,10); 
        gyro_z_Buffer.remove(0,10);

        mag_x_Buffer.remove(0,10); 
        mag_y_Buffer.remove(0,10); 
        mag_z_Buffer.remove(0,10);

        longitudeBuffer.append((std::to_string(setup::serialValues["longitude"]).c_str())); 
        latitudeBuffer.append((std::to_string(setup::serialValues["latitude"]).c_str())); 
        tempBuffer.append((std::to_string(setup::serialValues["temp"]).c_str())); 
        elevationBuffer.append((std::to_string(setup::serialValues["elevation"]).c_str())); 
        accel_x_Buffer.append((std::to_string(setup::serialValues["accel_x"]).c_str())); 
        accel_y_Buffer.append((std::to_string(setup::serialValues["accel_y"]).c_str())); 
        accel_z_Buffer.append((std::to_string(setup::serialValues["accel_z"]).c_str())); 

        gyro_x_Buffer.append((std::to_string(setup::serialValues["gyro_x"]).c_str())); 
        gyro_y_Buffer.append((std::to_string(setup::serialValues["gyro_y"]).c_str())); 
        gyro_z_Buffer.append((std::to_string(setup::serialValues["gyro_z"]).c_str())); 

        mag_x_Buffer.append((std::to_string(setup::serialValues["mag_x"]).c_str())); 
        mag_y_Buffer.append((std::to_string(setup::serialValues["mag_y"]).c_str())); 
        mag_z_Buffer.append((std::to_string(setup::serialValues["mag_z"]).c_str())); 
        
    }

    /**
     * Will update the timer. 
    */
    void timerCallback(void*){
        Fl::repeat_timeout(1.0, timerCallback);
    }

    void inputCallback(Fl_Widget *widget, void *data) {
        Fl_Input *input = static_cast<Fl_Input*>(widget);
        const char *inputText = input->value();
        // Do something with the input text (e.g., print it)
        printf("Entered text: %s\n", inputText);
}

          /**
     * The main event loop. Will read the serial data, update the serialValues map, both using 
     * the serialRead function, and then update the graphs/displays accordingly. 
    */
    void GUI::eventLoop(){ 
        std::string jsonString = "{\"latitude\":0,\"longitude\":0,\"elevation\":10.5,\"accel_x\":0,\"accel_y\":0,\"accel_z\":0,\"gyro_x\":0,\"gyro_y\":0,\"gyro_z\":0,\"mag_x\":0,\"mag_y\":0,\"mag_z\":0,\"temp\":100}"; 
        setup::jsonStringToMap(jsonString); 
        Fl::add_timeout(1.0, timerCallback);  
 
        graphCurrentPosition(); 
    }

   
    GUI::GUI(int width, int height, const char* title) : window(width, height, title){ 

        input = new Fl_Input(WIDTH - 650, HEIGHT/2 + 200, 100, 30, "Enter Hybrid Command:");
        input->align(FL_ALIGN_TOP_LEFT);
        
        button = new Fl_Button(WIDTH - 650, HEIGHT/2 + 300, 100, 30, "Submit");
        button->callback(inputCallback, input);

        altitudeChart = new Fl_Chart(0,0,WIDTH/2, HEIGHT/2-20, "Elevation"); // the altitude graph

        GPS = new GPS_BOX(WIDTH/2, HEIGHT/2); // the GPS 

        startButton = new Fl_Button(WIDTH-100,HEIGHT/2 + 80,100,50,"Start Read");  // the start button that begins reading sensor data 
        
        
        // The Text Displays with sensor information
        longitudeDisplay = new Fl_Text_Display(WIDTH-100,HEIGHT/2 + 200,100,50, "Longitude: "); // longitude and latitude displays
        
        latitudeDisplay = new Fl_Text_Display(WIDTH-100,HEIGHT/2 + 300,100,50, "Latitude: "); 

        tempDisplay =  new Fl_Text_Display(WIDTH-200,HEIGHT/2 + 300,100,50, "Temperature: "); 

        elevationDisplay = new Fl_Text_Display(WIDTH-200,HEIGHT/2 + 200,100,50, "Elevation: "); 

        accel_x_Display = new Fl_Text_Display(WIDTH-300,HEIGHT/2 + 100,100,50, "Accel_X: "); 
        accel_y_Display = new Fl_Text_Display(WIDTH-300,HEIGHT/2 + 200,100,50, "Accel_Y: "); 
        accel_z_Display = new Fl_Text_Display(WIDTH-300,HEIGHT/2 + 300,100,50, "Accel_Z: "); 

        gyro_x_Display = new Fl_Text_Display(WIDTH-400,HEIGHT/2 + 100,100,50, "Gyro_X: "); 
        gyro_y_Display = new Fl_Text_Display(WIDTH-400,HEIGHT/2 + 200,100,50, "Gyro_Y: "); 
        gyro_z_Display = new Fl_Text_Display(WIDTH-400,HEIGHT/2 + 300,100,50, "Gyro_Z: "); 

        mag_x_Display = new Fl_Text_Display(WIDTH-500,HEIGHT/2 + 100,100,50, "Mag_X: "); 
        mag_y_Display = new Fl_Text_Display(WIDTH-500,HEIGHT/2 + 200,100,50, "Mag_Y: "); 
        mag_z_Display = new Fl_Text_Display(WIDTH-500,HEIGHT/2 + 300,100,50, "Mag_Z: "); 

        timeDisplay = new Fl_Text_Display(WIDTH-650,HEIGHT/2 + 100,100,50, "Time:"); 

        // the buffers for the text displays 
        longitudeDisplay->buffer(&longitudeBuffer);  
        latitudeDisplay->buffer(&latitudeBuffer); 

        tempDisplay->buffer(&tempBuffer); 
        elevationDisplay->buffer(&elevationBuffer); 
        accel_x_Display->buffer(&accel_x_Buffer); 
        accel_y_Display->buffer(&accel_y_Buffer); 
        accel_z_Display->buffer(&accel_z_Buffer); 

        gyro_x_Display->buffer(&gyro_x_Buffer); 
        gyro_y_Display->buffer(&gyro_y_Buffer); 
        gyro_z_Display->buffer(&gyro_z_Buffer); 

        mag_x_Display->buffer(&mag_x_Buffer); 
        mag_y_Display->buffer(&mag_y_Buffer); 
        mag_z_Display->buffer(&mag_z_Buffer); 

        timeDisplay->buffer(&timerBuffer); 

        
        tempChart = new Fl_Chart(0,HEIGHT/2,WIDTH/2 , HEIGHT/2-20, "Temperature"); // the temperature graph
        
        // lambda function to add a callback to the startButton without having to have the method be static 
        startButton->callback(
            [](Fl_Widget *w, void *data) {
            ((GUI*)data)->eventLoop();
            }, this);

        position = 1; 

        // specify the types of chart, making both a line chart 
        altitudeChart->type(FL_LINE_CHART); 
        tempChart->type(FL_LINE_CHART); 

    }
    void GUI::show() {
        window.show();
    }
    void GUI::end() {
        window.end(); 
    }

    