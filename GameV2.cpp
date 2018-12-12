#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"

using namespace sf;
using namespace std;

class platform {
public:
    float x, y, w, h = 0;
    Image image;
    Texture texture;//сфмл текстура
    Sprite platformsprite;//сфмл спрайт
    
    platform(float X, float Y){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
        image.loadFromFile("Resources/platform.jpg");
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        platformsprite.setTexture(texture);//заливаем спрайт текстурой
        x = X; y = Y;//координата появления спрайта
//      platformsprite.setColor(sf::Color(128, 128, 255, 255));
        platformsprite.setTextureRect(IntRect(0, 0, 256, 64));
        platformsprite.setPosition(x,y);
    }
};

class enemy {
public:
    float x,y,w,h = 0;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy(float X, float Y){
        image.loadFromFile("Resources/bones.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        x = X; y = Y;
        enemysprite.setTextureRect(IntRect(48, 128, 48, 64));
        enemysprite.setPosition(x, y);
    }
};

class enemy2 {
public:
    float x,y,w,h = 0;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy2(float X, float Y){
        image.loadFromFile("Resources/ghost.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        x = X; y = Y;
        enemysprite.setTextureRect(IntRect(64, 48, 64, 64));
        enemysprite.setPosition(x, y);
    }
};

class enemy3 {
public:
    float x,y,w,h = 0;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy3(float X, float Y){
        image.loadFromFile("Resources/ghost.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        x = X; y = Y;
        enemysprite.setTextureRect(IntRect(64*16, 16, 128, 128));
        enemysprite.setPosition(x, y);
    }
};

int main()
{
    bool stayOnStatic = true;
    bool on_ground = false;
    bool stopPlatform2 = false;
    bool heroJump = false;
    bool platformMove = true;
    bool onMovingPlatform = false;
    bool enemyMove = false;
    bool enemyLive = true;
    int countOfPlatform = 1;
    float MASSIVEX[9];
    float MASSIVEY[9];
    MASSIVEX[0] = 512;
    MASSIVEY[0] = 720-64;
    

    RenderWindow window(sf::VideoMode(1280, 720), "EASY GAME 228");
    
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("Resources/background.png");
    
    Sprite backgroundsprite;
    backgroundsprite.setTexture(backgroundtexture);
    backgroundsprite.setTextureRect(IntRect(0, 0 , 1280, 720));
    backgroundsprite.setPosition(0, 0);
    backgroundsprite.setColor(sf::Color(196, 0, 0, 255));
    
    Texture poisontexture;
    poisontexture.loadFromFile("Resources/poison.png");
    
    Sprite poisonsprite;
    poisonsprite.setTexture(poisontexture);
    poisonsprite.setTextureRect(IntRect(0,0,1279,64));
    poisonsprite.setPosition(0, 720-64);
    poisonsprite.setColor(sf::Color(0, 196, 0, 196));
    
    Texture herotexture;
    herotexture.loadFromFile("Resources/hero2.png");
    
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(32, 128, 64, 128));
    herosprite.setPosition(592, 720-128-64);
    
    startGame(herosprite.getPosition().x, herosprite.getPosition().y);
    platform p1(512, 720 - 64);
    platform p2(0, 720-128);
    getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
    platform SPRITE(512, 720-64);
    enemy e1(512, 512);
    enemy2 e2(256, 256);
    enemy3 e3(400, 400);
    
    float CurrentFrame = 0;  //хранит текущий кадр
    Clock clock;
    
    while (window.isOpen())
    {
       
        on_ground = onGround();
        
        if (p1.platformsprite.getPosition().y < herosprite.getPosition().y - 127 < p1.platformsprite.getPosition().y - 145) // если стоит на первой платформе (которая всегда в статичном положении), то он статичен
            stayOnStatic = true;
        
        if (on_ground && (p2.platformsprite.getPosition().y < herosprite.getPosition().y - 127 < p2.platformsprite.getPosition().y - 145) && ((p2.platformsprite.getPosition().x < herosprite.getPosition().x < p2.platformsprite.getPosition().x + 256))){
            onMovingPlatform = true; // если персонаж находится в зоне второй платформы, то он двигается вместе с ней
            stayOnStatic = false;
        } else {
            onMovingPlatform = false;
            stayOnStatic = true;
        }
        
        if (gameOver() == 2) {
            window.close();
        }
        
        if (gameOver() == 1) {
            herosprite.setPosition(640, 512);
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
//                        herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 128, 128, 128)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            
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
        if (!stopPlatform2){
            if (platformMove){
                p2.platformsprite.move (0.2*time, 0);
                if ((p1.platformsprite.getPosition().x + 256 + 250 > p2.platformsprite.getPosition().x > p1.platformsprite.getPosition().x - 250) && onMovingPlatform){
                    stopPlatform2 = true;
                }
            }
            else
                p2.platformsprite.move (-0.2*time, 0);
//                if ((p2.platformsprite.getPosition().x <= 512+256) && onMovingPlatform){
//                    stopPlatform2 = true;
//                }
//            }
            changePositionOfMovingPlatform(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
        }
        
        if (stopPlatform2){
            MASSIVEX[countOfPlatform] = p2.platformsprite.getPosition().x;
            MASSIVEY[countOfPlatform] = p2.platformsprite.getPosition().y;
            p1.platformsprite.setPosition(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
            p2.platformsprite.setPosition(0, 720 - 64 - 64 - 64 * countOfPlatform);
            getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
            stopPlatform2 = false;
            onMovingPlatform = false;
            stayOnStatic = true;
            countOfPlatform += 1;
        }
        
        if (!on_ground && (p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 720){
            herosprite.move(0, 0.3*time);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        
        // ВРААААААААГ
        
        if (enemyLive){
            if (!enemyMove)
                e1.enemysprite.move(-0.1 * time, 0);
            if (e1.enemysprite.getPosition().x < 0)
                enemyMove = false;
            if (enemyMove)
                e1.enemysprite.move(0.1 * time, 0);
            if (e1.enemysprite.getPosition().x > 1280)
                enemyMove = true;
        }
        
        // ДВИЖЕНИЕ ПЕРСОНАЖА С ПЛАТФОРМОЙ
        
        if (onMovingPlatform){
            if (!stayOnStatic)
            if (!stopPlatform2){
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
        window.draw(backgroundsprite);
        window.draw(poisonsprite);
        window.draw(herosprite);
        window.draw(p1.platformsprite);
        window.draw(p2.platformsprite);
        
        /////////////набросок////////////
        for (int i = 0; i <= countOfPlatform; i++){
            SPRITE.platformsprite.setPosition(MASSIVEX[i], MASSIVEY[i]);
            window.draw(SPRITE.platformsprite);
        }
        
        if (enemyLive)
            window.draw(e1.enemysprite);
        window.draw(e2.enemysprite);
        window.draw(e3.enemysprite);
        window.display();
    }
    
    return 0;
}
