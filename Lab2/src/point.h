//
// Created by yevgeniy on 2022-03-09.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H
#include <QtWidgets>

class Point{
private:
    int x;
    int y;


public:
    Point(int x,int y);

    int getX() const { return x; };
    int getY() const { return y; };

    void setX(int xpos) { x = xpos; };
    void setY(int ypos) { y = ypos; };

    void draw(QPainter& painter, int radius) const;
};


#endif //LAB2_POINT_H
