#include "myrect.h"
#include "bullet.h"
#include <QGraphicsScene>
#include"enemy.h"
#include<QKeyEvent>
void myrect::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Left){
            if(pos().x() > 0)
            setPos(x()-10,y());
        }
        else if(event->key()==Qt::Key_Right){
            if(pos().x() + 100 < 800)
            setPos(x()+10,y());
        }else if(event->key()==Qt::Key_Space){
        bullet *Bullet=new bullet();
        Bullet->setPos(x(),y());
        scene()->addItem(Bullet);
    }

}

myrect::myrect(QGraphicsItem *parant)
{
    setPixmap(QPixmap(":/images/player.jpg"));
}

void myrect::spawn()
{
    enemy *Enemy=new enemy();
    scene()->addItem(Enemy);
}
