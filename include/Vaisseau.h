#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

#include "AbstractEntity.h"

class Vaisseau : public AbstractEntity {

private:

    bool isSpeedUp{false}; /**Permttra de savoir si il accelere ou non **/
    bool isTurningRight{false};
    bool isTurningLeft{false};


    /**Constante**/
    static constexpr float SPEEDUP{700.f}; /**Constexpr signifie const mais en plus que la valeur doit etre definie a la compilation dans notre cas 7000 si on utilse seulement const on peux pas mmettre de valeuer et il faudrait les mettre dans le cpp**/
    static constexpr float SPEEDDOWN{2.f};
    static constexpr float TURNINGSPEED{100.f};

public:
    void updateState();
    /* A savoir on ne supprime pas update meme si elle est dans abstract entity car contrairement aux autre elle a beaucoup plus de traitement */
    void update(float time);/**Le paramettre time sert a calculer la vitesse psk vit = temp * accelration;**/

    /**Constructeur**/
     Vaisseau(sf::Color couleur);
    ~Vaisseau();
};

#endif // VAISSEAU_H_INCLUDED
