#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "state.h"

class PlayState : public State
{
public:
    PlayState();
    void changeBehaviour();
    void drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform);
};

#endif // PLAYSTATE_H
