#ifndef WINSTATE_H
#define WINSTATE_H
#include <state.h>
#include <drawable.h>

class WinState : public State
{
public:
    WinState();
    void changeBehaviour(ResultBar &result_bar);
    void drawScene(QPainter &painter, Map *map, BallsPool *pool, Platform *platform);
    bool processClick(ResultBar &result_bar);
};

#endif // WINSTATE_H
