//
// Created by yevgeniy on 2022-03-10.
#ifndef LAB2_TRACE_H
#define LAB2_TRACE_H
#include <vector>
#include "point.h"
#include <QtWidgets>

using namespace std;

class Trace {
public:
    explicit Trace(int length){ traceLength = length;}

    void addPoint(Point point){ traceLine.push_back(point);}
    void removePoint(){traceLine.erase(traceLine.begin());}

    void draw(QPainter& painter, int radius);
    void move(Point point);

private:
    vector<Point> traceLine;
    int traceLength;

};


#endif //LAB2_TRACE_H
