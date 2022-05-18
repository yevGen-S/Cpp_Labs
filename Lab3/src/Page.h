//
// Created by yevgeniy on 2022-04-29.
//

#ifndef LAB3_PAGE_H
#define LAB3_PAGE_H

#include "Button.h"
#include "Types.h"

class Page {
public:
    Page(int id, Point pos, Size size);

    void draw(QPainter& painter);

    void setPosX(int x){this->position.setX(x);};
    void setPosY(int y){this->position.setY(y);};
    void setSize(int width, int height);

    int getPosX(){return this->position.getX();};
    int getPosY(){return this->position.getY();};
    Size getSize(){return this->size;};

    map<int, Button*>& getButtons(){return this->buttons;};
    void addButton(Button* newButton);
    Button* getButtonById(int buttonId);

private:
    int id;
    Point position;
    Size size;
    map<int, Button*> buttons;

};


#endif //LAB3_PAGE_H
