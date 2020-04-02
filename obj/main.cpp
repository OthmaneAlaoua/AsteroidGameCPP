#include <SFML/Graphics.hpp>
#include <iostream>>
#include "include/Vaisseau.h"
#include "Asteroid.h"

/**Chose a savoir:
 - polymorphisme c'est l'utilisation d'un objet sans connaitre son type on l'utilisera en utilisant le nom de la class mere

**/

using namespace std;

constexpr int WIDTH_WINDOW{800};
constexpr int HEIGHT_WINDOW{800};
const sf::Color COLOR_VAISSEAU{sf::Color{255,255,128}};
int main()
{
    /**Simple création d'une fenetre avec ses dimentions et son nom **/
    sf::RenderWindow window{sf::VideoMode{WIDTH_WINDOW,HEIGHT_WINDOW},"Asteroid"};
    Coordonnees::initialiserEspace(WIDTH_WINDOW,HEIGHT_WINDOW);
    /**Utilisation de chrono car il fait partie de SFML **/
    auto chrono = sf::Clock{};
    auto vaisseau = Vaisseau{COLOR_VAISSEAU};
    auto asteroid = Asteroid{};
    auto asteroid2 = Asteroid{};
    auto asteroid3 = Asteroid{};
    /** C'est ici qu'on utilise le polymorph
        enfaite en faisant u ntableau on pourra le foreach et faire appel aux fonction comme "affiché" au lieu de l'appler 1000 fois
    **/
    auto polymObjects = std::array<AbstractEntity*, 4>{&asteroid, &asteroid2,&asteroid3,&vaisseau};


    while(window.isOpen()){
        auto event = sf::Event{}; /** creation d'un obj evenement **/
        while(window.pollEvent(event)){ /**le while c'est au cas ou il y aurait plusisuers event pendant 1 tours de boucle ensuite la fonction poll envoi true si ya des event a traiter**/
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        vaisseau.updateState(); /**C'est ce qui va gerer les touche ou j'appui  **/
        auto timeToFinishwhile = chrono.restart().asSeconds(); //Le temps de la boucle.
        /** A savoir quand tu utilise un pointeur sur une methode il utilise la type static et non dynamique (resolution stat des lien) donc utilise virtual**/
        for(auto* object : polymObjects){
            object->update(timeToFinishwhile); /** On evite de le tapper sur tout les objets par ex :  vaisseau.update(timeToFinishwhile); ....  **/
        }

        /**Cette partie c'est pour tester les collision **/
        for(auto* object : polymObjects){
            if(object != &vaisseau){
                object->testCollision(vaisseau);
            } //sinon il est toujour en colition avec lui meme
        }
        window.clear();/**Quand tu efface une fenetre tu l'efface avec une couleur donc si tu met une couleur dans les paranthese elle prendra cette couleur**/
       /**Pareil pour la fonction affiché on vas la foreach **/
       for(auto* object : polymObjects){
            object->afficher(window); /** On evite de le tapper sur tout les objets par ex :  vaisseau.update(timeToFinishwhile); ....  **/
        }
        window.display();
    }
    return 0 ;
}
