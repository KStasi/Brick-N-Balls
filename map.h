#ifndef MAP_H
#define MAP_H
#include "brick.h"
#include <QVector>
#include <memory>
class Map
{
public:
    Map(int w, int h);
    ~Map();
    int getW();
    int getH();
    QVector<Brick *> map;
private:
    int m_w;
    int m_h;
};

#endif // MAP_H
