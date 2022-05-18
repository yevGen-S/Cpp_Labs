//
// Created by yevgeniy on 2022-03-22.
//

#ifndef LAB3_WINDOWWIDGET_H
#define LAB3_WINDOWWIDGET_H
#include  <QWidget>
#include <QMenu>
#include "Page.h"
#include "Point.h"
#include "Button.h"

using namespace std;


class WindowWidget: public QWidget{
public:
    explicit WindowWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    int currentPageId;
    Page* currentLoadingPage = nullptr;

    void loadUI(const string& filename);
    inline void loadPage(ifstream& file);
    inline void loadButton(ifstream& file);

    Page* getPageById(int pageId);

    void update();
    void switchPage(int switchPageId);



    map <int, Page*> pages;
};


#endif //LAB3_WINDOWWIDGET_H
