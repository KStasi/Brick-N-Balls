#include "winstate.h"

WinState::WinState(): State()
{}

void WinState::changeBehaviour(ResultBar &result_bar)
{
    //result_bar.newLevel();
    result_bar.changeResult(0);
    result_bar.switchStart();
}

void WinState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    painter->setBrush(QColor(80, 200, 54));
    painter->drawRect(QRect(0, 0, W_SIZE, H_SIZE));
}
