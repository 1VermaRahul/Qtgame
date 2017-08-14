#ifndef GAME_H
#define GAME_H
#include<QGraphicsView>
#include<QWidget>
#include<QGraphicsScene>
#include"myrect.h"
#include"score.h"
#include"health.h"

class Game:public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsScene *scene;
    myrect *rect;
    score *Score;
    health *Hlth;
};

#endif // GAME_H
