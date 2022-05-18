//
// Created by yevgeniy on 2022-04-05.
//

#include <QPainter>
#include <QPaintEvent>
#include "Button.h"
#include "WindowWidget.h"


Button::Button(int ButtonId, Point pos, Size size, string text) : id(ButtonId), position(pos), size(size), text(text) {

}


bool Button::isClickOnButton(Point clickPosition) {
    bool isOnButton = false;
    if((clickPosition.getX() <= this->position.getX() + this->size.width) &&
            (clickPosition.getX() >= this->position.getX()) &&
            (clickPosition.getY() <= this->position.getY() + this->size.height) &&
            (clickPosition.getY() >= this->position.getY())){
        isOnButton = true;
    }

    return isOnButton;
}


void Button::draw(QPainter &painter) {
    painter.setBrush(Qt::darkMagenta);
    QRect rect = QRect(this->position.getX(), this->position.getY(), this->size.width, this->size.height);
    painter.drawRect(rect);
    painter.setFont(QFont("Bold", 14));
    painter.drawText(rect, Qt::AlignCenter, QString::fromStdString(this->text), &rect);
}


