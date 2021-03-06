#ifndef BALLSPOOL_H
#define BALLSPOOL_H
#include "ball.h"
#include "map.h"
#include "drawable.h"
#include <QVector>
#include <QMutableVectorIterator>
#include "bonuscontroller.h"

class BallsPool
{
public:
    BallsPool();
    ~BallsPool();
    QVector<Ball *> pool;
    void create(int &count, int size, double x, double y, double x_speed = SPEED_DEFAULT * 0.4, double y_speed = -SPEED_DEFAULT);
    void update(Map *m_map, double time_left, BonusController &bonus_controller);

};

#endif // BALLSPOOL_H
