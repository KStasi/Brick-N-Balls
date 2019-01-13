#include "drawable.h"

void Drawable::drawRect(QPainter *painter, double x, double y, int w, int h, QColor mainColor)
{
    painter->setBrush(mainColor);
    painter->drawRoundRect(QRect(static_cast<int>(x), static_cast<int>(y), w, h));
}

void Drawable::drawBall(QPainter *painter, double x, double y, int w, int h, QColor mainColor)
{
    painter->setPen(QColor(static_cast<int>(mainColor.red() * 0.80),
    static_cast<int>(mainColor.green() * 0.80),
    static_cast<int>(mainColor.blue() * 0.80)));
    painter->setBrush(mainColor);
    painter->drawEllipse(x, y, w, h);
}
