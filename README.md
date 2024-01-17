Cornell Rocketry 2024 GroundStation. Uses FLTK for the GUI components, JSONCPP to read .json files and strings, and WIRINGPI to read in serial data on the raspberry pi. 

<h2>Depenendencies Required</h2> <br> 
- cmake <br>
- fltk <br>
- jsoncpp <br>
- wiringpi  <br>
- homebrew <br> 
<h2>Setup</h2> <br>
1. Install the required Dependencies <br> 
2. Undefine the WIRING_PI definition in DATA_PROCESSING.h <br> 
3. If you want to change the width and height of the frame, change the definitions in GPS_BOX.h <br>
<h2>Running</h2><br>
1. In the home directory, run mkdir build && cd build in the terminal <br>
2. Run cmake .. and then make -j4 in the terminal <br> 

<h2>Examples of the GUI</h2>
