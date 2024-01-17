#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <Fl/Fl_Chart.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Timer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Image.H>
#include <iostream>

#define WIDTH 1400 // defines the width and the height for the entire window 
#define HEIGHT 800

/**
 * A class that inherits the box class and that overrides the draw method to draw a custom image
*/
class GPS_BOX
    :
        public Fl_Box
    {
    public:
    //denotes the positions of the image 
    double top_left_latitiude = 32.990547; 
    double bottom_right_latitude = 32.909900; 
    double top_left_longitude = -107.007395;
    double bottom_right_longitude = -106.869876; 

    // bottom right = 32.91167280121341, -106.88529755805972
    // top left = 32.989980839081575, -106.99281940290523


    /**
     * double values to store the changes in longitude and latitude from the 
     * top left and bottom right corners of the image. Used to calculate the ratio
     * needed to draw the rocket's current position. 
    */
    double latitudeWidth = 0.08067;  
    double longitudeHeight = 0.137519; 

    GPS_BOX(int w, int h);
    /**
     * Draws the image with the specified rgb data of the image, and then draws 
     * the rocket's current position with the drawRocketPosition helper function. 
    */
    void draw();
    
    /**
     * Draws the rocket's current position. Uses the latitude and longitude measurements to create
     * a ratio with respect to the total possible measurements that the image has, and then
     * multiplies that by the image width to get the correct pixel. 
    */
    void drawRocketPosition();
};
