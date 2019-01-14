#include "mapbuilder.h"
MapBuilder::MapBuilder(int w, int h, int max_power)
{
    m_w = w;
    m_h = h;
    m_max_power = max_power;
}

Map *MapBuilder::openMap(char *fileName)
{
    int w;
    int h;
    int x;
    int y;
    int power;
    Map *newMap;

    ifstream file(fileName);
    file >> w >> h >> power;
    newMap = new Map(w, h);
    for (int var = 0; var < w * h; ++var)
    {
        file >> x >> y >> power;
        (newMap->map).append(new Brick(x, y, BLOCK_SIZE, BLOCK_SIZE, power));

    }
    file.close();
    return newMap;
}

Map *MapBuilder::generateMap()
{
    Map *map;

    srand(static_cast<unsigned int>(time(nullptr)));
    map = new Map(m_w, m_h);
    map->map.reserve(m_w * m_h);
    for (int i = 0; i < m_w * m_h * static_cast<double>(0.01 + static_cast<double>(rand() % 91) / 100); i++)
        map->map.append(new Brick(static_cast<int>(m_w * static_cast<double>(rand() % 100) / 100)
            * BLOCK_SIZE, static_cast<int>(m_h * static_cast<double>(rand() % 100) / 100 + 2)
            * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, static_cast<int>(m_max_power *
            static_cast<double>(rand() % 91 + 10) / 100)));
    return map;
}

void MapBuilder::writeMap(char *fileName, Map &map)
{
    ofstream file(fileName);

    file << m_w << " " << m_h << " " << m_max_power << endl;
    for (int i = 0; i < m_w * m_h; i++)
        file << map.map[i]->getX() << " " << map.map[i]->getY()
        << " " << map.map[i]->m_power << endl;
    file.close();
}
