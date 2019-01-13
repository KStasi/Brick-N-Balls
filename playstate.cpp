#include "playstate.h"

PlayState::PlayState(): State ()
{}

void PlayState::changeBehaviour(ResultBar &result_bar) {}

void PlayState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    platform->draw(painter);
    for(Drawable *brick : map->map)
        brick->draw(painter);
    if (pool)
        for(Drawable *ball : pool->pool)
            ball->draw(painter);
    painter->setBrush(QColor(75, 85, 121));
    painter->drawRect(QRect(0, 0, W_SIZE, HEADER));
}
