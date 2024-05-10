#include <PiPCA9685/PCA9685.h>
#include <iostream>
#include "ServoConfig.h"
#include "Servo.h"



Servo::Servo(ServoConfig& servoConfig, int channel) : _servoConfig(servoConfig), _channel(channel), _pca(servoConfig.getPca()) {}


void Servo::setAngle(int angle)
{
  //convertit l'angle fourni en PWM
  int calcPwm = _angleToPwm(angle);

  //vérifie si le PWM calculé n'est pas supérieur au MAX toléré
  if(calcPwm > _servoConfig.getCtrlMaxRange())
  {
    calcPwm = _servoConfig.getCtrlMaxRange();
  }

  //vérifie si le PWM calculé n'est pas inférieur au MIN toléré
  if(calcPwm < _servoConfig.getCtrlMinRange())
  {
    calcPwm = _servoConfig.getCtrlMinRange();
  }

  //définit le PWM du servomoteur de canal _channel
  _pca.set_pwm(_channel, 0 ,calcPwm);
}

void Servo::setPwm(const uint16_t pwm)
{
  int calcPwm = pwm;

  if(calcPwm > _servoConfig.getCtrlMaxRange())
  {
    calcPwm = _servoConfig.getCtrlMaxRange();
  }

  if(calcPwm < _servoConfig.getCtrlMinRange())
  {
    calcPwm = _servoConfig.getCtrlMinRange();
  }

  _pca.set_pwm(_channel, 0 ,calcPwm);
}

std::future<void> Servo::asyncSetAngle(int angle)
{
  return std::async(std::launch::async, &Servo::setAngle, this, angle);
}

std::future<void> Servo::asyncSetPwm(const uint16_t pwm)
{
    return std::async(std::launch::async, &Servo::setPwm, this, pwm);
}


