#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "state.h"

class PlayState : public State
{
public:
    PlayState();
    void changeBehaviour(ResultBar &result_bar);
    void drawScene(QPainter &painter, Map &map, BallsPool &pool, Platform &platform);
    bool processClick(ResultBar &result_bar);
};

#endif // PLAYSTATE_H
