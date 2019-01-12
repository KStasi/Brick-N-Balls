#include "playstate.h"

PlayState::PlayState(): State ()
{}

void PlayState::changeBehaviour()
{

}

void PlayState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    platform->draw(painter);
    for(Drawable *brick : map->map)
        brick->draw(painter);
    if (pool)
        for(Drawable *ball : pool->pool)
            ball->draw(painter);
    painter->drawRect(QRect(0, 0, W_SIZE, HEADER));
}
