#ifndef LAB2_QT__WINDOW_H
#define LAB2_QT__WINDOW_H
#include <QtWidgets>
#include <QObject>
#include "movingPoint.h"


class Window: public QWidget{
public:
    explicit Window(QWidget* parent = nullptr);


protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

    void checkBorders();


private:
    static const int width = 800;
    static const int height = 600;

    bool rightDir = false;
    bool leftDir = false;
    bool upDir = false;
    bool downDir = false;

    void move();
    void doDrawing();

    MovingPoint movingPoint;
};



#endif //LAB2_QT__WINDOW_H
