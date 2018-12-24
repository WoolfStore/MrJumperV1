
#ifndef allclass_h
#define allclass_h

using namespace sf;

class platform {
public:
    Image image;
    Texture texture;//сфмл текстура
    Sprite platformsprite;//сфмл спрайт
    
    platform(float X, float Y){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
        image.loadFromFile("platform.jpg");
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        platformsprite.setTexture(texture);//заливаем спрайт текстурой
        //      platformsprite.setColor(sf::Color(128, 128, 255, 255));
        platformsprite.setTextureRect(IntRect(0, 0, 256, 64));
        platformsprite.setPosition(X,Y);
    }
};

class enemy {
public:
    bool enemyMove;
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy(float X, float Y){
        image.loadFromFile("bones.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        enemysprite.setTextureRect(IntRect(48, 128, 48, 64));
        enemysprite.setPosition(X, Y);
    }
};

class enemy2 {
public:
    bool enemyMove;
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
    enemy2(float X, float Y){
        image.loadFromFile("ghost.png");
        texture.loadFromImage(image);
        enemysprite.setTexture(texture);
        enemysprite.setTextureRect(IntRect(64, 48, 64, 64));
        enemysprite.setPosition(X, Y);
    }
};

class enemy3 {
public:
    bool enemyLive;
    int lives;
    Image image;
    Texture texture;
    Sprite enemysprite;
    
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
