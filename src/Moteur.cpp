#include "Moteur.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <unistd.h>

Moteur::Moteur(int enablePin, int rotPin1, int rotPin2)
{
    this->_enablePin = enablePin;
    this->_rotPin1 = rotPin1;
    this->_rotPin2 = rotPin2;

    //on définit les PINs du moteur en mode sortie
    pinMode(enablePin, OUTPUT);
    pinMode(rotPin1, OUTPUT);
    pinMode(rotPin2, OUTPUT);
    
    //on arrête les moteurs par sécurité
    stop();

    //on initialise le PWM avec une valeur initiale de 0
    //et une valeur maximum de 100
    softPwmCreate(enablePin, 0, 100);
}

void Moteur::stop()
{
    //on met tout les PINs du moteur à état bas
    digitalWrite(this->_enablePin, LOW);
    digitalWrite(this->_rotPin1, LOW);
    digitalWrite(this->_rotPin2, LOW);
}

void Moteur::forward(int speed)
{
    /*on applique un état haut et bas aux
    pins du pont en H pour une polarité normale*/
    digitalWrite(this->_rotPin1, LOW);
    digitalWrite(this->_rotPin2, HIGH);

    /*on met en le PWM à speed sur le pin d'alimentation
    du moteur*/
    softPwmWrite(this->_enablePin, speed);
}

void Moteur::backward(int speed)
{
    digitalWrite(this->_rotPin1, HIGH);
    digitalWrite(this->_rotPin2, LOW);
    softPwmWrite(this->_enablePin, speed);
}