#include "bullet.h"
#include <QTimer>
#include<QGraphicsScene>
#include<QList>
#include "enemy.h"
#include"score.h"
#include<bits/stdc++.h>
#include"game.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>

extern Game *game;

bullet::bullet(QGraphicsItem *parant):QObject(),QGraphicsPixmapItem(parant)
{
    setPixmap(QPixmap(":/images/rocket1.jpg"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
void bullet::move()
{
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(enemy)){
            game->Score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
