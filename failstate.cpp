#include "failstate.h"

FailState::FailState(): State () {}

bool FailState::processClick(ResultBar &result_bar)
{
    if (m_reset_area.contains(result_bar.m_cursor.toPoint()))
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

void FailState::drawScene(QPainter &painter, Map &map, BallsPool &pool, Platform &platform)
{
    drawResultWindow(painter, QColor("#7a3f17"), QColor("#ba8551"));
    painter.drawText(QRect(9.5 * W_SIZE / 24, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18), "Try again");
    painter.drawText(QRect(7 * W_SIZE / 16, 28 * H_SIZE / 40, W_SIZE / 4, H_SIZE / 20), "Menu");
    painter.setFont(QFont("Helvetica", 60));
    painter.drawText(QRect(W_SIZE / 16, H_SIZE / 3, 7 * W_SIZE / 8, H_SIZE / 4), " GAME OVER");

    Q_UNUSED(map);
    Q_UNUSED(pool);
    Q_UNUSED(platform);
}
