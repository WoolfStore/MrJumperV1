

#include "core.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

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

int score = 0;
int newY = 0;
string name = "Mr.Jumper";

Hero mainHero; // Создание главного героя
Platform platform;
Platform movingPlatform;

Platform arrayOfPlatforms[9];

Enemy ghost;
Bullet enemyBullet;
Bullet heroBullet;

int quantityOfPlatforms = 1;
int control = 0;

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

int gameOver(bool enemyAlive){
    if (mainHero.lives <= 0) {
        return 2;
    }
    if (mainHero.y - 32 <= 32){
        
        mainHero.lives -= 0.5;
        
        if (quantityOfPlatforms == 2 && enemyAlive && (mainHero.lives == 2 || mainHero.lives == 1)){
            quantityOfPlatforms -= 1;
        }
        if (quantityOfPlatforms > 2 && enemyAlive && (mainHero.lives == 2 || mainHero.lives == 1)){
            quantityOfPlatforms -= 1;
        }
        if (quantityOfPlatforms >= 3 && (mainHero.lives == 2 || mainHero.lives == 1)){
            quantityOfPlatforms -= 2;
        }
        
        
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
    if ((mainHero.x + 15 <= ghost.x + width && mainHero.x + 49 >= ghost.x) && (mainHero.y - 118 <= ghost.y) && (mainHero.y - 15 >= ghost.y - height)) mainHero.lives -= 3;
}

bool comradYouHaveAHole(){
    if (mainHero.x + 64 >= enemyBullet.x && mainHero.x <= enemyBullet.x + 15 && enemyBullet.y <= mainHero.y && enemyBullet.y >= mainHero.y - 128) {
        mainHero.lives -= 1;
        enemyBullet.x = -100;
        enemyBullet.y = -100;
        return true;
    }
    return false;
}

bool niceShoot(int width, int height){
    if ((ghost.x + 15 <= heroBullet.x + width) && (heroBullet.x <= ghost.x + width - 15) && (heroBullet.y - 14 >= ghost.y - height) && (heroBullet.y <= ghost.y)){
        ghost.x = -100;
        ghost.y = -100;
        score += 1;
        return true;
    }
    return false;
}

bool stopPlatform(){
    if (onGround() == 2){
        if (movingPlatform.x + 240 >= platform.x && movingPlatform.x <= platform.x + 240) return true;
        score += 1;
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
    
    for (int i = 0; i < quantityOfPlatforms; i++){
        if ((arrayOfPlatforms[i].y <= mainHero.y) && (arrayOfPlatforms[i].y - 64 >= mainHero.y - 128)){
            if (arrayOfPlatforms[i].x <= mainHero.x + 64){
                return 1;
            }
            if (arrayOfPlatforms[i].x + 256 <= mainHero.x){
                return 2;
            }
        }
    }
    return 0;
}

int whatIsScore(){
    return score;
}

int finish(){
    if (mainHero.lives == 3) score += 10;
    if (mainHero.lives == 2) score += 5;
    if (mainHero.lives == 1) score += 3;
    score += 10; 
    cout << score;
    //file.close();
    fclose(stdout);
    return score;
}

bool endOfJump(){
    if (onGround() != 0){
        newY = mainHero.y;
        return false;
    } else {
        if (mainHero.y - newY >= 200){
            return true;
        }
    }
    return false;
}

void whatIsQuantityOfPlatform(int count){
    quantityOfPlatforms = count;
}

















