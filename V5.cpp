bool enemyLive = false; //Жив монстр
e1.enemyMove = false;  //Начальные параметры монстров
        e1.enemyLive = false;
        e2.enemyMove = false;
        e2.enemyLive = false;
        e3.enemyLive = false;
e1.lives = 2; //Жизни монстров 
        e2.lives = 4;
        e3.lives = 4;
 float CurrentFrame = 0;  //хранит текущий кадр для анимации
        Clock clock; //Время
        
        int p = 0; 
        bool GameNotOver = true; //Чтобы выполнялся цикл
        while (GameNotOver){ 
            
            a = rand() % 2 +1; //Рандомная переменная для генерации платформ и монстров %2 - 2 числа
            on_ground = onGround(); //Вызов функции из core.cpp
            
            if (gameOver(enemyLive) == 2) { 
                cout << finish();
                NumOfWindow = 4;
                GameNotOver = false;
            }
            
            if (countOfPlatform == 8){
                NumOfWindow = 3;
                GameNotOver = false;
            }
            
            if (gameOver(enemyLive) == 1) {
                if (!platformCantMove)
 // обработка врагов е1, е2, е3
            if (e1.enemyLive){
                if (e1.enemysprite.getPosition().x > 1280-48)
                    e1.enemyMove = true;
                if (e1.enemysprite.getPosition().x < 0)
                    e1.enemyMove = false;
                if (!e1.enemyMove){
                    e1.enemysprite.move(0.2 * time, 0);
                    changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
                }
                if (e1.enemyMove){
                    e1.enemysprite.move(-0.2 * time, 0);
                    changeEnemyPosition(e1.enemysprite.getPosition().x, e1.enemysprite.getPosition().y);
                }
                fightWithAShadow(48,64);
                if (niceShoot(48,64) && generatebullet){
                    e1.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                }
                if (e1.lives == 0)
                    e1.enemyLive = false;
            }
            
            if (e2.enemyLive){
                if (e2.enemysprite.getPosition().x > 1280-64)
                    e2.enemyMove = true;
                if (e2.enemysprite.getPosition().x < 0)
                    e2.enemyMove = false;
                if (!e2.enemyMove){
                    e2.enemysprite.setScale(-1, 1);
                    e2.enemysprite.move(0.6 * time, 0);
                    changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
                }
                if (e2.enemyMove){
                    e2.enemysprite.setScale(1, 1);
                    e2.enemysprite.move(-0.6 * time, 0);
                    changeEnemyPosition(e2.enemysprite.getPosition().x, e2.enemysprite.getPosition().y);
                }
                fightWithAShadow(64,64);
                if (niceShoot(64,64) && generatebullet){
                    e2.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                }
                if (e2.lives == 0)
                    e2.enemyLive = false;
            }
            
            if (e3.enemyLive){
                if (generateEnemyBullet){
                    enemystrikes.bulletLive = true;
                }
                
                if (enemystrikes.bulletLive){
                    if (enemystrikes.dirBullet == 1)
                        enemystrikes.bulletsprite.setScale(1, 1);
                    else
                        enemystrikes.bulletsprite.setScale(-1, 1);
                    enemystrikes.bulletsprite.move(0.6 * enemystrikes.dirBullet * time, 0);
                    changeEnemyBulletPosition(enemystrikes.bulletsprite.getPosition().x, enemystrikes.bulletsprite.getPosition().y);
                    if (enemystrikes.bulletsprite.getPosition().x > 1280 || enemystrikes.bulletsprite.getPosition().x < 0){
                        enemystrikes.bulletLive = false;
                    }
                }
                if (niceShoot(128,128) && generatebullet){
                    e3.lives --;
                    generatebullet = false;
                    pow.bulletLive = false;
                    changeEnemyPosition(e3.enemysprite.getPosition().x, e3.enemysprite.getPosition().y);
                }
                if (e3.lives == 0)
                    e3.enemyLive = false;
                if (!enemystrikes.bulletLive){
                    generateEnemyBullet = true;
                    enemystrikes.bulletsprite.setPosition(e3.enemysprite.getPosition().x + 128, e3.enemysprite.getPosition().y + 64);
                    changeEnemyBulletPosition(enemystrikes.bulletsprite.getPosition().x, enemystrikes.bulletsprite.getPosition().y);
                }
                if (comradYouHaveAHole())
                    enemystrikes.bulletLive = false;
            } else enemystrikes.bulletLive = false;
