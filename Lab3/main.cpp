#include <QApplication>
#include "src/WindowWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    WindowWidget w;
    w.show();
    return a.exec();
}
