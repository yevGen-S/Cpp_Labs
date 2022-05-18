//
// Created by yevgeniy on 2022-04-06.
//

#ifndef LAB3_POINT_H
#define LAB3_POINT_H


class Point {

private:
    int x;
    int y;
public:
    Point();
    Point(int x,int y);

    int getX() const{ return this->x; }
    int getY() const{ return this->y; }
    void setX(int xpos){ this->x = xpos; }
    void setY(int ypos){ this->y = ypos; }

};


#endif //LAB3_POINT_H
