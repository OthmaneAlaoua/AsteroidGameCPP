#include "Vecteur.h"
#include <cmath>

void Vecteur::operator+=(Vecteur const& firstVecteur){
    x += firstVecteur.x;
    y += firstVecteur.y;
 }

void Vecteur::operator-=(Vecteur const& firstVecteur){
    x -= firstVecteur.x;
    y -= firstVecteur.y;
}

Vecteur Vecteur::operator*(float coef)const{
    /**Ca on peut le faire psk tout nos attribut sont public et que l'on a aps de constructeur du coup pour le conpilateur l'initialisation correspond a l'initialisation de tout les attribut**/
    /** pas besoin de mettre VEcteur car il le deduit en fonction du retour **/
    return { x*coef,y*coef};
}
/**Elle va juste cree un vecteur a partire de la taille et de l'angle// On a des angle en degre cos et sin c radiant du coup on divise /180**/
Vecteur Vecteur::createFromAngle(float height, float angleDegree){
    return {height*cos(angleDegree/180.f*3.14159265358979323846),height*sin(angleDegree/180.f*3.14159265358979323846)};
}
