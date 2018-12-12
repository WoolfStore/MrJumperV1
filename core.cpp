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

Hero mainHero; // Создание главного героя
Platform platform;
Platform movingPlatform;

Platform arrayOfPlatforms[9];

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
    quantityOfPlatforms += 1;
    platform.x = x1;
    platform.y = convertYCoordinate(y1);
    movingPlatform.x = x2;
    movingPlatform.y = convertYCoordinate(y2);
    for (int i = 0; i < quantityOfPlatforms; i++){
        arrayOfPlatforms[i] = platform;
    }
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


bool onGround(){
    
    for (int i = 0; i < quantityOfPlatforms; i++){
        if ((mainHero.x >= arrayOfPlatforms[i].x && mainHero.x <= arrayOfPlatforms[i].x + 256) && (mainHero.y - 128 == arrayOfPlatforms[i].y))
            return true;
    }
    
    if ((mainHero.x >= movingPlatform.x && mainHero.x <= movingPlatform.x + 256) && (mainHero.y - 128 == movingPlatform.y)){
        return true;
    }
    return false;
}





