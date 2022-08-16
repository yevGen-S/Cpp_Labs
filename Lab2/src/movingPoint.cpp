//
// Created by yevgeniy on 2022-03-23.
//

#include "movingPoint.h"

MovingPoint::MovingPoint(Point startPoint, int speed ):point(startPoint),trace(Trace(30)), speed(speed) {
}

void MovingPoint::moveDown() {
    trace.move(point);
    point.setY(point.getY() + speed);
}

void MovingPoint::moveUp() {
    trace.move(point);
    point.setY(point.getY() - speed);
}

void MovingPoint::moveLeft() {
    trace.move(point);
    point.setX(point.getX() - speed);
}

void MovingPoint::moveRight() {
    trace.move(point);
    point.setX(point.getX() + speed);
}

void MovingPoint::draw(QPainter &painter, int radius) {
    trace.draw(painter, radius);
    point.draw(painter, radius);
}
