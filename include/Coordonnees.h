#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

/*
Enfaite le but de cette class c'est de pouvoir gerer les coordonnées de tout les obj verfier les limite et tout */
class Coordonnees
{
    public:
       /*On la defini en static car tout les objet seront dans le meme espace pas besoin de cree des obj */
       static void initialiserEspace(int longueur, int hauter);
       static inline int getLongueurEspace(){return longueurEspace;};
       static inline int getHauteurEspace(){return hauteurEspace;};
       Coordonnees();
       Coordonnees(float px , float py);

       /*Inline permet l'acces direct a l'attribut en gros en terme de perf c'est mieux */
       inline float getX() const {return x;};
       inline float getY() const {return y;};

       void operator+=(Vecteur const& vecteur);
       float calculerDistance(Coordonnees const& autre) const;


    private:
        /*Pour calculer les limite et pouvoir rester dedans*/
        void recalculer();
        float x{longueurEspace/2.f};
        float y{hauteurEspace/2.f};

        /*On met les prochain attribut en static car ils sont partager par tout les obj*/

        static int longueurEspace;
        static int hauteurEspace;


    protected:

    private:
};


#endif // COORDONNEES_H
