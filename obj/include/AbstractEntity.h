#ifndef ABSTRACTENTITY _H
#define ABSTRACTENTITY _H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

/** Ce que tu as a savoir sur cette class: c'est une class mere enfaite ya la otion d'heritage qui permet de donnée les attribut et les methodes
    aux classe "fille de celle ci"
    pour le moment les class qui en herite sont:
    - Vaisseau
    - Asteroid
**/


class AbstractEntity
{
    public:
        AbstractEntity(std::string const& imagePath);
        //AbstractEntity(AbstractEntity const& other) = delete; //suppression du constructeur de copie
        //void operator=(AbstractEntity const& other) = delete; //supp de la copie d'objet
        //AbstractEntity(std::string_view const& imagePath);
        /** RESOLUTION DES LIEN DE MANIERE DYNAMIQUE **/
        virtual void update(float time);
        void afficher(sf::RenderWindow &window)const;
        void testCollision(AbstractEntity& other);
        float getRayon() const;



    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};
        Vecteur speed{0.f,0.f};
        Coordonnees position{};
        float rotateSpeed{};
};

#endif // ABSTRACTENTITY _H
