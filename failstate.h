#ifndef FAILSTATE_H
#define FAILSTATE_H
#include <state.h>

class FailState : public State
{
public:
    FailState();
    void changeBehaviour(ResultBar &result_bar);
    void drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform);
};

#endif // FAILSTATE_H
