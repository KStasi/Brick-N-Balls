#include "brick.h"

Brick::Brick(double x, double y, int w, int h, int power, int r, int g, int b):
    GameObject(x, y, w, h, r, g, b)
{
    m_power = power;
}

Brick::Brick(double x, double y, int w, int h, int power):
    GameObject(x, y, w, h, 58 + power * 3, 70 + power * 3, 85 + power * 3)
{
    m_power = power;
}

Brick::~Brick()
{}

void Brick::changeMainColor(int r, int g, int b)
{
    mainColor = QColor(r + m_power * 3 , g + m_power * 3, b + m_power * 3);
}

void Brick::draw(QPainter &painter)
{
    drawRect(painter, m_x, m_y, m_w, m_h, mainColor);

    painter.setPen(QColor(192 - m_power * 3, 185 - m_power * 3, 170 - m_power * 3));
    painter.setFont(QFont("Helvetica", 14));
    painter.drawText(*m_area, " " + QString::number(m_power) + " ");

    changeMainColor(58, 70, 85);
}

void Brick::decreasePower()
{
    m_power--;
    changeMainColor(162, 171, 179);
}
