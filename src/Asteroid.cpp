#include "Asteroid.h"
#include <iostream>

Asteroid::Asteroid()
{
      if(!texture.loadFromFile("ressources/asteroid.png")){
        std::cerr << "L'image de l'asteroid n'as pas été chargé" << std::endl;
    }
    sprite.setTexture(texture);
    /**On fait un set origine pour definir origine du sprite en generale de base c en haut a gauche **/
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    /**On va aussi definir d'ou il vas commencer **/
    //BF MODIFsprite.setPosition(50,50);
    sprite.setPosition(position.getX(),position.getY()); //On lui envoi le vecteur calculer dans la class coordonnees.
    speed = {100,20};
}

void Asteroid::afficher(sf::RenderWindow &window) const{
    window.draw(sprite);
}


/**Le but de cette methode est de mettre a jour la position du vaiseau avec cette methode on va appler spride move **/
void Asteroid::update(float time){
    // Cette partie la je l'ai reprise du vaisseau mais on la supprime pas, peut etre on va ajouté des vitesse diffente aux sprite(avoir des asterid plus rapide jcp ...)
    /*if(isSpeedUp){
         //speed += {SPEEDUP *time,0}; on peux pas tourné
         /// En faisant cela on peut aller dans toutes les direction car y est definie avec l'angle du sprite//
         speed += Vecteur::createFromAngle(SPEEDUP*time, sprite.getRotation());
    } */
    /** move est une variable temps spreite.move accepte seuelemnt 2 float donc je cree une variable pour la mettre dedeant**/
    auto moving = speed*time;
    //BF MODsprite.move(moving.x,moving.y);
    position  += moving;
    sprite.setPosition(position.getX(), position.getY());

};
