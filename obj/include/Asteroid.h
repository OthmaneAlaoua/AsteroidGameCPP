#ifndef ASTEROID_H
#define ASTEROID_H

#include "AbstractEntity.h"
#include <iostream>



/**Pour cette class j'ai repris les meme truc que dans vaisseau(afficher, update...) des explication sont donn�e au sein de la classe vaiseeau **/
class Asteroid : public AbstractEntity
{
    public:
        Asteroid();
        //Asteroid(Asteroid const& other) = delete; // �a supprime le constructeur de copie c'et une bonne patique a avoir
};

#endif // ASTEROID_H
