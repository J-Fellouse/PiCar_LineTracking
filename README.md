# PiCar_LineTracking
**Warning : this project was done in 2023, the repo is actually unmaintened**\
<ins>**TODO :</ins> Integrate the vision process into a separate class instead of having a function in main.**\
\
C++ project that enables a PiCar robot to follow a line on the ground using its camera (OpenCV).

## How to build ?
1. Install CMake (at least version 3.1).
2. Download, compile and install via CMake OpenCV on the Raspberry (or do cross compilation).
3. Download and install the releases of WiringPi (deb package), create a cmake install script and put it inside the appropriate CMake folder.
4. Download, compile PiPCA9685.
5. Clone the repo and enter the command ```cmake -B build``` and then ```cmake --build build```.
6. The binary should be in ```build/PiCar_AJ```.

## What is a PiCar ?
Picar Pro is an educational and fun kit based on the Raspberry Pi 4 3 model B B+ , and it is also a smart electronic teaching aid for different people's learning needs. The overall structure is simple and easy to assemble. Compared with similar robot kits, Picar-Pro has added camera, robotic arm, light, more interesting possibilities for your experiment.

![Photography of the PiCar robot by Adeept](https://m.media-amazon.com/images/I/71uYI1BZTUS._AC_UF1000,1000_QL80_.jpg "The PiCar robot by Adeept")
