#include <iostream> 
#include <map> 
#include <string> 

#define WIRING_PI 1

class setup {
    public : 
        std::map <std::string, double> serialValues; // The map to contain the Serial Values transmitted 

        /**
         * Initializes the keys that correspond to data points to be read via Serial input. 
        */
        setup(); 

        /**
         * Will read in the serial data from the RATS module and update the serialValues map. 
        */
        void serialRead();

        void jsonStringToMap(const std::string& jsonString); 

}; 