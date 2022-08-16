#include "Game.h"
#include <QTimer>
#include "Enemy.h"
#include "Button.h"

#include <iostream>

Game::Game(QWidget * parent){
    sceneSize.width = 800;
    sceneSize.height = 600;
    resize(sceneSize.width,sceneSize.height);
    move(500,200);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneSize.width , sceneSize.height);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, sceneSize.width, sceneSize.height);
    setScene(scene);

    number_of_enemies = 10;
}


void Game::start(){
    scene->clear();
    player = new Player();
    scene->addItem(player);

    int x = 10;
    int y = 80;
    for(int i = 0; i < number_of_enemies; i ++ ){
        enemies.push_back(new Enemy(x,y));
        scene->addItem(enemies[i]);
        x+=30;
        if ( i % 5 ==0){
            y += 20;
        }
    }
}

void Game::showMenu(){
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Space Invaders"));
    QFont titleFont("times new roman", 20);
    title->setFont(titleFont);
    int xTitlePos = this->width()/2 - title->boundingRect().width() / 2;
    int yTitlePos = 50;
    title->setPos(xTitlePos, yTitlePos);
    scene->addItem(title);

    Button *play = new Button(QString("Play"));
    int xPlayPos = this->width()/2 - play->boundingRect().width() / 2;
    int yPlayPos = 275;
    play->setPos(xPlayPos, yPlayPos);
    connect(play, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(play);

    Button *quit = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quit->boundingRect().width() / 2;
    int yQuitPos = 350;
    quit->setPos(xQuitPos, yQuitPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);

}

void Game::showGameOver(){
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Game Over"));
    QFont titleFont("times new roman", 20);
    titleText->setFont(titleFont);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos, yTitlePos);
    scene->addItem(titleText);

    Button *retryButton = new Button(QString("Retry"));
    int xRetryPos = this->width()/2 - retryButton->boundingRect().width()/2;
    int yRetryPos = 275;
    retryButton->setPos(xRetryPos, yRetryPos);
    connect(retryButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(retryButton);

    Button *quitButton = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int yQuitPos = 425;
    quitButton->setPos(xQuitPos, yQuitPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

