#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <cmath>
#include <csignal>
#include <opencv2/opencv.hpp>

#include "Moteur.h"
#include "Servo.h"

bool capture = true;

void signal_handler(int signal_num) 
{ 
    std::cout << "Arrêt du robot" << std::endl;
    //on arrête la boucle infinie
    capture = false;
} 

cv::Point detectLinePosition(const cv::Mat& image) {
    // Rogner la partie basse de l'image (les 25% inférieurs)
    cv::Rect roi(0, image.rows * 3 / 4, image.cols, image.rows / 4);
    cv::Mat croppedImage = image(roi);

    // Convertir en niveaux de gris
    cv::Mat gray;
    cv::cvtColor(croppedImage, gray, cv::COLOR_BGR2GRAY);

    // Appliquer un seuillage
    cv::Mat thresholded;
    cv::threshold(gray, thresholded, 100, 255, cv::THRESH_BINARY_INV);

    // Détecter les contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresholded, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // Trouver le contour le plus grand
    double maxArea = 0;
    std::vector<cv::Point> largestContour;
    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        if (area > maxArea) {
            maxArea = area;
            largestContour = contour;
        }
    }

    // Calculer la position x du centre du contour
    cv::Moments M = cv::moments(largestContour);
    cv::Point center;
    if (M.m00 != 0) {
        center = cv::Point(static_cast<int>(M.m10 / M.m00), static_cast<int>(M.m01 / M.m00));
    }

    return center;
}

int main() {
    //on intercepte le signal SIGINT déclenché par CTRL+C
    signal(SIGINT, signal_handler);

    //initialisation de la librairie wiringPi
    wiringPiSetupGpio();
    
    //initialisation des moteurs via leurs PINs respectifs
    Moteur moteurGauche(4, 26, 21);
    Moteur moteurDroit(17, 27, 18);

    //initialisation de la configuration des servomoteurs
    ServoConfig servoConfig;
    /*initialisation des servomoteurs via la configuration
    et leur numéro de canal respectif*/
    Servo direction(servoConfig, 0);
    Servo bras(servoConfig, 1);

    //on bouge le bras du robot pour que la caméra soit centrée
    bras.setAngle(190);
    //on centre les roues du robot
    direction.setAngle(180);

    /*on initialise l'objet permettant de capturer une image
    à partir de la caméra d'index 0 */
    cv::VideoCapture cap(0);

    //on vérifie que la caméra est bien disponible
    if (!cap.isOpened()) {
        std::cerr << "Erreur : Impossible d'ouvrir la caméra" << std::endl;
        return -1;
    }

    int lastX = -1;

    while(capture)
    {        
        //on capture un image
        cv::Mat frame;
        cap >> frame;

        //on vérifie que la prise d'image s'est effectuée sans erreur
        if (frame.empty()) {
            std::cerr << "Erreur : Impossible de capturer une image" << std::endl;

            //on arrête le robot en cas d'erreur
            moteurDroit.stop();
            moteurGauche.stop();
            direction.setAngle(180);
            return -1;
        }

        //on récupère la position X de la ligne
        cv::Point linePosition = detectLinePosition(frame);

        int processedX = 0;

        //on vérifie qu'une ligne est bien détectée
        if(linePosition.x != 0)
        {
            processedX = linePosition.x;
            lastX = linePosition.x;
        }
        //sinon la valeur de X prend sa dernière valeur non nulle
        //soit la dernière position où une ligne a été detéctée
        else
        {
            processedX = lastX;
        }

        int angle = static_cast<int>(0.333*processedX-75);
        int vitesse = static_cast<int>(-0.6*std::abs(angle)+100);
        
        std::cout << "Angle : " << angle << std::endl;
        std::cout << "Vitesse : " << vitesse << std::endl;
        
        direction.setAngle(180-angle);
        moteurGauche.forward(vitesse);
        moteurDroit.forward(vitesse);
    }

    moteurDroit.stop();
    moteurGauche.stop();
    direction.setAngle(180);

    return 0;
}
