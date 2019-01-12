#include "gameobject.h"

GameObject::GameObject(double x, double y, int w, int h, int r, int g, int b):
    m_area(new QRectF(x, y, w, h))
{
    m_x = x;
    m_y = y;
    m_h = h;
    m_w = w;
    mainColor.setRgb(r, g, b);
}

double GameObject::getX()
{
    return m_x;
}

double GameObject::getY()
{
    return m_y;
}
