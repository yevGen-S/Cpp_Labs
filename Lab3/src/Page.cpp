//
// Created by yevgeniy on 2022-04-29.
//

#include "Page.h"
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <QPainterPath>


Page::Page(int id, Point pos, Size size): id(id), position(pos), size(size) {

}


void Page::setSize(int width, int height) {
    this->size.width = width;
    this->size.height = height;

}

void Page::draw(QPainter& painter) {
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    QRect rect = QRect(0,0, this->size.width, this->size.height);
    painter.drawRect(rect);

    for ( auto& button : this->buttons){
        button.second->draw(painter);
    }
}


void Page::addButton(Button *newButton) {
    this->buttons.insert_or_assign(newButton->getId(), newButton);
}

Button *Page::getButtonById(int buttonId) {
    if(this->buttons.count(buttonId))
        return this->buttons[buttonId];
    return nullptr;
}




