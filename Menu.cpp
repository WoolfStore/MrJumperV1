

#include "Menu.hpp"
#include <SFML/Audio.hpp>


using namespace sf;

int menu(RenderWindow & window, int NumOfWindow) {
    
    Music music;//создаем объект музыки
    music.openFromFile("menu queen.wav");//загружаем файл
    music.play();//воспроизводим музыку
    
    Font font;//шрифт
    font.loadFromFile("12838.ttf");//передаем нашему шрифту файл шрифта
    Text menu1("", font, 70);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    Text menu2("", font, 70);
    Text menu3("", font, 70);
    menu1.setString("START GAME");
	menu2.setString(" ");
    menu3.setString("EXIT GAME");
    
    Texture menuBackground;
    menuBackground.loadFromFile("background.png");
    Sprite menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(512, 260);
    menu2.setPosition(512, 360);
    menu3.setPosition(512, 460);
    menuBg.setPosition(0, 0);
    
    ////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        
        if (IntRect(512, 260, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }
        if (IntRect(512, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
        if (IntRect(512, 460, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }
        
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                isMenu = false;//если нажали первую кнопку, то выходим из меню
                NumOfWindow = 2;
            }
            if (menuNum == 3)  { window.close(); isMenu = false; }
            
        }
        
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        
        window.display();
    }
    return NumOfWindow;
}
