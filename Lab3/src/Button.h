//
// Created by yevgeniy on 2022-04-05.
//

#ifndef LAB3_BUTTON_H
#define LAB3_BUTTON_H
#include <vector>
#include <string>
#include "Point.h"
#include "Types.h"
#include <QPainter>

#define UNDEFIND_REDIRECTION -1

using namespace  std;

class Button {
public:
    Button();
    Button(int ButtonId, Point pos, Size size, string text);


    void draw(QPainter& painter);

    int getId() const{return this->id;};
    void setRedirectId(int redirId){this->redirectId = redirId;};
    int getRedirectId() const{return this->redirectId;};
    string getText(){return this->text;};

    bool isClickOnButton(Point clickPosition);

private:
    int id;
    Point position;
    Size size;
    string text;
    void (*onClickHandler)(Button* ) = nullptr;



    int redirectId = UNDEFIND_REDIRECTION;


};


#endif //LAB3_BUTTON_H
