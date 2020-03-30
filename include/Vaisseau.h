#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
class Vaisseau{
private:
    sf::Sprite sprite{};/** Le sprite c'est l'objet qui permettra d'affciher la texture (en bas)**/
    sf::Texture texture{};/**La texture c'est image en elle meme**/
    Vecteur speed{0.f,0.f};/**Tu doit avoir deux valuer afin d'avoir la pos x et la pos y besoin d'un vecteur car 2 valuer **/

    bool isSpeedUp{false}; /**Permttra de savoir si il accelere ou non **/
    bool isTurningRight{false};
    bool isTurningLeft{false};

    Coordonnees position{};

    /**Constante**/
    static constexpr float SPEEDUP{700.f}; /**Constexpr signifie const mais en plus que la valeur doit etre definie a la compilation dans notre cas 7000 si on utilse seulement const on peux pas mmettre de valeuer et il faudrait les mettre dans le cpp**/
    static constexpr float SPEEDDOWN{2.f};
    static constexpr float TURNINGSPEED{100.f};
public:
    void updateState();
    void update(float time);/**Le paramettre time sert a calculer la vitesse psk vit = temp * accelration;**/
    void afficher(sf::RenderWindow &window)const;

    /**Constructeur**/
    Vaisseau(sf::Color couleur);
    ~Vaisseau();
};

#endif // VAISSEAU_H_INCLUDED
