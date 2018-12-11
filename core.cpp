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

Platform platform;

int matrix[20][20];

int convertYCoordinate(int y){
    return(1280 - y - 1);
}

void newPlatform(int x, int y){
    platform.x = x;
    platform.y = convertYCoordinate(y);
}

Hero mainHero; // Создание главного героя

void startGame(int x, int y){
    
    mainHero.x = x;
    mainHero.y = convertYCoordinate(y);
    mainHero.lives = 3;
    
    for (int i = 0; i < 20; i++){ // забить всю матрицу нулями
        for (int c = 0; c < 20; c++){
            matrix[i][c] = 0;
        }
    }
    
    for (int i = 0; i < 20; i++){ // создание кислоты
        matrix[i][0] = 4;
    }
    
    matrix[mainHero.x/64][int(convertYCoordinate(y)/64)] = 5;
    matrix[mainHero.x/64][int(convertYCoordinate(y)/64) - 1] = 5;
    
    cout << "$$$" << mainHero.y << "$$$";
    
}

void pushPlatformIntoMatrix(int x, int y){
    
    int start = int(x/64);
    for (int i = 0; i < 20; i++){
        matrix[i][int(convertYCoordinate(y)/64)] = 0;
    }
    
    if (matrix[0][0] == 0){
        for (int i = 0; i < 20; i++){
            matrix[i][0] = 4;
        }
    }
    
    for (int i = 0; i < 4; i++){
        matrix[start+i][int(convertYCoordinate(y)/64)] = 1;
    }
    
 
    
    
    
    
    for (int i = 0; i < 20; i++){
        cout << '\n';
        for (int c = 0; c < 20; c++){
            cout << matrix[c][i];
        }
    }
    
    
}

void changeHeroPosition(int x, int y){
    int oldX = mainHero.x;
    int oldY = mainHero.y;
    matrix[oldX/64][(oldY/64)] = 0;
    matrix[oldX/64][(oldY/64)] = 0;
    mainHero.x = x;
    mainHero.y = convertYCoordinate(y);
    matrix[mainHero.x/64][int(convertYCoordinate(y)/64)] = 5;
    matrix[mainHero.x/64][int(convertYCoordinate(y)/64) - 1] = 5;
    
}

int gameOver(){
    if (mainHero.lives == 0) {
        return 2;
    }
    if ((matrix[(mainHero.x+50)/64][mainHero.y/64 - 2] == 4 || matrix[(mainHero.x)/64][mainHero.y/64 - 2] == 4)){
        
        mainHero.lives -= 0.5;
    
        cout << mainHero.lives << "\n";
        return 1;
    }
    return 0;
}



bool onGround(){ //ЕСЛИ РАЗНИЦА МЕЖДУ НАШИМ ГЕРОЕМ И ПЛАТФОРМОЙ > КАКОГО_ТО ЧИСЛА(128) ТО FALSE
    if (matrix[(mainHero.x)/64][mainHero.y/64 - 2] == 1) return true;
    else {
        return false;
    };
}





