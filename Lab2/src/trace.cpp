//
// Created by yevgeniy on 2022-03-10.
//

#include "trace.h"

void Trace::draw(QPainter& painter, int radius) {
    double opacity = 1;
    painter.setPen(Qt::transparent);
    painter.setBrush(Qt::darkMagenta);
    if(!traceLine.empty()) {
        for (int i = 0; i < traceLine.size(); i++) {
            opacity -= 0.033;
            painter.setOpacity(opacity);
            painter.drawEllipse(traceLine[traceLine.size() - i - 1].getX() - i/2,
                                traceLine[traceLine.size() - i - 1].getY() - i/2,
                                radius + i,
                                radius + i
            );

        }
    }
}

void Trace::move(Point point) {
    addPoint(point);
    if(traceLine.size() == traceLength){
        removePoint();
    }
}
