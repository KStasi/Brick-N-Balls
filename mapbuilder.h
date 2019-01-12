#ifndef MAPBUILDER_H
#define MAPBUILDER_H
#include "map.h"
#include <QRandomGenerator>
#include <iostream>
#include <fstream>
#include "drawable.h"

using namespace std;

class MapBuilder
{
public:
    MapBuilder(int w, int h, int max_power);
    Map *openMap(char *file);
    Map *generateMap();
    Map *createMap();
    void writeMap(char *file, Map &map);
private:
    int m_h;
    int m_w;
    int m_max_power;
};

#endif // MAPBUILDER_H
