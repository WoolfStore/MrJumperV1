#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <list>

using namespace sf;
using namespace std;

class platform {
public:
    float x, y, w, h;
    Image image;
    Texture texture;//сфмл текстура
    Sprite platformsprite;//сфмл спрайт
    
    platform(float X, float Y){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
        image.loadFromFile("Resources\platform.jpg");
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        platformsprite.setTexture(texture);//заливаем спрайт текстурой
        x = X; y = Y;//координата появления спрайта
        platformsprite.setTextureRect(IntRect(0, 0, 256, 64));
        platformsprite.setPosition(x,y);
    }
};

int main()
{
    bool on_ground = false;
    bool stopPlatform = false;
    bool stopPlatform2 = false;
    bool heroJump = false;
    bool platformMove = true;
    bool onMovingPlatform = false;
    bool createNewPlatform = false;

    RenderWindow window(sf::VideoMode(800, 600), "EASY GAME ");
    
    Texture poisontexture;
    poisontexture.loadFromFile("Resources\poison.png");
    
    Sprite poisonsprite;
    poisonsprite.setTexture(poisontexture);
    poisonsprite.setTextureRect(IntRect(0,0,1279,64));
    poisonsprite.setPosition(0, 1216);
    
    Texture herotexture;
    herotexture.loadFromFile("Resources\hero2.png");
    
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(32, 128, 64, 128));
    herosprite.setPosition(592, 1280-128-64);
    
    startGame(herosprite.getPosition().x, herosprite.getPosition().y);
    platform p1(512, 1280-64);
    pushPlatformIntoMatrix(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y);
    platform p2(0, 1280-128);
    pushPlatformIntoMatrix(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
    platform p3(1280-256, 1280-192);
    pushPlatformIntoMatrix(p3.platformsprite.getPosition().x, p3.platformsprite.getPosition().y);
    platform p4(0, 1280-192-64);
    pushPlatformIntoMatrix(p4.platformsprite.getPosition().x, p4.platformsprite.getPosition().y);
    
    float CurrentFrame = 0;  //хранит текущий кадр
    Clock clock;
    
    while (window.isOpen())
    {
        
        if (on_ground && (herosprite.getPosition().y < 1280-64-128)){
            onMovingPlatform = true;
        } else {
            onMovingPlatform = false;
        }
        
        on_ground = onGround();
        //        std::cout << on_ground;
        
        if (gameOver() == 2) {
            window.close();
        }
        
        if (gameOver() == 1) {
            herosprite.setPosition(592, 1280-128-64);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            on_ground = true;
        }
        
        
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        ///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
        
        if ((Keyboard::isKeyPressed(Keyboard::Left))) { //если нажата клавиша стрелка влево
            //            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //            if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            //            herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            herosprite.move(-0.2*time, 0);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Right))) {
//                        CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
//                        if (CurrentFrame > 4) CurrentFrame -= 4; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
//                        herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 128, 64, 128)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            
            herosprite.move(0.2*time, 0);//происходит само движение персонажа вправо
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Space)) ) {
            
            if (((p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 1024)){
                herosprite.move(0, -0.6*time);
                heroJump = true;
            }
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            
        }
        // ДВИЖЕНИЕ И ОСТАНОВКА ПЛАТФОРМЫ
        
        if (p2.platformsprite.getPosition().x >= 1280-256)
            platformMove = false;
        if (p2.platformsprite.getPosition().x <= 0)
            platformMove = true;
        if (!stopPlatform){
            if (platformMove){
                p2.platformsprite.move (0.2*time, 0);
                if ((p2.platformsprite.getPosition().x >= p1.platformsprite.getPosition().x) && onMovingPlatform){
                    stopPlatform = true;
                }
            }
            else {
                p2.platformsprite.move (-0.2*time, 0);
                if ((p2.platformsprite.getPosition().x <= p1.platformsprite.getPosition().x) && onMovingPlatform){
                    stopPlatform = true;
                }
            }
            pushPlatformIntoMatrix(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
        }
        
        // ПОЯЛЕНИЕ ТРЕТЕЙ ПЛАТФОРМЫ
        
        if (stopPlatform){
            if (p3.platformsprite.getPosition().x >= 1280-256)
                platformMove = false;
            if (p3.platformsprite.getPosition().x <= 0)
                platformMove = true;
            if (!stopPlatform2){
                if (platformMove){
                    p3.platformsprite.move (0.2*time, 0);
                    if ((p3.platformsprite.getPosition().x >= p2.platformsprite.getPosition().x) && onMovingPlatform){
                        stopPlatform2 = true;
                    }
                }
                else {
                    p3.platformsprite.move (-0.2*time, 0);
                    if ((p3.platformsprite.getPosition().x <= p2.platformsprite.getPosition().x) && onMovingPlatform){
                        stopPlatform2 = true;
                        }
                    }
                pushPlatformIntoMatrix(p3.platformsprite.getPosition().x, p3.platformsprite.getPosition().y);
            }
        }
        if (!on_ground && (p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 1024){
            herosprite.move(0, 0.3*time);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        
        // ДВИЖЕНИЕ ПЕРСОНАЖА С ПЛАТФОРМОЙ
        
        if (onMovingPlatform){
            if (!stopPlatform){
                if (platformMove){
                    herosprite.move(0.2*time, 0);
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                } else {
                    herosprite.move(-0.2*time, 0);
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                }
            }
        }
        
        window.clear();
        window.draw(poisonsprite);
        window.draw(herosprite);
        window.draw(p1.platformsprite);
        window.draw(p2.platformsprite);
        if (stopPlatform)
            window.draw(p3.platformsprite);
        if (stopPlatform2)
            window.draw(p4.platformsprite);
        window.display();
    }
    
    return 0;
}