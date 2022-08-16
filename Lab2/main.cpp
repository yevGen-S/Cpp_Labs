#include <QApplication>
#include "window.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window my_window;
    my_window.show();
    return app.exec();
}
