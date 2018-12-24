
void changeEnemyPosition(int x, int y); // Вызывать каждый раз при движении врага. (Принимает на борт координаты врага)
void changeEnemyBulletPosition(int x, int y); // При движении вражеской пули. (Координаты пули)
void fightWithAShadow(int width, int height); // Вызывать всегда (передавть ширину монстра, который сейчас на экране)
bool niceShoot(int width, int height); //Вызывать всегда. Возвращает true при попадании во врага. Принимает ширину врага.

