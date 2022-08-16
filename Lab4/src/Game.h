#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"

typedef struct Size{
    int width;
    int height;
}Size;

class Game: public QGraphicsView{
    Q_OBJECT

public:
    Game(QWidget * parent=NULL);

    void showMenu();
    void showGameOver();

    QGraphicsScene * scene;
    Size sceneSize;

    Player * player;
    int number_of_enemies;
    std::vector <Enemy*> enemies;


public slots:
    void start();
};

#endif // GAME_H
