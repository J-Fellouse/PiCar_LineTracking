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

<p align="center">
  <img src="https://m.media-amazon.com/images/I/71uYI1BZTUS._AC_UF1000,1000_QL80_.jpg" width="400">
  <br/>
  <i>The PiCar Robot by Adeept</i>
</p>

## What is the vision process ?
<p align="center">
  <img src="https://images2.imgbox.com/f4/5c/H1HkfCkQ_o.png">
  <br/>
  <i>Step 1 : Base image captured by the RPi Camera </i>
</p>

<p align="center">
  <img src="https://images2.imgbox.com/41/27/AVn4vCBk_o.png">
  <br/>
  <i>Step 2 : Cropped image </i>
</p>

<p align="center">
  <img src="https://images2.imgbox.com/b7/30/aOHqRe1B_o.png">
  <br/>
  <i>Step 3 : Grayscaled image </i>
</p>

<p align="center">
  <img src="https://images2.imgbox.com/49/31/Hgisz6Nt_o.png">
  <br/>
  <i>Step 4 : Thresholded image </i>
</p>
