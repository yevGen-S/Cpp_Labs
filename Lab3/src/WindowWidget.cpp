//
// Created by yevgeniy on 2022-03-22.
//

#include <fstream>
#include <QPainter>
#include <QLabel>
#include "WindowWidget.h"
#include "iostream"
#include "Button.h"
#include <QMouseEvent>





void WindowWidget::update(){
    this->resize(getPageById(currentPageId)->getSize().width,getPageById(currentPageId)->getSize().height);
    this->move(getPageById(currentPageId)->getPosX(),getPageById(currentPageId)->getPosY());
}


WindowWidget::WindowWidget(QWidget *parent): QWidget(parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setWindowTitle("Menu");
    string filename = "/home/yevgeniy/Work_Study/Polytech/C++/Cpp_Labs/Lab3/src/refs/menuUI";
    loadUI(filename);
    currentPageId = 0;
    this->getPageById(0)->getButtonById(3)->setRedirectId(4);
    this->getPageById(4)->getButtonById(5)->setRedirectId(0);

}



void WindowWidget::switchPage(int switchPageId) {
    if(this->pages.count(switchPageId)){
        this->currentPageId =  switchPageId;
    }
}


void WindowWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    update();
    this->getPageById(currentPageId)->draw(painter);
}

void WindowWidget::mousePressEvent(QMouseEvent *event){
    Point clickPos = Point(event->pos().x(),event->pos().y());
    for(auto& button: this->getPageById(currentPageId)->getButtons()){
        if(button.second->isClickOnButton(clickPos)){
            if(button.second->getRedirectId() != UNDEFIND_REDIRECTION ) {
                switchPage(button.second->getRedirectId());
            }
        }
    }
    this->repaint();
}


void WindowWidget::loadUI(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "File wasn't opened. Check if the name of the file correct." << endl;
    }
    string buff;
    if(getline(file,buff) && buff.find("menu"))
        loadPage(file);
}



Page *WindowWidget::getPageById(int pageId) {
    if(this->pages.count(pageId)){
        return this->pages[pageId];
    }
    return nullptr;
}

void WindowWidget::loadPage(ifstream &file) {
    string buff;
    int indexStart;
    int indexEnd;
    int middle;
    int newPageId;
    int x;
    int y;
    Size newPageSize;

    while (getline(file, buff) && buff.find("&button") == string::npos) {
        indexStart = (int)buff.find('{') + 1;
        middle = (int) buff.find(',');
        indexEnd =  (int)buff.find('}');
        if (buff.find("id")!= string::npos) {
            newPageId = stoi(buff.substr(indexStart, indexEnd-indexStart));
            continue;
        }
        if (buff.find("position")!= string::npos) {
            x = stoi(buff.substr(indexStart, middle-indexStart));
            y = stoi(buff.substr(middle + 1, indexEnd-middle-1));
            continue;

        }
        if (buff.find("size")!= string::npos) {
            newPageSize.width = stoi(buff.substr(indexStart, indexEnd-middle));
            newPageSize.height = stoi(buff.substr(middle + 1, indexEnd-middle - 1));
            continue;

        }
    }
    Page* newPage = new Page(newPageId, Point(x,y), newPageSize);
    this->pages.insert_or_assign(newPageId, newPage);
    this->currentLoadingPage = newPage;
    loadButton(file);

}

void WindowWidget::loadButton(ifstream &file) {
    string buff;
    Button* newButton = nullptr;

    int newButtonId;
    int x;
    int y;
    Size newButtonSize ;
    string text;

    while(getline(file,buff)) {
        int indexStart = (int) buff.find('{') + 1;
        int middle = (int) buff.find(',');
        int indexEnd = (int) buff.find('}');
        if (buff.find("id")!= string::npos) {
            newButtonId = stoi(buff.substr(indexStart, indexEnd-indexStart));
            continue;
        }

        if (buff.find("position")!= string::npos) {
            x = stoi(buff.substr(indexStart, middle-indexStart));
            y = stoi(buff.substr(middle+1, indexEnd-middle-1));
            continue;
        }

        if (buff.find("size")!= string::npos) {
            newButtonSize.width = stoi(buff.substr(indexStart, indexEnd-middle));
            newButtonSize.height = stoi(buff.substr(middle+1, indexEnd-middle-1));
            continue;

        }
        if (buff.find("text")!= string::npos) {
            text = buff.substr(indexStart, indexEnd-indexStart);
            continue;
        }

        newButton = new Button(newButtonId, Point(x, y), newButtonSize, text);
        this->currentLoadingPage->addButton(newButton);

        if( buff.find("&submenu") != string::npos){
            loadPage(file);
            continue;
        }
    }

}



