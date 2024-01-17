#include <iostream> 
#include <map> 
#include <string> 

#define WIRING_PI 1

class setup {
    public : 
        static std::map <std::string, double> serialValues; // The map to contain the Serial Values transmitted 

        /**
         * Is never used, since methods are static. 
        */
        setup(); 

        /**
         * Will read in the serial data from the RATS module and update the serialValues map. 
        */
        static std::string serialRead();

        static void jsonStringToMap(const std::string& jsonString); 

}; 