#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QColor>
#include <QRectF>

class GameObject
{
public:
    explicit GameObject(double x, double y, int w, int h, int r, int g, int b);
    ~GameObject();
    double getX();
    double getY();
    QRectF *m_area = nullptr;
protected:
    double m_x;
    double m_y;
    int m_h;
    int m_w;
    QColor mainColor;
};

#endif // GAMEOBJECT_H
