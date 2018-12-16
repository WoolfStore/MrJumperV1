//
//  core.cpp
//  sfml test


#include "core.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

class Hero {
public:
    int x;
    int y;
    float lives;
};

struct Platform {
    int x;
    int y;
};

struct Enemy{
    int x;
    int y;
};

struct Bullet{
    int x;
    int y;
};

Hero mainHero; // Создание главного героя
Platform platform;
Platform movingPlatform;

Platform arrayOfPlatforms[9];

Enemy ghost;
Bullet enemyBullet;
Bullet heroBullet;

int quantityOfPlatforms = 1;

int convertYCoordinate(int y){
    return(720 - y);
}



void startGame(int x, int y){
    
    mainHero.x = x;
    mainHero.y = convertYCoordinate(y);
    mainHero.lives = 3;
    
}



void getPlatformCoordinates(int x1, int y1, int x2, int y2){
    platform.x = x1;
    platform.y = convertYCoordinate(y1);
    movingPlatform.x = x2;
    movingPlatform.y = convertYCoordinate(y2);
    arrayOfPlatforms[quantityOfPlatforms - 1] = platform;
    quantityOfPlatforms += 1;
}

void changePositionOfMovingPlatform(int x, int y){
    movingPlatform.x = x;
    movingPlatform.y = convertYCoordinate(y);
}

void changeHeroPosition(int x, int y){
    
    mainHero.x = x;
    mainHero.y = convertYCoordinate(y);
    
}

int gameOver(){
    if (mainHero.lives == 0) {
        return 2;
    }
    if (mainHero.y <= 32){
        
        mainHero.lives -= 0.5;
        
        cout << mainHero.lives << "\n";
        return 1;
    }
    return 0;
}


int onGround(){// возвращает 1 если стоит на колонне, 2 если стоит на двигующейся платформе, 0 если не стоит
    
    for (int i = 0; i < quantityOfPlatforms; i++){
        if ((mainHero.x >= arrayOfPlatforms[i].x && mainHero.x <= arrayOfPlatforms[i].x + 256) && (mainHero.y - 128 <= arrayOfPlatforms[i].y))
            return 1;
    }
    
    
    
    if ((mainHero.x >= movingPlatform.x && mainHero.x <= movingPlatform.x + 256) && (mainHero.y - 128 <= movingPlatform.y)){
        return 2;
    }
    
    return 0;
    
}

void changeEnemyPosition(int x, int y){
    ghost.x = x;
    ghost.y = convertYCoordinate(y);
}

void changeEnemyBulletPosition(int x, int y){
    enemyBullet.x = x;
    enemyBullet.y = convertYCoordinate(y);
}

void changeHeroBulletPostion(int x, int y){
    heroBullet.x = x;
    heroBullet.y = convertYCoordinate(y);
}


int crash() { // столкновение с двигающийся платформой
    if ((mainHero.y - 128 >= platform.y) || (mainHero.y <= platform.y - 64)){
        if (mainHero.x + 64 >= movingPlatform.x + 256+64 && mainHero.x + 64 <= movingPlatform.x + 256+64+5)
            return 1;
        else
            if (mainHero.x >= movingPlatform.x - 69 && mainHero.x <= movingPlatform.x - 64 )
                return 2;
    }
    return 0;
}

void fightWithAShadow(int width, int height){
    if ((mainHero.x <= ghost.x + width && mainHero.x + 64 >= ghost.x) && (mainHero.y - 128 <= ghost.y) && (mainHero.y >= ghost.y - height)) mainHero.lives -= 1;
}

void comradYouHaveAHole(){
    if ((mainHero.x + 64) >= enemyBullet.x >= mainHero.x - 16) mainHero.lives -= 1;
}

bool niceShoot(int width, int height){
    if ((ghost.x + 15 <= heroBullet.x + width) && (heroBullet.x <= ghost.x + width - 15) && (heroBullet.y - 14 >= ghost.y - height) && (heroBullet.y <= ghost.y)){
        ghost.x = -100;
        ghost.y = -100;
        return true;
    }
    return false;
}

bool stopPlatform(){
    if (onGround() == 2){
        if (platform.x - 240 <= movingPlatform.x <= platform.x + 495) return true;
    }
    return false;
}

int heroLives(){
    return mainHero.lives;
}

int objectGenerator(){
    int a = rand() % (quantityOfPlatforms + 4) +1;
    if (a == 1){
        return 1;
    }
    if (a > 7){
        return 4;
    }
    if (a > 3 && a < 7){
        return 3;
    }
    if (a >= 2 && a < 4){
        return 2;
    }
    return 0;
}

int stop(){ // 1 - right 2 - left, 3 - top 0 - ok
    if (mainHero.x <= 0) return 2;
    if (mainHero.x + 64 >= 1280) return 1;
    if (mainHero.y >= 720) return 3;
    
//    for (int i = 0; i < quantityOfPlatforms; i++){
//        if ((arrayOfPlatforms[i].y >= mainHero.y) && ((arrayOfPlatforms[i].y - 64) <= (mainHero.y - 128))){
//            if (mainHero.x <= arrayOfPlatforms[i].x + 256) return 2;
//            if (mainHero.x + 64 >= arrayOfPlatforms[i].x) return 1;
//        }
//    }
    return 0;
}



























