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
        Fl_Text_Display *longitudeDisplay;
        Fl_Text_Display *latitudeDisplay;
        Fl_Chart *tempChart;
        Fl_Box *testBox;

        setup DataProcessing; 

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
}; 
