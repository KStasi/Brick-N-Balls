#ifndef STATE_H
#define STATE_H
#include <QWidget>
#include <QPainter>
#include "ballspool.h"
#include "map.h"
#include "platform.h"

class State
{
public:
    State();
    virtual void changeBehaviour()=0;
    virtual void drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)=0;
    virtual ~State();
};

#endif // STATE_H
