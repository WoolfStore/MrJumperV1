
<<<<<<< HEAD

<<<<<<< HEAD
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
#ifndef allclass_h
#define allclass_h

using namespace sf;

class platform {
public:
    Image image;
<<<<<<< HEAD
=======
#ifndef allclass_h 
#define allclass_h

using namespace sf; //потом

class platform { 
public:
    Image image;//cфмл изображение
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
    Texture texture;//сфмл текстура
    Sprite platformsprite;//сфмл спрайт
    
    platform(float X, float Y){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
        image.loadFromFile("platform.jpg");
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        platformsprite.setTexture(texture);//заливаем спрайт текстурой
        //      platformsprite.setColor(sf::Color(128, 128, 255, 255));
        platformsprite.setTextureRect(IntRect(0, 0, 256, 64));
<<<<<<< HEAD
=======
        image.loadFromFile("platform.jpg");//загружаем изображение из файла
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        platformsprite.setTexture(texture);//заливаем спрайт текстурой
        platformsprite.setColor(sf::Color(128, 128, 255, 255));//создаем спрайт
        platformsprite.setTextureRect(IntRect(0, 0, 256, 64));//выбор прямоугольной области ,которую берем от текстуры
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
        platformsprite.setPosition(X,Y);
    }
};

<<<<<<< HEAD
<<<<<<< HEAD



class enemy  {
public:
	class enemy();
    bool enemyMove;
    bool enemyLive;
    int lives;




class enemy1 : public enemy {
public:
	class enemy();
    bool enemyMove;
    bool enemyLive;
    int lives;

    Image image;
    Texture texture;
    Sprite enemysprite;


    enemy1 (float X, float Y){

=======
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
class enemy {
public:
    bool enemyMove;
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy(float X, float Y){
<<<<<<< HEAD
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
        image.loadFromFile("bones.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        enemysprite.setTextureRect(IntRect(48, 128, 48, 64));
        enemysprite.setPosition(X, Y);
    }
};

<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
class enemy2 {
public:
    bool enemyMove;
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
<<<<<<< HEAD
<<<<<<< HEAD

class enemy2 : public enemy {


=======
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
    
    enemy2(float X, float Y){
        image.loadFromFile("ghost.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        enemysprite.setTextureRect(IntRect(64, 48, 64, 64));
        enemysprite.setPosition(X, Y);
    }
};

<<<<<<< HEAD
<<<<<<< HEAD


class enemy3 : public enemy {



=======
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
class enemy3 {
public:
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 371b86f5e0136f4f3ca75b041a870dfae6f9cedc
=======
>>>>>>> 154c78d348fb6896623b6c71bb5404d4d6666404
    
    enemy3(float X, float Y){
        image.loadFromFile("ghost.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        enemysprite.setTextureRect(IntRect(64*16, 16, 128, 128));
        enemysprite.setPosition(X, Y);
    }
};

class bullet {
public:
    int dirBullet;
    bool bulletLive;
    Image image;
    Texture texture;
    Sprite bulletsprite;
    
    bullet(float X, float Y){
        image.loadFromFile("bullet.png");
        texture.loadFromImage(image);
        bulletsprite.setTexture(texture);
        bulletsprite.setTextureRect(IntRect(0, 0, 32, 14));
        bulletsprite.setPosition(X, Y);
    }
};


#endif /* allclass_h */
