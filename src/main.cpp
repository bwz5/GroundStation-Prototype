#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <Fl/Fl_Chart.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Timer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Image.H>

#include <json/json.h>
#include <json/value.h>
#include "GUI.h"

#include <fstream> 
#include <iostream>
#include <map>
#include <string>


int main(int argc, char **argv) {
    GUI gui(WIDTH,HEIGHT,"Ground Station"); 
    
    gui.show(); 
    gui.end(); 


    return Fl::run();
}



