#include <QPainter>
#include <QTimerEvent>
#include "window.h"
#include "point.h"


Window::Window(QWidget * parent): QWidget(parent), movingPoint(MovingPoint(Point(width/2,height/2))){
    setStyleSheet("background-color: black");
    setFixedSize(width,height);
    startTimer(30);
}


void Window::keyPressEvent(QKeyEvent* event) {
    int key = event->key();

    if(key == Qt::Key_Up) {
        upDir = true;
        downDir = false;
        leftDir = false;
        rightDir = false;
//        direction = key;
    }

    if(key == Qt::Key_Down){
        downDir = true;
        leftDir = false;
        rightDir = false;
        upDir = false;
//        direction = key;
    }

    if(key == Qt::Key_Right) {
        upDir = false;
        downDir = false;
        rightDir = true;
        leftDir = false;
//        side = key;
    }

    if(key == Qt::Key_Left) {
        upDir = false;
        downDir = false;
        leftDir = true;
        rightDir = false;
//        side = key;
    }

    if(key == Qt::Key_Space){
        upDir = false;
        downDir = false;
        leftDir = false;
        rightDir = false;
    }

    if(key == Qt::Key_Escape){
        close();
    }

    QWidget::keyPressEvent(event);
}





void Window::checkBorders(){
    if(movingPoint.getPoint().getX() > width){
        movingPoint.getPoint().setX(0);
    }
    if(movingPoint.getPoint().getX() < 0){
        movingPoint.getPoint().setX(width);
    }
    if(movingPoint.getPoint().getY() > height){
        movingPoint.getPoint().setY(0);
    }
    if(movingPoint.getPoint().getY() < 0){
        movingPoint.getPoint().setY(height);
    }
}


void Window::move() {
    checkBorders();

    if(leftDir){
        movingPoint.moveLeft();
    }

    if(rightDir){
        movingPoint.moveRight();

    }

    if(upDir){
        movingPoint.moveUp();
    }

    if(downDir){
        movingPoint.moveDown();
    }

}



void Window::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e)
    doDrawing();
}


void Window::doDrawing() {
    QPainter painter(this);
    movingPoint.draw(painter, 10);
}


void Window::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e)

    move();
    repaint();
}

