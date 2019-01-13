#include "failstate.h"

FailState::FailState(): State ()
{}

void FailState::changeBehaviour(ResultBar &result_bar)
{
    //result_bar.reset();
    result_bar.switchStart();
    result_bar.changeResult(0);
}

void FailState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    painter->setBrush(QColor(187, 81, 54));
    painter->drawRect(QRect(0, 0, W_SIZE, H_SIZE));
}
