#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

#include <QDebug>

// there is an external global object called game of type game pointer
extern Game * game;

Bullet::Bullet(){
    setRect(0,0,5,20);
    setBrush(Qt::black);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);

}

void Bullet::move(){
    QList<QGraphicsItem *> items = collidingItems();

    for (int i = 0, n = items.size(); i < n; ++i) {
        bool isEnemy = typeid(*(items[i])) == typeid(Enemy);
        if (isEnemy) {
            game->player->increaseScore();

            scene()->removeItem(items[i]);
            scene()->removeItem(this);

            delete items[i];
            delete this;

            return;
        }
    }

    setPos(x(), y() - 20);

    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    };
}
