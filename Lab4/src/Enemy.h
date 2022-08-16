#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(int x=0,int y=0);

private:
    int speed;

public slots:
    void move();
};

#endif // ENEMY_H
