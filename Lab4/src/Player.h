#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Score.h"
#include "Health.h"

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();

    void keyPressEvent(QKeyEvent * event);
    void decreaseHealth(){this->health->decrease();};
    void increaseScore(){this->score->increase();};

private:
    Health * health;
    Score* score;
};

#endif // PLAYER_H
