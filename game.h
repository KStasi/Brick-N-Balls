#ifndef GAME_H
#define GAME_H
#include <QWindow>
#include <QTimer>
#include <QString>
#include "ballspool.h"
#include "winstate.h"
#include "failstate.h"
#include "mapbuilder.h"
#include "winstate.h"
#include "failstate.h"
#include "playstate.h"
#include "platform.h"
#define TRIES_BY_DEFAULT 50
#define POWER_BY_DEFAULT 10

class Game: QObject, public Drawable
{
    Q_OBJECT
public:
    static Game* start(QWindow *window);
    void launchGame();
    State           *m_state;
    Map             *m_map;
    BallsPool       *m_balls_pool;
    Platform        *m_platform;
    int             n_balls = BALLS_BY_DEFAULT;
    void            draw(QPainter *painter);
private:
    Game(QWindow *window);
    QWindow         *m_window;
    QTimer          *tmr;
    int             level = 1;
    int             score = 0;
    int             n_try = TRIES_BY_DEFAULT;
    int             result = 0;
    int             m_w = BLOCKS_BY_DEFAULT;
    int             m_h = BLOCKS_BY_DEFAULT;
    int             m_power = POWER_BY_DEFAULT;
private slots:
    void            checkState();
};

#endif // GAME_H
