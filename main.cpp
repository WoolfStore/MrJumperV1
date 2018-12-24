#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "allclass.hpp"
#include "Menu.hpp"
#include "GameBegins.hpp"
#include "Finish.hpp"
#include "Fall.hpp"


using namespace sf;
using namespace std;

int NumOfWindow = 1;
int a = 0;

int main()
{
   
    RenderWindow window(sf::VideoMode(1280, 720), "MrJumper");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (NumOfWindow == 1)
            NumOfWindow = menu(window, NumOfWindow);
        if (NumOfWindow == 2)
            NumOfWindow = GameBegins(window, NumOfWindow);
        if (NumOfWindow == 3)
            NumOfWindow = finishGame(window, NumOfWindow);
        if (NumOfWindow == 4)
            NumOfWindow = EndGame(window, NumOfWindow);
        
        }
    return 0;
}

