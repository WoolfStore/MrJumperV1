

#include "Finish.hpp"
#include <SFML/Audio.hpp>


using namespace sf;

int finishGame (RenderWindow & window, int NumOfWindow){
    
    Music music;//создаем объект музыки
    music.openFromFile("won queen.wav");//загружаем файл
    music.play();//воспроизводим музыку
    
    Font font;//шрифт
    font.loadFromFile("12838.ttf");//передаем нашему шрифту файл шрифта
    Text menuButton("", font, 70);
    menuButton.setString("YOU WON");
    
    Texture menuBackground;
    menuBackground.loadFromFile("background.png");
    Sprite menuBg(menuBackground);
    
    menuButton.setPosition(512, 260);
    menuBg.setPosition(0, 0);
    
    bool isMenu = 1;
    int menuNum = 0;
    
    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menuNum = 0;
        menuButton.setColor(Color::White);
        window.clear(Color(129, 181, 221));
        
        if (IntRect(512, 260, 300, 50).contains(Mouse::getPosition(window))) { menuButton.setColor(Color::Red); menuNum = 1; }
        
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                NumOfWindow = 1;
                isMenu = false;
            }
            
        }
        
        window.draw(menuBg);
        window.draw(menuButton);
        window.display();
    }
    return NumOfWindow;
}
