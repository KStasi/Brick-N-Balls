#ifndef STATE_H
#define STATE_H
#include <QWidget>
#include <QPainter>
#include "ballspool.h"
#include "map.h"
#include "platform.h"
#include "resultbar.h"

class State
{
public:
    State();
    virtual void changeBehaviour(ResultBar &result_bar)=0;
    virtual void drawScene(QPainter &painter, Map *map, BallsPool *pool, Platform *platform)=0;
    virtual bool processClick(ResultBar &result_bar)=0;
    virtual void drawResultWindow(QPainter &painter, QColor mainColor, QColor secondColor);
    virtual bool menuChecked(QPoint mouse);
    virtual ~State();
protected:
    QRect m_reset_area = QRect(2 * W_SIZE / 6, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18);
    QRect m_menu_area = QRect(3 * W_SIZE / 8, 14 * H_SIZE / 20, W_SIZE / 4, H_SIZE / 20);
};

#endif // STATE_H
