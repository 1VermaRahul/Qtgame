#include"game.h"
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include<QTimer>
#include"score.h"
#include"bullet.h"
#include<QMediaPlayer>
#include"myrect.h"
#include<QImage>

Game::Game(QWidget *parent)
{
    QGraphicsScene *scene=new QGraphicsScene();

    QGraphicsView *view=new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg2.jpg")));
   // rect->setPos(view->width()/2,view->height());
    rect=new myrect();
    rect->setPixmap(QPixmap(":/images/player1.jpg"));
    rect->setPos(400,500);
    //adding score to that
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    scene->addItem(rect);
    Score=new score();
    scene->addItem(Score);

    //adding health
    Hlth=new health();
    Hlth->setPos(Hlth->x(),Hlth->y()+25);
    scene->addItem(Hlth);
    //spawn enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/asla.mp3"));
    music->play();
}
