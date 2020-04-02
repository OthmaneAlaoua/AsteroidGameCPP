#ifndef VECTEUR_H
#define VECTEUR_H


struct Vecteur /**Struct c'est la meme chose qu'une classe sauf que par default les attribut sont public non privé le but c'est avoir une classe dite de donnée */
{
    /**Les methode suivante sont des surcharge d'operateur /le +/-... n'existe pas pour le vecteur tu peux donc les definir **/
    void operator+=(Vecteur const &firstVecteur);
    void operator-=(Vecteur const &firstVecteur);

    Vecteur operator*(float coef) const;

    float x{0.f};
    float y{0.f};


    static Vecteur createFromAngle(float height , float angleDegree);
};

#endif // VECTEUR_H
