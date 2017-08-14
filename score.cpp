#include"score.h"
#include<QString>
#include<QFont>

score::score(QGraphicsItem *parant): QGraphicsTextItem(parant){
    Score = 0;
    setPlainText(QString("score : ") + QString::number(Score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void score::increase()
{
    Score++;
    setPlainText(QString("score : ") + QString::number(Score));

}

int score::getScore()
{
    return Score;
}
