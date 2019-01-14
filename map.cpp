#include "map.h"

Map::Map(int w, int h)
{
    m_w = w;
    m_h = h;
}

Map::~Map()
{
    for(Brick *brick : map)
        delete brick;
    map.clear();
}
