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
#include "resultbar.h"

class Game: QObject, public Drawable
{
    Q_OBJECT
public:
    static Game* start(QWindow *window);
    void launchGame();
    void updatePlatform();
    State           *m_state;
    Map             *m_map;
    BallsPool       *m_balls_pool;
    Platform        *m_platform;
    ResultBar       m_result_bar;
    int             n_balls = BALLS_BY_DEFAULT;
    void            draw(QPainter *painter);
private:
    Game(QWindow *window);
    QWindow         *m_window;
    QTimer          *tmr;
    int             m_w = BLOCKS_BY_DEFAULT;
    int             m_h = BLOCKS_BY_DEFAULT;
    int             m_blocks;
    int             m_try;
    void            changeStrategy();
    void            executeStrategy();
    void            changeState();
    void            levelStart();
    void            newTry();
private slots:
    void            updateReult();
};

#endif // GAME_H
