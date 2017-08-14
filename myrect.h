#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsRectItem>
class myrect:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    myrect(QGraphicsItem *parant=0);
public slots:
    void spawn();
};

#endif // MYRECT_H
