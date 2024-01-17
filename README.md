Cornell Rocketry 2024 GroundStation. Uses FLTK for the GUI components, JSONCPP to read .json files and strings, and WIRINGPI to read in serial data on the raspberry pi. 

<h2>Depenendencies Required</h2> <br> 
- cmake <br>
- fltk <br>
- jsoncpp <br>
- wiringpi  <br>
- homebrew (for MacOS) <br> 
<h2>Setup</h2> <br>
1. Install the required Dependencies <br> 
2. Undefine the WIRING_PI definition in DATA_PROCESSING.h <br> 
3. If you want to change the width and height of the frame, change the definitions in GPS_BOX.h <br>
<h2>Running</h2><br>
1. In the home directory, run mkdir build && cd build in the terminal <br>
2. Run cmake .. and then make -j4 in the terminal <br> 

<h2>Examples of the GUI</h2>

<br>
<img width="1398" alt="Screenshot 2024-01-17 at 4 30 49 PM" src="https://github.com/bwz5/GroundStation/assets/143123593/bc1b1896-eb7d-4122-9dd5-654fb3829a13">

<br>
<h2>Use</h2><br>
Start Read begins the reading of sensor data. Then, elevation data and temperature data will be graphed in their respective charts. Sensor readings will also appear in their own respecitve text boxes. Finally, the location of the rocket will be displayed on the map using GPS coordinates. 
