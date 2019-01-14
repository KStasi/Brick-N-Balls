#include "ball.h"

Ball::Ball(double x, double y, int w, int h, double speed_x, double speed_y, int r, int g, int b):
    GameObject(x, y, w, h, r, g, b)
{
    m_speed_x = speed_x;
    m_speed_y = speed_y;
}

Ball::Ball(double x, double y, int w, int h, double speed_x, double speed_y):
    GameObject(x, y, w, h, 237, 154, 78)
{
    m_speed_x = speed_x;
    m_speed_y = speed_y;
}

void Ball::draw(QPainter &painter)
{
    drawBall(painter, m_x, m_y, m_w, m_h, mainColor);
}

void Ball::update(double delta_time)
{
    m_x += m_speed_x * delta_time;
    m_y += m_speed_y * delta_time;
    m_area->moveTo(m_x, m_y);
}

void Ball::rotate(int x_rot, int y_rot)
{
    m_speed_x *= x_rot;
    m_speed_y *= y_rot;
}

void Ball::checkMove(GameObject &object)
{
    if ((object.m_area->contains(m_area->topLeft())
        || object.m_area->contains(m_area->bottomLeft()))
        && (object.m_area->right() - m_area->left() < object.m_area->width() / 2))
    {
        m_x = object.m_area->right();
        rotate(-1, 1);
    }
    if ((object.m_area->contains(m_area->bottomLeft())
        || object.m_area->contains(m_area->bottomRight()))
        && object.m_area->bottom() - m_area->top()< object.m_area->height() / 2)
    {
        m_y = object.m_area->top() - m_h;
        rotate(1, -1);
    }
    if ((object.m_area->contains(m_area->topRight())
        || object.m_area->contains(m_area->bottomRight()))
        && m_area->right() - object.m_area->left() < BLOCK_SIZE / 2)
    {
        m_x = object.m_area->left() - m_w;
        rotate(-1, 1);
    }
    if ((object.m_area->contains(m_area->topLeft())
        || object.m_area->contains(m_area->topRight()))
        && m_area->bottom() - object.m_area->top() < object.m_area->height() / 2)
    {
        m_y = object.m_area->bottom();
        rotate(1, -1);
    }
    m_area->moveTo(m_x, m_y);
}

bool Ball::checkBorder(QRectF area)
{
        if (area.left() > m_area->left())
        {
            m_x = area.left();
            rotate(-1, 1);
        }
        else if (area.bottom() < m_area->bottom() - m_h)
        {
            m_y = area.bottom() - m_h;
            rotate(1, -1);
            return false;
        }
        else if (area.right() < m_area->right() - m_w)
        {
            m_x = area.right() - m_w;
            rotate(-1, 1);
        }
        else if (area.top() > m_area->top())
        {
            m_y = area.top();
            rotate(1, -1);
        }
        m_area->moveTo(m_x, m_y);
        return true;
}
