//
// Created by yevgeniy on 2022-03-09.
//
#include<window.h>
#include "point.h"


Point::Point(int x,int y){
    this->x = x ;
    this->y = y;
}


void Point::draw(QPainter& painter, int radius) const{
    painter.setOpacity(255);
    painter.setBrush(Qt::darkMagenta);
    painter.setPen(Qt::white);
    painter.drawEllipse(x,y,radius,radius);
}

