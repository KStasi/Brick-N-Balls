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
    ~Game();
    static Game* start();
    void launchGame();
    void updatePlatform();
    State           *m_state = nullptr;
    Map             *m_map = nullptr;
    BallsPool       *m_balls_pool = nullptr;
    Platform        *m_platform = nullptr;
    ResultBar       m_result_bar;
    QRectF          m_menu_area = QRectF(9 * W_SIZE / 10 * 0.95, H_SIZE - W_SIZE / 7, W_SIZE / 10, W_SIZE / 10);
    void            draw(QPainter &painter);
    void            endGame();
private:
    Game();
    QTimer          *tmr = nullptr;
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
