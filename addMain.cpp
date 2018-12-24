        ///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
        
        if ((((Keyboard::isKeyPressed(Keyboard::Left)) && (crash() == 0)) || ((Keyboard::isKeyPressed(Keyboard::Left)) && (enemyLive))) && (stop() != 2)) { //если нажата клавиша стрелка влево
            //            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //            if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            //            herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            herosprite.move(-0.2*time, 0);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            dirhero = false;
        }
        
        if ((((Keyboard::isKeyPressed(Keyboard::Right)) && (crash() == 0)) || ((Keyboard::isKeyPressed(Keyboard::Right)) && (enemyLive))) && (stop() !=2)) {
            //                        CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //                        if (CurrentFrame > 4) CurrentFrame -= 4; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            //                        herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 128, 128, 128)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            herosprite.move(0.2*time, 0);//происходит само движение персонажа вправо
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            dirhero = true;
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Space)) && (stop() != 3) && !endOfJump() && HeroCanJump == 1) {
            herosprite.move(0, -0.8*time);
            changeHeroPosition(herosprite.getPosition().x, herosprite.getPosition().y);
            
        }
        
        if (endOfJump() && on_ground == 0)
            HeroCanJump = 0;
        
        if (on_ground !=0)
            HeroCanJump = 1;



//////////////ПУЛя

  if ((Keyboard::isKeyPressed(Keyboard::A) && youCanShoot)){
            youCanShoot = false;
            if (dirhero)
                pow.dirBullet = 1;
            else
                pow.dirBullet = -1;
            generatebullet = true;
        }
        
        if (generatebullet){
            pow.bulletLive = true;
            pow.bulletsprite.move(0.8 * pow.dirBullet * time, 0);
            changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
            if (pow.bulletsprite.getPosition().x > 1280 || pow.bulletsprite.getPosition().x < 0){
                pow.bulletLive = false;
            }
        }
        
        if (!pow.bulletLive){
            pow.bulletsprite.setPosition(herosprite.getPosition().x + 64, herosprite.getPosition().y + 64);
            changeHeroBulletPostion(pow.bulletsprite.getPosition().x, pow.bulletsprite.getPosition().y);
            generatebullet = false;
            youCanShoot = true;
        }
        

