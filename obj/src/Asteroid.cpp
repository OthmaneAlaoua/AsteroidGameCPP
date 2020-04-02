#include "Asteroid.h"
#include <iostream>
#include <random>
#include <chrono>

Asteroid::Asteroid(): AbstractEntity{"ressources/asteroid.png"} // enfaite j'ajout ca pour que avant de construire l'asteroid il construit la mere avec la bonne image
{
    /** Random number distribution that produces floating-point values according to a uniform distribution **/

    /** random_device is a uniformly-distributed integer random number generator that produces non-deterministic random numbers. **/
    //auto generateur = static_cast<float>(rand() % 100);//std::random_device{};
    //std::random_device generateur;
    //std::default_random_engine generateur;
    //auto generateur = std::random_device{};
    /** Hello **/
    auto temps = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(temps).count();
    auto generateur = std::mt19937{static_cast<unsigned long>(ns)};

    auto distributionPosition = std::uniform_real_distribution<float>{-150,150};
    auto distributionSpeed = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    auto distributionRotateSpeed = std::uniform_real_distribution<float>{10,30};
    position = {distributionPosition(generateur), distributionPosition(generateur)};

    /**Enfaite je le met la psk on herite de abstract mais il faut definir une vitesse comme c pas la memepour toute les class on la def dans le construct **/
    //speed = {100,20};
    speed = Vecteur::createFromAngle(distributionSpeed(generateur),distributionAngle(generateur));

    /** On ajoute un truc pour faire tourner les asteroid il sert a rien mais sa fait bien  **/
    rotateSpeed =  distributionRotateSpeed(generateur);
}



