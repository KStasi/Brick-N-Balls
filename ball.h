#ifndef BALL_H
#define BALL_H
#include "drawable.h"
#include "gameobject.h"
#define SPEED_DEFAULT 250

class Ball : public Drawable, public GameObject
{
public:
    Ball(double x, double y, int w, int h, double m_speed_x, double m_speed_y, int r, int g, int b);
    Ball(double x, double y, int w, int h, double m_speed_x = SPEED_DEFAULT * 0.4, double m_speed_y = -SPEED_DEFAULT);
    void draw(QPainter *painter);
    void checkMove(GameObject *object);
    void checkBorder(QRectF *area);
    void update(double delta_time);
    void rotate(int x_rot, int y_rot);
private:
    double m_speed_x;
    double m_speed_y;
};

#endif // BALL_H
