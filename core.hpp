//
//  core.hpp
//  sfml test


#ifndef core_hpp
#define core_hpp

#include <stdio.h>

void startGame(int x, int y);
void getPlatformCoordinates(int x1, int y1, int x2, int y2);
void changePositionOfMovingPlatform(int x, int y);
void changeHeroPosition(int x, int y);
int gameOver();
int onGround();
void changeEnemyPosition(int x, int y); // Вызывать каждый раз при движении врага. (Принимает на борт координаты врага)
void changeEnemyBulletPosition(int x, int y); // При движении вражеской пули. (Координаты пули)
void changeHeroBulletPostion(int x, int y); //При движении родной пули. (Координаты пули)
int crash(); // возвращает true если его толкает платформа.
void fightWithAShadow(int width, int height); // Вызывать всегда (передавть ширину монстра, который сейчас на экране)
void comradYouHaveAHole(); // Вызывать всегда
bool niceShoot(int width, int height); //Вызывать всегда. Возвращает true при попадании во врага. Принимает ширину врага.
bool stopPlatform(); // Если вовзращает true, останавливаем платформу
int heroLives(); // ЖИЗНИ
int objectGenerator(); 
int stop();

#endif /* core_hpp */
