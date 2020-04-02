#include "AbstractEntity.h"
#include <iostream>


AbstractEntity::AbstractEntity(std::string const& imagePath){
      if(!texture.loadFromFile(imagePath)){
        std::cerr << "L'image n\'as pas été chargé" << std::endl;
    }
    sprite.setTexture(texture);
    /**On fait un set origine pour definir origine du sprite en generale de base c en haut a gauche **/
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    /**On va aussi definir d'ou il vas commencer **/
    //BF MODIFsprite.setPosition(50,50);
    sprite.setPosition(position.getX(),position.getY()); //On lui envoi le vecteur calculer dans la class coordonnees.
}

void AbstractEntity::afficher(sf::RenderWindow &window) const{
    /** Important le probleme qu'on as c'est que les objets apparaissent de maniere brutal quans il passe l'ecran le but du prochain code est qu'il s'affiche
        correctement sans etre brut, jusqu'a present on affichait l'objet a ses coordonnees mais maintenant on va afficher a ses coordonnees mais en plus a
        ses (coordonnees + taille de l'ecran) (dans tout les sens possible) comme sa si il sort un peu de l'ecran il sera affiché aussitot de lautre coté
    **/
    /** premier coorespond diago en haut a gauche ,2:verticale en haut,3: en haut a doitre ... **/
    auto allDraw = std::array<Vecteur,9>{Vecteur{-1,-1},Vecteur{0,-1},Vecteur{1,-1},
                                         Vecteur{-1,0},Vecteur{0,0},Vecteur{1,0},
                                         Vecteur{-1,1},Vecteur{0,-1},Vecteur{1,1}};


    /**Maintenant on peux foreach le tableau en affichant a chaque fois dans chaque position **/
    for(auto& currentDraw : allDraw){
            /** https://www.sfml-dev.org/tutorials/2.5/graphics-transform-fr.php **/
        auto transforme = sf::Transform{};
        /** Donc le vecteur * la hauteur de la fenetre et la longeur de la fenetre **/
        transforme.translate(currentDraw.x*Coordonnees::getLongueurEspace(), currentDraw.y*Coordonnees::getHauteurEspace());
         window.draw(sprite,transforme);
    }

}


/**Le but de cette methode est de mettre a jour la position du vaiseau avec cette methode on va appler spride move **/
void AbstractEntity::update(float time){
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
    sprite.rotate(rotateSpeed*time);

};

float AbstractEntity::getRayon() const {
    return sprite.getLocalBounds().height/2.f;
}
void AbstractEntity::testCollision(AbstractEntity& other){
    /** Pour savoir si il se touche on calcule la distance entre les deux sprite **/
    auto distance = position.calculerDistance(other.position);
    if(distance < getRayon() + other.getRayon()){
        sprite.setColor(sf::Color::Red);
        other.sprite.setColor(sf::Color::Red);
    }
}
