#include "Coordonnees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};

Coordonnees::Coordonnees(){
    if(longueurEspace == 0 || hauteurEspace == 0){
        std::cerr << "Attention : une coordonnée a été créee avant l'initialisation de l'espace !"<< std::endl;
    }
}

Coordonnees::Coordonnees(float px, float py) : x{px}, y{py}{
    recalculer();
}

void Coordonnees::operator+=(Vecteur const &vecteur){
    x += vecteur.x;
    y += vecteur.y;
    recalculer();
}

void Coordonnees::initialiserEspace(int longueur, int hauteur){
    if(longueurEspace != 0 || hauteurEspace !=0){
        std::cerr <<"Attention : l'espace était deja initialisé !" << std::endl;
    }
    longueurEspace = longueur;
    hauteurEspace = hauteur;
}

void Coordonnees::recalculer(){
    /**ça c'est quand on sort de la map on le fait apparaittre de lautre cote  genre si **/
    /** En gros si le vaiseau il est au "pixel" 801 on va faire 801  - 800 donc 1 il va revenir de l'autrze cote**/
    while(x>longueurEspace){
        x -= longueurEspace;
    }
    while(x < 0){
        x += longueurEspace;
    }
    while(y > hauteurEspace){
        y -= hauteurEspace;
    }
    while(y < 0){
        y += hauteurEspace;
    }
}

/**Kader Look ca stp **/

float Coordonnees::calculerDistance(Coordonnees const& other)const {
    /** ce truc juste pour sauvegarder et savoir la distance en tre les deux element donc on use un vecteur **/
    auto delta = Vecteur{std::min({abs(x-other.x),abs(x-other.x-longueurEspace),abs(x-other.x+longueurEspace)}), std::min({abs(y-other.y), abs(y-other.y-hauteurEspace), abs(y-other.y+hauteurEspace)})};
    return sqrt(delta.x*delta.x+delta.y*delta.y);
}
