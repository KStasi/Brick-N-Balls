#ifndef PLATFORM_H
#define PLATFORM_H
#include "drawable.h"
#include "gameobject.h"

class Platform : public Drawable, public GameObject
{
public:
    static Platform *create(double x, double y, int w, int h);
    void draw(QPainter *painter);
    void update(double x, int with_ball);
private:
    Platform(double x, double y, int w, int h, int r, int g, int b);
    Platform(double x, double y, int w, int h);
    int m_with_ball = 1;
};

#endif // PLATFORM_H
