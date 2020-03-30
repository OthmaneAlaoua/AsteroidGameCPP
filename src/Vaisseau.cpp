#include "../include/Vaisseau.h"
#include <iostream>
void Vaisseau::updateState(){
    /**On fait la verification si l'venement c'est une tocuhe clavier et si c'est fleche du haut **/
    isSpeedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    isTurningLeft =  sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    isTurningRight =  sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
void Vaisseau::afficher(sf::RenderWindow &window) const{
    window.draw(sprite);
}
/**Le but de cette methode est de mettre a jour la position du vaiseau avec cette methode on va appler spride move **/
void Vaisseau::update(float time){
    if(isSpeedUp){
         //speed += {SPEEDUP *time,0}; on peux pas tourné
         /** En faisant cela on peut aller dans toutes les direction car y est definie avec l'angle du sprite**/
         speed += Vecteur::createFromAngle(SPEEDUP*time, sprite.getRotation());
    }
    speed -= speed * SPEEDDOWN *time;
    /** move est une variable temps spreite.move accepte seuelemnt 2 float donc je cree une variable pour la mettre dedeant**/
    auto moving = speed*time;
    //BF MODsprite.move(moving.x,moving.y);
    position  += moving;
    sprite.setPosition(position.getX(), position.getY());
    /**Si il tourne a gauche **/
    if(isTurningLeft){
        sprite.rotate(-TURNINGSPEED * time);
    }

    /**Si il tourne a droite **/
    if(isTurningRight){
        sprite.rotate(TURNINGSPEED * time);
    }
};

/**Constructeur **/
Vaisseau::Vaisseau(sf::Color couleur){
    if(!texture.loadFromFile("ressources/vaisseau.png")){
        std::cerr << "L'image du vaisseau n'as pas été chargé" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setColor(couleur);
    /**On fait un set origine pour definir origine du sprite en generale de base c en haut a gauche **/
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    /**On va aussi definir d'ou il vas commencer **/
    //BF MODIFsprite.setPosition(50,50);
    sprite.setPosition(position.getX(),position.getY());
}

Vaisseau::~Vaisseau(){
    std::cout << "Merci d'avoir joué"  << std::endl;
}

