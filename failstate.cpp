#include "failstate.h"

FailState::FailState(): State ()
{}

void FailState::changeBehaviour()
{
    
}

void FailState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    for(Drawable *brick : map->map)
        brick->draw(painter);
}
