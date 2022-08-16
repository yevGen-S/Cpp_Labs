//
// Created by yevgeniy on 2022-03-23.
//

#ifndef LAB2_MOVINGPOINT_H
#define LAB2_MOVINGPOINT_H
#include "point.h"
#include "trace.h"

class MovingPoint {
private:
    int speed ;
    Point point;
    Trace trace;

public:
    MovingPoint(Point startPoint, int speed = 10);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void draw(QPainter& painter, int radius);
    Point& getPoint(){ return point;}


};


#endif //LAB2_MOVINGPOINT_H
