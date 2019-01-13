#include "failstate.h"

FailState::FailState(): State ()
{}

bool FailState::processClick(ResultBar &result_bar)
{
    if (m_reset_area.contains(result_bar.m_cursor->toPoint()))
    {
        result_bar.reset();
        result_bar.changeResult(2);
    }
    return false;
}

void FailState::changeBehaviour(ResultBar &result_bar)
{
    if (result_bar.getStart())
        result_bar.switchStart();
    result_bar.changeResult(0);
    result_bar.setGameMode(0);
}

void FailState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    drawResultWindow(painter, QColor("#7a3f17"), QColor("#ba8551"));
    painter->drawText(QRect(9.5 * W_SIZE / 24, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18), "Try again");
}
