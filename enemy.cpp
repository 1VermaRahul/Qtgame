#include "enemy.h"
#include <QTimer>
#include<QGraphicsScene>
#include"game.h"
#include<bits/stdc++.h>
extern Game *game;
enemy::enemy()
{
    //set pos
    int random_number=rand()%700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/images/enemy1.png"));

    QTimer *timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
void enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() < 0){
        game->Hlth->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
