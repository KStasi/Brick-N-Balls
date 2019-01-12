#include "platform.h"

Platform::Platform(double x, double y, int w, int h, int r, int g, int b) :
    GameObject(x, y, w, h, r, g, b){}

Platform::Platform(double x, double y, int w, int h) :
GameObject(x, y, w, h, 100, 45, 34){}

Platform *Platform::create(double x, double y, int w, int h)
{
    static Platform *platform = new Platform(x, y, w, h);
    return platform;
}

void Platform::draw(QPainter *painter)
{
    drawRect(painter, m_x, m_y, m_w, m_h, mainColor);
    if (m_with_ball > 0)
        drawBall(painter, m_x + m_w / 2, m_y - BLOCK_SIZE / 2,
        BLOCK_SIZE / 2, BLOCK_SIZE / 2, mainColor);
}
void Platform::update(double x, int with_ball)
{
    if (x > 0 && x < W_SIZE - m_w)
        m_x = x;
    m_area->moveTo(m_x, m_y);
    m_with_ball = with_ball;
}
