#ifndef BRICK_H
#define BRICK_H
#include <QObject>
#include <QString>
#include "drawable.h"
#include "gameobject.h"

class Brick : public QObject, public Drawable, public GameObject
{
public:
    Brick(double x, double y, int w, int h, int power, int r, int g, int b);
    Brick(double x, double y, int w, int h, int power);
    void draw(QPainter *painter);
    void changeMainColor(int r, int g, int b);
    void decreasePower();
    int m_power;
private:
};

#endif // BRICK_H
