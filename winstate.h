#ifndef WINSTATE_H
#define WINSTATE_H
#include <state.h>

class WinState : public State
{
public:
    WinState();
    void changeBehaviour();
    void drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform);
};

#endif // WINSTATE_H
