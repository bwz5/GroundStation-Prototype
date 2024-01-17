#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <Fl/Fl_Chart.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Timer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Image.H>
#include "GPS_BOX.h"
#include "DATA_PROCESSING.h"



class GUI {
    
    private:
        Fl_Window window;
        Fl_Chart *altitudeChart;
        GPS_BOX *GPS;
        Fl_Button *startButton;
        Fl_Chart *tempChart;
        setup DataProcessing; 

        //The text displays for a GUI Object
        Fl_Text_Display *longitudeDisplay;
        Fl_Text_Display *latitudeDisplay;

        Fl_Text_Display *elevationDisplay; 
        Fl_Text_Display *tempDisplay; 

        Fl_Text_Display *accel_x_Display; 
        Fl_Text_Display *accel_y_Display; 
        Fl_Text_Display *accel_z_Display; 

        Fl_Text_Display *gyro_x_Display; 
        Fl_Text_Display *gyro_y_Display; 
        Fl_Text_Display *gyro_z_Display; 

        Fl_Text_Display *mag_x_Display; 
        Fl_Text_Display *mag_y_Display; 
        Fl_Text_Display *mag_z_Display; 

        //The Text Displays' respective buffers 
        Fl_Text_Buffer gyro_x_Buffer; 
        Fl_Text_Buffer gyro_y_Buffer; 
        Fl_Text_Buffer gyro_z_Buffer; 


        Fl_Text_Buffer elevationBuffer; 
        Fl_Text_Buffer tempBuffer; 

        Fl_Text_Buffer longitudeBuffer; 
        Fl_Text_Buffer latitudeBuffer; 

        Fl_Text_Buffer accel_x_Buffer; 
        Fl_Text_Buffer accel_y_Buffer; 
        Fl_Text_Buffer accel_z_Buffer; 

        Fl_Text_Buffer mag_x_Buffer; 
        Fl_Text_Buffer mag_y_Buffer; 
        Fl_Text_Buffer mag_z_Buffer;

        int position; 

    public:   
   /**
    * Creates the GUI window and the components that will go in the window. 
   */
    GUI(int width, int height, const char* title); 

    /**
     * Shows the window. 
    */
    void show(); 
    void end(); 

    void graphCurrentPosition(); 

    void updateDisplays();

    void eventLoop(); 
}; 
