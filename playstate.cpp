#include "playstate.h"

PlayState::PlayState(): State ()
{
    m_reset_area = QRect(0,0,0,0);
    m_menu_area = QRect(0,0,0,0);
}

void PlayState::changeBehaviour(ResultBar &result_bar)
{
    result_bar.setGameMode(0);
}

bool PlayState::processClick(ResultBar &result_bar)
{
    result_bar.changeResult(0);
    return true;
}

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
