#include <SFML/Graphics.hpp>
#include <iostream>>
#include "include/Vaisseau.h"
#include "Asteroid.h"

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
    while(window.isOpen()){
        auto event = sf::Event{}; /** creation d'un obj evenement **/
        while(window.pollEvent(event)){ /**le while c'est au cas ou il y aurait plusisuers event pendant 1 tours de boucle ensuite la fonction poll envoi true si ya des event a traiter**/
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        vaisseau.updateState(); /**C'est ce qui va gerer les touche ou j'appui  **/
        auto timeToFinishwhile = chrono.restart().asSeconds(); //Le temps de la boucle.
        vaisseau.update(timeToFinishwhile);/**Enfaite si tu lui donne le temps de la boucle precedente sa definiera le temps que t'es rester appuyé cette methode. restart va dans un premier temps redemarer le chrono et ensuite retourner le temps entre sa creation et le restart ou son update(type de retour sf time ()float)  **/
        asteroid.update(timeToFinishwhile);
        window.clear();/**Quand tu efface une fenetre tu l'efface avec une couleur donc si tu met une couleur dans les paranthese elle prendra cette couleur**/
        asteroid.afficher(window);// le premier tu met il va en arriere plan donc la il sera deriiere le vaisseau
        vaisseau.afficher(window);
        window.display();
    }
    return 0 ;
}
