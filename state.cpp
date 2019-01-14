#include "state.h"

State::State(){}

bool State::processClick(ResultBar &result_bar) {Q_UNUSED(result_bar) return false;}
void State::changeBehaviour(ResultBar &result_bar) {Q_UNUSED(result_bar)}
void State::drawScene(QPainter &painter, Map &map, BallsPool &pool, Platform &platform)
{
    Q_UNUSED(painter);
    Q_UNUSED(map);
    Q_UNUSED(pool);
    Q_UNUSED(platform);
}

void State::drawResultWindow(QPainter &painter, QColor mainColor, QColor secondColor)
{
    painter.setBrush(mainColor);
    painter.drawRect(QRect(0, 0, W_SIZE, H_SIZE));
    painter.setBrush(secondColor);
    painter.drawRoundRect(m_reset_area, 20, 40);
    painter.drawRoundRect(m_menu_area, 20, 40);
    painter.setPen(QColor(240, 240, 255));
    painter.setFont(QFont("Helvetica", 24));
}

bool State::menuChecked(QPoint mouse)
{
    return m_menu_area.contains(mouse);
}

State::~State(){}
