#include "ballspool.h"

BallsPool::BallsPool() {}

void BallsPool::create(int *count, int size, double x, double y, double x_speed, double y_speed)
{
    if (*count)
    {
        if (x_speed < SPEED_DEFAULT || y_speed < SPEED_DEFAULT)
        {
            x_speed *= SPEED_DEFAULT / std::abs(std::min(x_speed, y_speed));
            y_speed *= SPEED_DEFAULT / std::abs(std::min(x_speed, y_speed));
        }
        pool.append(new Ball(x, y, size, size, x_speed, y_speed));
        (*count)--;
    }
}
void BallsPool::update(Map *m_map, double time_left)
{
    for(Ball *ball : pool)
    {
        ball->update(time_left);
        ball->checkBorder(new QRectF(0, 50, W_SIZE, H_SIZE - 100));
        for(Brick *brick : m_map->map)
            if (ball->m_area->intersects(*brick->m_area))
            {
                ball->checkMove(brick);
                brick->decreasePower();
            }
        for(Ball *other_ball : pool)
            if (other_ball != ball && ball->m_area->intersects(*other_ball->m_area))
                ball->checkMove(other_ball);
    }

    QMutableVectorIterator<Brick *> iter(m_map->map);
    while (iter.hasNext())
        if (iter.next()->m_power < 1)
            iter.remove();
}
