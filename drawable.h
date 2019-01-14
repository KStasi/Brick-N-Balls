#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QWidget>
#include <QPainter>
#define W_SIZE 600
#define H_SIZE 1000
#define BLOCKS_BY_DEFAULT 10
#define BLOCK_SIZE (W_SIZE / BLOCKS_BY_DEFAULT)
#define HEADER BLOCK_SIZE * 2

class Drawable
{
public:
    virtual void draw(QPainter &painter)=0;
    virtual void drawRect(QPainter &painter, double x, double y, int w, int h, QColor mainColor);
    virtual void drawBall(QPainter &painter, double x, double y, int w, int h, QColor mainColor);
    virtual ~Drawable(){}
};

#endif // DRAWABLE_H
