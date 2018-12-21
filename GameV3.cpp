#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "allclass.hpp"

using namespace sf;
using namespace std;

int main()
{
    bool dirhero = true;
    int on_ground;
    bool stopPlatform2 = false;
    bool heroJump = false;
    bool platformMove = true;
    bool onMovingPlatform = false;
    bool enemyLive = false;
    int countOfPlatform = 1;
    float MASSIVEX[9];
    float MASSIVEY[9];
    MASSIVEX[0] = 512;
    MASSIVEY[0] = 720-64;
    bool generatebullet = false;
    
    
    
    Music music;//создаем объект музыки
    music.openFromFile("8 bit.wav");//загружаем файл
    music.play();//воспроизводим музыку
    
    RenderWindow window(sf::VideoMode(1280, 720), "Mr.Jumper");
    
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("background.png");
    
    Sprite backgroundsprite;
    backgroundsprite.setTexture(backgroundtexture);
    backgroundsprite.setTextureRect(IntRect(0, 0 , 1280, 720));
    backgroundsprite.setPosition(0, 0);
    backgroundsprite.setColor(sf::Color(196, 0, 0, 255));
    
    Texture hearttexture;
    hearttexture.loadFromFile("heart.png");
    
    Sprite heartsprite;
    heartsprite.setTexture(hearttexture);
    heartsprite.setTextureRect(IntRect(0, 0 , 1280, 720));
    heartsprite.setPosition(1280-64, 0);
    
    Texture poisontexture;
    poisontexture.loadFromFile("poison.png");
    
    Sprite poisonsprite;
    poisonsprite.setTexture(poisontexture);
    poisonsprite.setTextureRect(IntRect(0,0,1279,32));
    poisonsprite.setPosition(0, 720-32);
    poisonsprite.setColor(sf::Color(0, 196, 0, 196));
    
    Texture herotexture;
    herotexture.loadFromFile("hero2.png");
    
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(32, 128, 64, 128));
    herosprite.setPosition(592, 720-128-64);
    
    startGame(herosprite.getPosition().x, herosprite.getPosition().y);
    platform p1(512, 720 - 64);
    platform p2(-256, 720-128);
    getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
    platform SPRITE(512, 720-64);
    enemy e1(0, 0);
    enemy2 e2(0, 0);
    enemy3 e3(0, 0);
    bullet pow(herosprite.getPosition().x + 64, herosprite.getPosition().y + 64);
    
    e1.enemyMove = false;
    e1.enemyLive = false;
    e2.enemyMove = false;
    e2.enemyLive = false;
    e3.enemyMove = false;
    e3.enemyLive = false;
    pow.dirBullet = 1;
    pow.bulletLive = false;
    
    float CurrentFrame = 0;  //хранит текущий кадр
    Clock clock;
    
    int p = 0;
    
    while (window.isOpen())
    {
        
        on_ground = onGround();
        comradYouHaveAHole();
        
        if (gameOver() == 2) {
            window.close();
        }
        
        if (gameOver() == 1) {
            herosprite.setPosition(640, 512);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
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
        
        
       
        if ((Keyboard::isKeyPressed(Keyboard::Left)) && (crash() == 0) && (stop() != 2)) { //если нажата клавиша стрелка влево
            //            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //            if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            //            herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            herosprite.move(-0.2*time, 0);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            dirhero = false;
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Right)) && (crash()==0) && (stop() != 1)) {
            //                        CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //                        if (CurrentFrame > 4) CurrentFrame -= 4; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            //                        herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 128, 128, 128)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            herosprite.move(0.2*time, 0);//происходит само движение персонажа вправо
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            dirhero = true;
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Space)) && (stop() != 3)) {
            
            if (((p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 1024)){
                herosprite.move(0, -0.6*time);
                heroJump = true;
            }
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            
        }
        
        // Пуля
        
        if ((Keyboard::isKeyPressed(Keyboard::A))){
            if (dirhero)
                pow.dirBullet = 1;
            else
                pow.dirBullet = -1;
            generatebullet = true;
        }
        
        if (generatebullet){
            pow.bulletLive = true;
            pow.bulletsprite.move(0.4 * pow.dirBullet * time, 0);
            changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
            if (pow.bulletsprite.getPosition().x > 1280 || pow.bulletsprite.getPosition().x < 0){
                pow.bulletLive = false;
            }
        }
        
        if (!pow.bulletLive){
            pow.bulletsprite.setPosition(herosprite.getPosition().x + 64, herosprite.getPosition().y + 64);
            changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
            generatebullet = false;
        }
        
        
        
        // ДВИЖЕНИЕ И ОСТАНОВКА ПЛАТФОРМЫ
        
        if (stopPlatform())
            stopPlatform2 = true;
        else
            stopPlatform2 = false;
        if (p2.platformsprite.getPosition().x >= 1280-256)
            platformMove = false;
        if (p2.platformsprite.getPosition().x <= 0)
            platformMove = true;
        if (!stopPlatform2){
            if (platformMove)
                p2.platformsprite.move (0.2*time, 0);
            else
                p2.platformsprite.move (-0.2*time, 0);
            changePositionOfMovingPlatform(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
        }
        
        int a = rand() % 2 +1;
        
        p = objectGenerator();
        if (!e1.enemyLive && !e2.enemyLive && !e3.enemyLive)
            enemyLive = false;
        else
            enemyLive = true;
        
        if (stopPlatform2){
            if ((p==1) && (!enemyLive)){
                MASSIVEX[countOfPlatform] = p2.platformsprite.getPosition().x;
                MASSIVEY[countOfPlatform] = p2.platformsprite.getPosition().y;
                p1.platformsprite.setPosition(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
                if (a == 1)
                p2.platformsprite.setPosition(-256, 720 - 64 - 64 - 64 * countOfPlatform);
                else
                    if (a == 2 )
                       p2.platformsprite.setPosition(1280, 720 - 64 - 64 - 64 * countOfPlatform);
                getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
                stopPlatform2 = false;
                onMovingPlatform = false;
                countOfPlatform += 1;
            }
            if (p==2 && (!enemyLive)){
                e1.enemyLive = true;
                e1.enemysprite.setPosition(0, 720-64-64 -24 -64 * countOfPlatform);
                changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
            }
            if (p==3 && (!enemyLive)){
                e2.enemyLive = true;
                e2.enemysprite.setPosition(0, 720-64-64-24-64 * countOfPlatform);
                changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
            }
            if (p==4 && (!enemyLive)){
                e3.enemyLive = true;
                e3.enemysprite.setPosition(0, 720-64-128-64 * countOfPlatform);
                changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
            }
        }
        
        if ((on_ground == 0) && (p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 720){
            herosprite.move(0, 0.3*time);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        
        // ДВИЖЕНИЕ ПЕРСОНАЖА С ПЛАТФОРМОЙ
        
        if (on_ground == 2){
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
        
        // обработка первого враг
        if (e1.enemyLive){
            if (e1.enemysprite.getPosition().x > 1280)
                e1.enemyMove = true;
            if (e1.enemysprite.getPosition().x < 0)
                e1.enemyMove = false;
            if (!e1.enemyMove){
                e1.enemysprite.move(0.2 * time, 0);
                changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
            }
            if (e1.enemyMove){
                e1.enemysprite.move(-0.2 * time, 0);
                changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
            }
            fightWithAShadow(48,64);
            if (niceShoot(48,64) && generatebullet){
                e1.enemyLive = false;
                generatebullet = false;
                pow.bulletLive = false;
            }
        }
        
        if (e2.enemyLive){
            if (e2.enemysprite.getPosition().x > 1280)
                e2.enemyMove = true;
            if (e2.enemysprite.getPosition().x < 0)
                e2.enemyMove = false;
            if (!e2.enemyMove){
                e2.enemysprite.move(0.2 * time, 0);
                changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
            }
            if (e2.enemyMove){
                e2.enemysprite.move(-0.2 * time, 0);
                changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
            }
            fightWithAShadow(64,64);
            if (niceShoot(64,64) && generatebullet){
                e2.enemyLive = false;
                generatebullet = false;
                pow.bulletLive = false;
            }
        }
        
        if (e3.enemyLive){
            if (e3.enemysprite.getPosition().x > 1280)
                e3.enemyMove = true;
            if (e3.enemysprite.getPosition().x < 0)
                e3.enemyMove = false;
            if (!e3.enemyMove){
                e3.enemysprite.move(0.2 * time, 0);
                changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
            }
            if (e3.enemyMove){
                e3.enemysprite.move(-0.2 * time, 0);
                changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
            }
            fightWithAShadow(128,128);
            if (niceShoot(128,128) && generatebullet){
                e3.enemyLive = false;
                generatebullet = false;
                pow.bulletLive = false;
            }
        }
        
        // ПЛАТФОРМА ТОЛКАЕТ ПЕРСОНАЖА
        
        if (crash()==1 && on_ground==1){
            herosprite.move(0.2 * time, 0);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        else{
            if (crash()==2 && on_ground==1)
                herosprite.move(-0.2 * time, 0);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
        }
        
        window.clear();
        window.draw(backgroundsprite);
        window.draw(poisonsprite);
        window.draw(herosprite);
        window.draw(p1.platformsprite);
        window.draw(p2.platformsprite);
        
        /////////////набросок////////////
        for (int i = 0; i < countOfPlatform; i++){
            SPRITE.platformsprite.setPosition(MASSIVEX[i], MASSIVEY[i]);
            window.draw(SPRITE.platformsprite);
        }
        
        if (e1.enemyLive)
            window.draw(e1.enemysprite);
        if (e2.enemyLive)
            window.draw(e2.enemysprite);
        if (e3.enemyLive)
            window.draw(e3.enemysprite);
        if (pow.bulletLive)
            window.draw(pow.bulletsprite);
        for (int a = 0; a < heroLives(); a++){
            heartsprite.setPosition(1280-192+64*a, 10);
            window.draw(heartsprite);
        }
        
        window.display();
    }
    
    return 0;
}
