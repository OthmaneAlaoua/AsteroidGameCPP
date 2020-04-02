#include "../include/Vaisseau.h"
#include <iostream>
void Vaisseau::updateState(){
    /**On fait la verification si l'venement c'est une tocuhe clavier et si c'est fleche du haut **/
    isSpeedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    isTurningLeft =  sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    isTurningRight =  sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

/**Le but de cette methode est de mettre a jour la position du vaiseau avec cette methode on va appler spride move **/
void  Vaisseau::update(float time){
    if(isSpeedUp){
         //speed += {SPEEDUP *time,0}; on peux pas tourné
         /** En faisant cela on peut aller dans toutes les direction car y est definie avec l'angle du sprite**/
         speed += Vecteur::createFromAngle(SPEEDUP*time, sprite.getRotation());
    }
    /**Je commente les ligne suivante car il ya les meme dans abstract elle serve au deplacement **/ /**
    ;
    /** move est une variable temps spreite.move accepte seuelemnt 2 float donc je cree une variable pour la mettre dedeant** /
    auto moving = speed*time; /
    //BF MODsprite.move(moving.x,moving.y);
    position  += moving; **/

    speed -= speed * SPEEDDOWN *time;
//sprite.setPosition(position.getX(), position.getY());
    /**Si il tourne a gauche **/
    if(isTurningLeft){
       // sprite.rotate(-TURNINGSPEED * time);
       rotateSpeed = -TURNINGSPEED;
    } else if(isTurningRight){
        //sprite.rotate(TURNINGSPEED * time);
        rotateSpeed = TURNINGSPEED ;
    } else{
        rotateSpeed = 0;
    }
    AbstractEntity::update(time);

};

/**Constructeur **/
Vaisseau::Vaisseau(sf::Color couleur) : AbstractEntity{"ressources/vaisseau.png"} {
    /** Il contient que la couleur du vaisseau car on a mis tout ce qu'il fallait dans la class mere en plus l'image est construit par avant car on l'envoi dans la liste constructeur**/
    sprite.setColor(couleur);
}

Vaisseau::~Vaisseau(){
    std::cout << "Merci d'avoir joué"  << std::endl;
}

