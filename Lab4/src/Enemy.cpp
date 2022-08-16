#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand()
#include "Game.h"

#include <iostream>
#include <QDebug>

extern Game * game;

Enemy::Enemy(int x,int y): QObject(), QGraphicsRectItem(){
    int width = 10;
    int height = 10;
    setRect(x, y, width, height);
    setBrush(Qt::darkRed);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(1000);
}

void Enemy::move(){
    setPos(x() + this->speed, y());
    if (pos().y() - rect().height() > (game->sceneSize.height)){
        game->player->decreaseHealth();
        scene()->removeItem(this);
        delete this;
    }

}
