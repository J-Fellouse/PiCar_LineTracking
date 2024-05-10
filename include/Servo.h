#ifndef SERVO_H
#define SERVO_H

#include <cmath>
#include "ServoConfig.h"
#include <future>
#include <thread>
#include <functional>

class Servo
{
    public:
        /*constructeur qui permet de définir un servo-moteur
        à partir de la configuration commune et de l'identification du servo-moteur*/
        Servo(ServoConfig& servoConfig, int channel);
        
        //fonction permettant de changer l'angle du servomoteur
        void setAngle(int angle);
        //fonction permettant de changer le PWM du servomoteur
        void setPwm(const uint16_t pwm);

        //fonction asynchrone permettant de changer l'angle du servomoteur
        std::future<void> asyncSetAngle(int angle);
        //fonction asyncrhone permettant de changer le PWM du servomoteur
        std::future<void> asyncSetPwm(const uint16_t pwm);

    private:
        ServoConfig& _servoConfig;
        PiPCA9685::PCA9685& _pca;
        int _channel;

        int _angleToPwm(int angle) const {
            return static_cast<int>(std::round((_servoConfig.getCtrlMaxRange() - _servoConfig.getCtrlMinRange()) / _servoConfig.getAngleRange() * angle));
        }
};

#endif