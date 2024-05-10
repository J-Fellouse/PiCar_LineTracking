#ifndef MOTEUR_H
#define MOTEUR_H

class Moteur
{
    public:
        Moteur(int enablePin, int rotPin1, int rotPin2);

        void stop();
        void forward(int speed);
        void backward(int speed);

    private:
        int _enablePin;
        int _rotPin1;
        int _rotPin2;
};

#endif