#include "StdAfx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "allclass.hpp"
#include <vector>
#include <list>
using namespace sf;
using namespace std;

int NumOfWindow = 1;

void finishGame (RenderWindow & window){
    
    Music music;//������� ������ ������
    music.openFromFile("won queen.wav");//��������� ����
    music.play();//������������� ������
    
    Font font;//�����
    font.loadFromFile("12838.ttf");//�������� ������ ������ ���� ������
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
}

void EndGame (RenderWindow & window){
    
    Music music;//������� ������ ������
    music.openFromFile("death .wav");//��������� ����
    music.play();//������������� ������
    
    Font font;//�����
    font.loadFromFile("12838.ttf");//�������� ������ ������ ���� ������
    Text menuButton("", font, 70);
    menuButton.setString("GAME OVER");
    
    Texture menuBackground;
    menuBackground.loadFromFile("background.png");
    Sprite menuBg(menuBackground);
    
    menuButton.setPosition(512, 160);
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
        
        if (IntRect(512, 160, 300, 50).contains(Mouse::getPosition(window))) { menuButton.setColor(Color::Red); menuNum = 1; }
        
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
}

void menu (RenderWindow & window) {  
    
    Music music;//������� ������ ������
    music.openFromFile("menu queen.wav");//��������� ����
    music.play();//������������� ������

    Font font;//�����
    font.loadFromFile("12838.ttf");//�������� ������ ������ ���� ������
    Text menu1("", font, 70);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    Text menu2("", font, 70);
    Text menu3("", font, 70);
    menu1.setString("START GAME");
    menu2.setString("VIEW SCORE");
    menu3.setString("EXIT GAME");

    Texture menuBackground;
    menuBackground.loadFromFile("background.png");
    Sprite menuBg(menuBackground);
    bool isMenu = 1; //�������� �� ������� ���� ���� //�� ������ ��������� � ����
    int menuNum = 0; //�������� ���������� �� ������ �����
    menu1.setPosition(512, 260); // ������ ��������� ������������
    menu2.setPosition(512, 360);
    menu3.setPosition(512, 460);
    menuBg.setPosition(0, 0);

    ////////////////////////////����///////////////////
    while (isMenu)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // ��� ����� �� ��������
                window.close();
        }
        
        menu1.setColor(Color::White); //������ ���� �������
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0; //��� ���� ����� ����������� ���� ������ ���� ����
        window.clear(Color(129, 181, 221)); //���������� ������
        
        if (IntRect(512, 260, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; } // ������ ������������� ������ � ����� ��������� ��������� ����
        if (IntRect(512, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
        if (IntRect(512, 460, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }
        
        if (Mouse::isButtonPressed(Mouse::Left)) //���� ������ ����� ������ ����� �� ���������� �������
        {
            if (menuNum == 1) { 
                isMenu = false;//���� ������ ������ ������, �� ������� �� ���� //����� �� �����
                NumOfWindow = 2;
            }
            if (menuNum == 3)  { window.close(); isMenu = false; } // �������� ���� ����������
            
        }

        window.draw(menuBg); //��������� ����
        window.draw(menu1);  //��������� ������
        window.draw(menu2);
        window.draw(menu3);

        window.display();
    }
}

    void GameBegins (RenderWindow & window){
        bool dirhero = true; //���������� ���������� �� ��������� ���� (�����������), ���� ������ ������ = ���, � ����� = ����
        int on_ground; //���������� 1 ���� ����� �� ���������, 2 ���� �� ����������, 0 ���� �� �� �����
        bool stopPlatform2 = false; //��������� ��������� (���� ������ ��� ��������� ���������)
        bool platformMove = true;   //�������� ��������� (���-�����, ����- �����) 
        bool onMovingPlatform = false; //�� ��������� �� ����. ���������
        bool enemyLive = false; //��� ������
        int countOfPlatform = 1; // ���-�� �������� �� ������
        float MASSIVEX[9];       // 2 ������� �������� x � y (�������� ��������� �������� ������� �� ����������) 
        float MASSIVEY[9];
        MASSIVEX[0] = 512;       //���������� 0� ���������
        MASSIVEY[0] = 720-64;
        bool generatebullet = false; //������� ����. ���� - �� ����
        bool youCanShoot = true; //�� ������ �������� ������ = �������
        bool platformCantMove = false; //���������� ���������������� ���������
        int HeroCanJump = 1; // ������ ������ (�� �����)
        int a;
        bool generateEnemyBullet = false; //�������� ��������� ����
        bool OperationWithPlatforms = false; //� ����� ��������� �������� � �����������
        
        Music music;//������� ������ ������
        music.openFromFile("8 bit.wav");//��������� ����
        music.play();//������������� ������
        
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
        
        Image heroimage;
        heroimage.loadFromFile("mainhero.png");
        
        
        Texture herotexture;
        herotexture.loadFromImage(heroimage);
        
        Sprite herosprite;
        herosprite.setTexture(herotexture);
        herosprite.setTextureRect(IntRect(0, 0, 64, 128));
        herosprite.setPosition(592, 720-128-64);
        
        startGame(herosprite.getPosition().x, herosprite.getPosition().y); // ������� ������� �������� ��������� ���������� ���������
        platform p1(512, 720 - 64); 
        platform p2(-256, 720-128);
        getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
        platform SPRITE(512, 720-64); //������������ ��� ��������� ������� �������� 
        enemy e1(0, 0); //������ 1 ������� 
        enemy2 e2(0, 0);
        enemy3 e3(0, 0);
        bullet pow(herosprite.getPosition().x + 64, herosprite.getPosition().y + 64); //����� ����. ������ pow 
        bullet enemystrikes(e3.enemysprite.getPosition().x + 64, e3.enemysprite.getPosition().y + 64); //����� ���� �����
        enemystrikes.bulletsprite.setColor(sf::Color(0,255,255,255)); //������ ����.������ �������.����� ����
        
        e1.enemyMove = false;  //��������� ��������� ��������
        e1.enemyLive = false;
        e2.enemyMove = false;
        e2.enemyLive = false;
        e3.enemyLive = false;
        pow.dirBullet = 1;    //����������� ����. ������ ������
        pow.bulletLive = false; //����� ����
        enemystrikes.bulletLive = false; 
        e1.lives = 2; //����� �������� 
        e2.lives = 4;
        e3.lives = 4;
        
        float CurrentFrame = 0;  //������ ������� ���� ��� ��������
        Clock clock; //�����
        
        int p = 0; 
        bool GameNotOver = true; //����� ���������� ����
        while (GameNotOver){ 
            
            a = rand() % 2 +1; //��������� ���������� ��� ��������� �������� � �������� %2 - 2 �����
            on_ground = onGround(); //����� ������� �� core.cpp
            
            if (gameOver(enemyLive) == 2) { 
                cout << finish();
                NumOfWindow = 4;
                GameNotOver = false;
            }
            
            if (countOfPlatform == 8){
                NumOfWindow = 3;
                GameNotOver = false;
            }
            
            if (gameOver(enemyLive) == 1) {
                if (!platformCantMove)
                {
                    herosprite.setPosition(p1.platformsprite.getPosition().x + 128-32, p1.platformsprite.getPosition().y-128); //������� ����� ��� ��� ���������
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y); //�������� ���������� � core.cpp
                }
                else{
                    herosprite.setPosition(p2.platformsprite.getPosition().x + 128-32, p2.platformsprite.getPosition().y-128);
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                }
                
                if (countOfPlatform == 2 && enemyLive){  //�������� � ����������� ����� ��������
                    countOfPlatform -= 1;
                    OperationWithPlatforms = true;
                }
                if (countOfPlatform > 2 && enemyLive){
                    countOfPlatform -= 1;
                    OperationWithPlatforms = true;
                }
                if (countOfPlatform > 3){
                    countOfPlatform -= 2;
                    OperationWithPlatforms = true;
                }
                
                if ((countOfPlatform != 1) || OperationWithPlatforms){    // ���������� �������� �� ���������
                    p1.platformsprite.setPosition(MASSIVEX[countOfPlatform-1], MASSIVEY[countOfPlatform-1]);
                    if (a == 1)
                        p2.platformsprite.setPosition(-256, 720 - 64 -64- 64 * (countOfPlatform-1));
                    else
                        if (a == 2 )
                            p2.platformsprite.setPosition(1280, 720 - 64 - 64 - 64 * (countOfPlatform-1));
                    getPlatformCoordinates(p1.platformsprite.getPosition().x, p1.platformsprite.getPosition().y, p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
                    herosprite.setPosition(MASSIVEX[countOfPlatform-1]+128-32, MASSIVEY[countOfPlatform-1] - 128);
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                    stopPlatform2 = false;
                    onMovingPlatform = false;
                    platformCantMove = false;
                    changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                    OperationWithPlatforms = false;
                    e1.enemyLive = false;
                    e2.enemyLive = false;
                    e3.enemyLive = false;
                }
            }
            float time = clock.getElapsedTime().asMicroseconds(); // ���� ����� � ������������� 
            clock.restart(); 
            time = time / 1200;
            
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            
            ///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
            
            if ((((Keyboard::isKeyPressed(Keyboard::Left)) && (crash() == 0)) || ((Keyboard::isKeyPressed(Keyboard::Left)) && (enemyLive))) && (stop() != 2)) { //���� ������ ������� ������� �����
                CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
                if (CurrentFrame > 6) CurrentFrame -= 6; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
                herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 256, 64, 128)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96
                herosprite.move(-0.2*time, 0); //������� ������ ����� �� � (��������)
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                dirhero = false;
            }
            
            if ((((Keyboard::isKeyPressed(Keyboard::Right)) && (crash() == 0)) || ((Keyboard::isKeyPressed(Keyboard::Right)) && (enemyLive))) && (stop() !=2)) {
                CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
                if (CurrentFrame > 6) CurrentFrame -= 6; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
                herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 384, 64, 128)); //
                herosprite.move(0.2*time, 0);//���������� ���� �������� ��������� ������
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                dirhero = true;
            }
            
            if ((Keyboard::isKeyPressed(Keyboard::Space)) && (stop() != 3) && !endOfJump() && HeroCanJump == 1) {
                herosprite.move(0, -0.8*time);
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
                herosprite.setTextureRect(IntRect(0, 0, 64, 128)); //������ �������� �������� �����
            }
            
            if (endOfJump() && on_ground == 0) //�� ����� ������� � �������
                HeroCanJump = 0;
            
            if (on_ground !=0)      //����� ������� �� ���������
                HeroCanJump = 1;
            
            // ����

			  std::list<bullet*>  bullets;
			std::list<bullet*>::iterator bb;

				bullets.push_back(new bullet( 32, 14));
		for (bb = bullets.begin(); bb != bullets.end(); bb++){
			(*bb)->pow.dirBullet(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
			}
						
			
            
            if ((Keyboard::isKeyPressed(Keyboard::A) && youCanShoot)){ //��������
                youCanShoot = false;
                if (dirhero)
                    pow.dirBullet = 1;
                else
                    pow.dirBullet = -1;
                generatebullet = true;
            }
          
			
            if (generatebullet){  //��������� ����
                pow.bulletLive = true;
                if (pow.dirBullet == 1)
                    pow.bulletsprite.setScale(1, 1);
                else
                    pow.bulletsprite.setScale(-1, 1);
                pow.bulletsprite.move(0.8 * pow.dirBullet * time, 0);
                changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
                if (pow.bulletsprite.getPosition().x > 1280 || pow.bulletsprite.getPosition().x < 0){
                    pow.bulletLive = false;
                }
            }
            
            if (!pow.bulletLive){ //�������� ����
                pow.bulletsprite.setPosition(herosprite.getPosition().x + 64, herosprite.getPosition().y + 64);
                changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
                generatebullet = false;
                youCanShoot = true;
            }
            
            
            
            // �������� � ��������� ���������
            
            if (stopPlatform()){
                stopPlatform2 = true;
                platformCantMove = true;
            }
            else
                stopPlatform2 = false;
            if (p2.platformsprite.getPosition().x >= 1280-256)
                platformMove = false;
            if (p2.platformsprite.getPosition().x <= 0)
                platformMove = true;
            if (!stopPlatform2 && !platformCantMove ){
                if (platformMove)
                    p2.platformsprite.move (0.4*time, 0);
                else
                    p2.platformsprite.move (-0.4*time, 0);
                changePositionOfMovingPlatform(p2.platformsprite.getPosition().x, p2.platformsprite.getPosition().y);
            }
            
            p = objectGenerator();
            //   p = 1;
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
                    platformCantMove = false;
                }
                if (p==2 && (!enemyLive)){
                    e1.enemyLive = true;
                    e1.lives = 4;
                    if (a == 1)
                        e1.enemysprite.setPosition(-48, 720-64-64 -24 -64 * countOfPlatform);
                    else
                        e1.enemysprite.setPosition(1280, 720-64-64 -24 -64 * countOfPlatform);
                    changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
                }
                if (p==3 && (!enemyLive)){
                    e2.enemyLive = true;
                    e2.lives = 2;
                    if (a == 1)
                        e2.enemysprite.setPosition(-64, 720-64-64-24-64 * countOfPlatform);
                    else
                        e2.enemysprite.setPosition(1280, 720-64-64-24-64 * countOfPlatform);
                    changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
                }
                if (p==4 && (!enemyLive)){
                    e3.enemyLive = true;
                    generateEnemyBullet = true;
                    e3.lives = 4;
                    if (a == 1){
                        e3.enemysprite.setPosition(0, 720-64-128-64 * countOfPlatform);
                        enemystrikes.dirBullet = 1;
                        enemystrikes.bulletsprite.setPosition(e3.enemysprite.getPosition().x + 128, e3.enemysprite.getPosition().y + 64);
                    }
                    else{
                        e3.enemysprite.setPosition(1280 - 128, 720-64-128-64 * countOfPlatform);
                        enemystrikes.dirBullet = -1;
                        enemystrikes.bulletsprite.setPosition(e3.enemysprite.getPosition().x - 32, e3.enemysprite.getPosition().y + 64);
                    }
                    changeEnemyBulletPosition(enemystrikes.bulletsprite.getPosition().x, enemystrikes.bulletsprite.getPosition().y);
                    changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
                }
            }
            
            if ((on_ground == 0) && (p1.platformsprite.getPosition().y - herosprite.getPosition().y) < 720){
                herosprite.move(0, 0.3*time);
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            }
            
            // �������� ��������� � ����������
            
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
            
            // ��������� ������ �1, �2, �3
            if (e1.enemyLive){
                if (e1.enemysprite.getPosition().x > 1280-48)
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
                    e1.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                }
                if (e1.lives == 0)
                    e1.enemyLive = false;
            }
            
            if (e2.enemyLive){
                if (e2.enemysprite.getPosition().x > 1280-64)
                    e2.enemyMove = true;
                if (e2.enemysprite.getPosition().x < 0)
                    e2.enemyMove = false;
                if (!e2.enemyMove){
                    e2.enemysprite.setScale(-1, 1);
                    e2.enemysprite.move(0.6 * time, 0);
                    changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
                }
                if (e2.enemyMove){
                    e2.enemysprite.setScale(1, 1);
                    e2.enemysprite.move(-0.6 * time, 0);
                    changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
                }
                fightWithAShadow(64,64);
                if (niceShoot(64,64) && generatebullet){
                    e2.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                }
                if (e2.lives == 0)
                    e2.enemyLive = false;
            }
            
            if (e3.enemyLive){
                if (generateEnemyBullet){
                    enemystrikes.bulletLive = true;
                }
                
                if (enemystrikes.bulletLive){
                    if (enemystrikes.dirBullet == 1)
                        enemystrikes.bulletsprite.setScale(1, 1);
                    else
                        enemystrikes.bulletsprite.setScale(-1, 1);
                    enemystrikes.bulletsprite.move(0.6 * enemystrikes.dirBullet * time, 0);
                    changeEnemyBulletPosition(enemystrikes.bulletsprite.getPosition().x, enemystrikes.bulletsprite.getPosition().y);
                    if (enemystrikes.bulletsprite.getPosition().x > 1280 || enemystrikes.bulletsprite.getPosition().x < 0){
                        enemystrikes.bulletLive = false;
                    }
                }
                if (niceShoot(128,128) && generatebullet){
                    e3.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                    changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
                }
                if (e3.lives == 0)
                    e3.enemyLive = false;
                if (!enemystrikes.bulletLive){
                    generateEnemyBullet = true;
                    enemystrikes.bulletsprite.setPosition(e3.enemysprite.getPosition().x + 128, e3.enemysprite.getPosition().y + 64);
                    changeEnemyBulletPosition(enemystrikes.bulletsprite.getPosition().x, enemystrikes.bulletsprite.getPosition().y);
                }
                if (comradYouHaveAHole())
                    enemystrikes.bulletLive = false;
            } else enemystrikes.bulletLive = false;
            
            // ��������� ������� �����
            
            if (crash()==1 && on_ground==1 && !platformCantMove){
                herosprite.move(0.4 * time, 0);
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            }
            else{
                if (crash()==2 && on_ground==1 && !platformCantMove)
                    herosprite.move(-0.4 * time, 0);
                changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            }
            
            window.clear();
            window.draw(backgroundsprite);
            window.draw(poisonsprite);
            window.draw(herosprite);
            window.draw(p1.platformsprite);
            window.draw(p2.platformsprite);
            
            /////////////��������////////////
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
            if (enemystrikes.bulletLive)
                window.draw(enemystrikes.bulletsprite);
            for (int a = 0; a < heroLives(); a++){
                heartsprite.setPosition(1280-192+64*a, 10);
                window.draw(heartsprite);
            }
            
            window.display();
            
        }
        
    }

int main()
{
   
    RenderWindow window(sf::VideoMode(1280, 720), "Mr.Jumper");  //������� ���� ��������� window
    
    while (window.isOpen()) //������� ���� ���� "���� ���� �������"
    {
        sf::Event event;   // ������� ������� ����
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (NumOfWindow == 1) // NumOfWindow ���������� ����� ���� // menu
            menu(window);
        if (NumOfWindow == 2) //����
            GameBegins(window);
        if (NumOfWindow == 3) // ����� ����
            finishGame(window);
        if (NumOfWindow == 4) // ����� �� ����
            EndGame(window);
        
        }
    return 0;
}

