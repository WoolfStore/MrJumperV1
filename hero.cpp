#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "allclass.hpp"


using namespace sf;
using namespace std;

i
        
        Image heroimage;
        heroimage.loadFromFile("mainhero.png");
        
        
        Texture herotexture;
        herotexture.loadFromImage(heroimage);
        
        Sprite herosprite;
        herosprite.setTexture(herotexture);
        herosprite.setTextureRect(IntRect(0, 0, 64, 128));
        herosprite.setPosition(592, 720-128-64);
        
        startGame(herosprite.getPosition().x, herosprite.getPosition().y); // Функция которые передают начальные координаты персонажа
        platform p1(512, 720 - 64); 
        platform p2(-256, 720-128);
       