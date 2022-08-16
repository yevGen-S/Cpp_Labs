#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

#define STEP 15

#include <QDebug>

extern Game * game;

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case(Qt::Key_Left):
            if (pos().x() > 0)
                setPos(x() - STEP, y());
            break;
        case(Qt::Key_Right):
            if (pos().x() + rect().width() < (game->sceneSize.width))
                setPos(x() + STEP, y());
            break;
        case(Qt::Key_Space):
            Bullet * bullet = new Bullet();
            bullet->setPos(x() + rect().width() / 2, y() - rect().height());
            game->scene->addItem(bullet);
    }
}

Player::Player() {
    int playerWidth = 25;
    int playerHeight = 25;

    setRect(0,0, playerWidth, playerHeight);
    setPos(game->scene->width()/2 - rect().width()/2,
           game->scene->height() - rect().height());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setBrush(Qt::green);

    score = new Score();
    game->scene->addItem(score);

    health = new Health();
    int yTextOffset = 25;
    health->setPos(health->x(), health->y() + yTextOffset);
    game->scene->addItem(health);
}


