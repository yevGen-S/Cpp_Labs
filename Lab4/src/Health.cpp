#include "Health.h"
#include "Game.h"
#include <QFont>
#include <QApplication>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize to 3
    health = 3;

    // draw text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    if (gameOver()){
        // Close the application
        game->showGameOver();
    } else {
        // Update the text
        setPlainText(QString("Health: ") + QString::number(health));
    }
}


bool Health::gameOver(){
    return health < 1;
}
