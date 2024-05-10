cmake_minimum_required(VERSION 3.1)
project(PiCar_AJ)

set(CMAKE_CXX_STANDARD 14)

find_package(PiPCA9685 REQUIRED)
find_package(WiringPi REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories(${WIRINGPI_INCLUDE_DIRS})
include_directories(include)

set(SOURCE_FILES
"src/main.cpp"
"src/Moteur.cpp"
"src/Servo.cpp"
"src/ServoConfig.cpp"
"include/Moteur.h"
"include/Servo.h"
"include/ServoConfig.h")

add_executable(PiCar_AJ ${SOURCE_FILES})
target_link_libraries(PiCar_AJ ${PiPCA9685_LIBRARY})
target_link_libraries(PiCar_AJ ${WIRINGPI_LIBRARIES})
target_link_libraries(PiCar_AJ ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(PiCar_AJ ${OpenCV_LIBS} )

