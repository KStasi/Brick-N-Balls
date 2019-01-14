#include "ballspool.h"

BallsPool::BallsPool() {}

BallsPool::~BallsPool(){}

void BallsPool::create(int &count, int size, double x, double y, double x_speed, double y_speed)
{
    if (count)
    {
        if (x_speed < SPEED_DEFAULT || y_speed < SPEED_DEFAULT)
        {
            x_speed *= SPEED_DEFAULT / std::abs(std::min(x_speed, y_speed));
            y_speed *= SPEED_DEFAULT / std::abs(std::min(x_speed, y_speed));
        }
        pool.append(new Ball(x, y, size, size, x_speed, y_speed));
        count--;
    }
}

void BallsPool::update(Map *m_map, double time_left)
{
    QMutableVectorIterator<Ball *> iter_pool(pool);
    Ball *ball;

    while (iter_pool.hasNext())
    {
        ball = iter_pool.next();
        ball->update(time_left);
        if (!ball->checkBorder(QRectF(0, HEADER, W_SIZE - BLOCK_SIZE / 4, H_SIZE - HEADER)))
        {
            iter_pool.remove();
            continue ;
        }
        for(Brick *brick : m_map->map)
            if (ball->m_area->intersects(*brick->m_area)
            || ball->m_area->contains(*brick->m_area))
            {
                ball->checkMove(*brick);
                brick->decreasePower();
            }

        for(Ball *other_ball : pool)
            if (other_ball != ball && ball->m_area->intersects(*other_ball->m_area))
                ball->checkMove(*other_ball);
    }

    QMutableVectorIterator<Brick *> iter_map(m_map->map);
    while (iter_map.hasNext())
        if (iter_map.next()->m_power < 1)
            iter_map.remove();
}
