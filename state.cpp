#include "state.h"

State::State(){}

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
