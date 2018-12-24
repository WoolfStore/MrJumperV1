
#ifndef core_hpp
#define core_hpp

#include <stdio.h>

void startGame(int x, int y);
void getPlatformCoordinates(int x1, int y1, int x2, int y2);
void changePositionOfMovingPlatform(int x, int y);
void changeHeroPosition(int x, int y);
int gameOver(bool enemyAlive);
int onGround();
void changeEnemyPosition(int x, int y); // �������� ������ ��� ��� �������� �����. (��������� �� ���� ���������� �����)
void changeEnemyBulletPosition(int x, int y); // ��� �������� ��������� ����. (���������� ����)
void changeHeroBulletPostion(int x, int y); //��� �������� ������ ����. (���������� ����)
int crash(); // ���������� true ���� ��� ������� ���������.
void fightWithAShadow(int width, int height); // �������� ������ (��������� ������ �������, ������� ������ �� ������)
bool comradYouHaveAHole(); // �������� ������
bool niceShoot(int width, int height); //�������� ������. ���������� true ��� ��������� �� �����. ��������� ������ �����.
bool stopPlatform(); // ���� ���������� true, ������������� ���������
int heroLives(); // ������
int objectGenerator(); // ����� ������ �� �������������
int stop();
int whatIsScore();
int finish();
bool endOfJump();
void whatIsQuantityOfPlatform(int count);

#endif /* core_hpp */
