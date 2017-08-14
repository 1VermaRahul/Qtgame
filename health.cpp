#include"health.h"
#include<QString>
#include<QFont>

health::health(QGraphicsItem *parant): QGraphicsTextItem(parant){
    Health = 3;
    setPlainText(QString("health : ") + QString::number(Health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void health::decrease()
{
    Health=Health-1;
    setPlainText(QString("health : ") + QString::number(Health));

}

int health::getHealth()
{
    return Health;
}
