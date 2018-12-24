#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "allclass.hpp"


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
    
    Texture menuBackground;//�������� �������� �������� ����
    menuBackground.loadFromFile("background.png");//�������� � �������� �� �����
    Sprite menuBg(menuBackground);//������
    
    menuButton.setPosition(512, 260);
    menuBg.setPosition(0, 0);
    

        menuNum = 0;
        menuButton.setColor(Color::White);
        window.clear(Color(129, 181, 221));
        
   

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
    
    
        menuNum = 0;
        menuButton.setColor(Color::White);
        window.clear(Color(129, 181, 221));
        
        if (IntRect(512, 160, 300, 50).contains(Mouse::getPosition(window))) { menuButton.setColor(Color::Red); menuNum = 1; }
        
        
        window.draw(menuBg);
        window.draw(menuButton);
        window.display();
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

        
        menu1.setColor(Color::White); //������ ���� �������
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
       
        window.clear(Color(129, 181, 221)); //���������� ������
        
        if (IntRect(512, 260, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; } // ������ ������������� ������ � ����� ��������� ��������� ����
        if (IntRect(512, 360, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
        if (IntRect(512, 460, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }
        


        window.draw(menuBg); //��������� ����
        window.draw(menu1);  //��������� ������
        window.draw(menu2);
        window.draw(menu3);

        window.display();
    }
}

    
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
        
        
        float CurrentFrame = 0;  //������ ������� ���� ��� ��������
        Clock clock; //�����
        
       
            
                