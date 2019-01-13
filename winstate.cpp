#include "winstate.h"

WinState::WinState(): State()
{}

bool WinState::processClick(ResultBar &result_bar)
{
    if (m_reset_area.contains(result_bar.m_cursor->toPoint()))
        result_bar.changeResult(2);
    return false;
}

void WinState::changeBehaviour(ResultBar &result_bar)
{
    result_bar.setGameMode(0);
    result_bar.newLevel();
    result_bar.changeResult(0);
    if (result_bar.getStart())
        result_bar.switchStart();
}

void WinState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    drawResultWindow(painter, QColor("#092a3a"), QColor("#395036"));
    painter->drawText(QRect(9.5 * W_SIZE / 24, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18), "Continue");
}
