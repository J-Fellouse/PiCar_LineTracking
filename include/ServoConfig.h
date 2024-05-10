#ifndef SERVOCONFIG_H
#define SERVOCONFIG_H

#include <PiPCA9685/PCA9685.h>
#include <string>
#include <sstream>

class ServoConfig
{
    public:
        /* Constructors */
        //lorsque l'utilisateur veut utiliser les variables de configuration par défaut
        ServoConfig(void);
        //lorsque l'utilisateur veut définir ses propres variables de configuration
        ServoConfig(double freqHz, int ctrlMaxRange, int ctrlMinRange, int angleRange);
        /* Constructors */

        /* Getters */
        //permet d'obtenir la fréquence utilisée pour les servo-moteurs
        double getFreqHz(void);
        //permet d'obtenir la valeur maximale de PWM tolérée par le servo-moteur
        int getCtrlMaxRange(void);
        //permet d'obtenir la valeur minimale de PWM tolérée par le servo-moteur
        int getCtrlMinRange(void);
        //permet d'obtenir la plage d'angle tolérée par le servo-moteur
        int getAngleRange(void);
        //permet d'obtenir une référence vers l'objet permettant de gérer les servos
        PiPCA9685::PCA9685& getPca(void);
        /* Getters */

        /* Setters */
        //permet de définir la fréquence utilisée pour les servo-moteurs
        void setFreqHz(double freqHz);
        //permet de définir la valeur maximale de PWM tolérée par le servo-moteur
        void setCtrlMaxRange(int ctrlMaxRange);
        //permet de définir la valeur minimale de PWM tolérée par le servo-moteur
        void setCtrlMinRange(int ctrlMinRange);
        //permet de définir la plage d'angle tolérée par le servo-moteur
        void setAngleRange(int angleRange);
        /* Setters */

    private:
        double _freqHz = 60.0;
        int _ctrlMaxRange = 560;
        int _ctrlMinRange = 100;
        int _angleRange = 180;

        PiPCA9685::PCA9685 _pca{};
};

#endif