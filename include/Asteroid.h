#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

/**Pour cette class j'ai repris les meme truc que dans vaisseau(afficher, update...) des explication sont donnée au sein de la classe vaiseeau **/
class Asteroid
{
    public:
        Asteroid();
        void update(float time);
        void afficher(sf::RenderWindow &window)const;




    private:
        sf::Sprite sprite{};
        sf::Texture texture{};
        Vecteur speed{0.f,0.f};
        Coordonnees position{};
};

#endif // ASTEROID_H
