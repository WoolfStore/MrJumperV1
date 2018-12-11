//
//  core.hpp
//  sfml test


#ifndef core_hpp
#define core_hpp

#include <stdio.h>

void startGame(int x, int y);
void pushPlatformIntoMatrix(int x, int y);
void changeHeroPosition(int x, int y);
int gameOver();
bool onGround();


#endif /* core_hpp */
