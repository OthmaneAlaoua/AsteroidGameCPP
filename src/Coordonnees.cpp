#include "Coordonnees.h"
#include <iostream>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};

Coordonnees::Coordonnees(){
    if(longueurEspace == 0 || hauteurEspace == 0){
        std::cerr << "Attention : une coordonn�e a �t� cr�ee avant l'initialisation de l'espace !"<< std::endl;
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
        std::cerr <<"Attention : l'espace �tait deja initialis� !" << std::endl;
    }
    longueurEspace = longueur;
    hauteurEspace = hauteur;
}

void Coordonnees::recalculer(){
    /**�a c'est quand on sort de la map on le fait apparaittre de lautre cote  genre si **/
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


