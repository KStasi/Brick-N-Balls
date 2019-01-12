#include "brick.h"

Brick::Brick(double x, double y, int w, int h, int power, int r, int g, int b):
    GameObject(x, y, w, h, r, g, b)
{
    m_power = power;
}

Brick::Brick(double x, double y, int w, int h, int power):
    GameObject(x, y, w, h, power * 4, power * 4, power * 4)
{
    m_power = power;
}

void Brick::draw(QPainter *painter)
{
    drawRect(painter, m_x, m_y, m_w, m_h, mainColor);

    painter->setPen(QColor(255 - m_power * 4, 255 - m_power * 4, 255 - m_power * 4));
    painter->setFont(QFont("Helvetica", 14));
    painter->drawText(*m_area, " " + QString::number(m_power) + " ");
}

void Brick::decreasePower()
{
    m_power--;
}
