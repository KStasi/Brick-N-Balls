#include "winstate.h"

WinState::WinState(): State() {}

bool WinState::processClick(ResultBar &result_bar)
{
    if (m_reset_area.contains(result_bar.m_cursor.toPoint()))
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

void WinState::drawScene(QPainter &painter, Map &map, BallsPool &pool, Platform &platform)
{
    drawResultWindow(painter, QColor("#092a3a"), QColor("#395036"));
    painter.drawText(QRectF(9.5 * W_SIZE / 24, 23 * H_SIZE / 37,
        W_SIZE / 3, H_SIZE / 18), "Continue");
    painter.drawText(QRectF(7 * W_SIZE / 16, 28 * H_SIZE / 40,
        W_SIZE / 4, H_SIZE / 20), "Menu");
    painter.setFont(QFont("Helvetica", 70));
    painter.drawText(QRect(W_SIZE / 8, H_SIZE / 3, 3 * W_SIZE / 4,
        H_SIZE / 4), "YOU WIN!");

    Q_UNUSED(map);
    Q_UNUSED(pool);
    Q_UNUSED(platform);
}
