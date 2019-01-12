#include "winstate.h"

WinState::WinState(): State()
{}

void WinState::changeBehaviour()
{

}

void WinState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    for(Drawable *brick : map->map)
        brick->draw(painter);
}
