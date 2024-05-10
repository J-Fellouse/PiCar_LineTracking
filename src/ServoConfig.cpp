#include "ServoConfig.h"
#include <PiPCA9685/PCA9685.h>

#include <string>
#include <sstream>

//constructeur permettant d'utiliser la configuration par défaut
ServoConfig::ServoConfig()
{
    this->_pca.set_pwm_freq(this->_freqHz);
}

//constructeur permettant d'utiliser une configuration personnalisée
ServoConfig::ServoConfig(double freqHz, int ctrlMaxRange, int ctrlMinRange, int angleRange)
{
    this->_freqHz = freqHz;
    this->_ctrlMaxRange = ctrlMaxRange;
    this->_ctrlMinRange = ctrlMinRange;
    this->_angleRange = angleRange;

    this->_pca.set_pwm_freq(this->_freqHz);
}

//Getters
double ServoConfig::getFreqHz() {return this->_freqHz;}
int ServoConfig::getCtrlMaxRange() {return this->_ctrlMaxRange;}
int ServoConfig::getCtrlMinRange() {return this->_ctrlMinRange;}
int ServoConfig::getAngleRange() {return this->_angleRange;}
PiPCA9685::PCA9685& ServoConfig::getPca() {return this->_pca;}

//Setters
void ServoConfig::setFreqHz(double freqHz) {this->_freqHz = freqHz;}
void ServoConfig::setCtrlMaxRange(int ctrlMaxRange) {this->_ctrlMaxRange = ctrlMaxRange;}
void ServoConfig::setCtrlMinRange(int ctrlMinRange) {this->_ctrlMinRange = ctrlMinRange;}
void ServoConfig::setAngleRange(int angleRange) {this->_angleRange = angleRange;}