#include "state.h"

State::State(){}

void State::drawResultWindow(QPainter *painter, QColor mainColor, QColor secondColor)
{
    painter->setBrush(mainColor);
    painter->drawRect(QRect(0, 0, W_SIZE, H_SIZE));
    painter->setBrush(secondColor);
    painter->drawRoundRect(m_reset_area, 20, 40);
    painter->drawRoundRect(m_menu_area, 20, 40);
    painter->setPen(QColor("#c7c4ac"));
    painter->setFont(QFont("Helvetica", 24));
    painter->drawText(QRect(7 * W_SIZE / 16, 28 * H_SIZE / 40, W_SIZE / 4, H_SIZE / 20), "Menu");
}

bool State::menuChecked(QPoint mouse)
{
    return m_menu_area.contains(mouse);
}

State::~State(){}
