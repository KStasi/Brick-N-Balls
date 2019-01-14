#ifndef RESULTBAR_H
#define RESULTBAR_H
#include "drawable.h"
#include "bonuscontroller.h"
#define POWER_BY_DEFAULT 10
#define TRIES_BY_DEFAULT 5

class ResultBar
{
public:
    ResultBar();
    int getPower();
    int getLevel();
    int getScore();
    int getTry();
    int getResult();
    void incrementLevel();
    void changeScore(int type);
    void changeResult(int new_result);
    void decrementTry();
    void reset();
    void resetBalls();
    void newLevel();
    bool getStart();
    int getBalls();
    void updateBalls();
    void switchStart();
    bool getGameMode();
    void setGameMode(bool launch);
    int *getBallsLink();
    QPointF  m_cursor;
    QPointF  m_platform;
    BonusController m_bonusController;
private:
    int m_power = POWER_BY_DEFAULT;
    int m_level = 1;
    int m_score = 0;
    int m_try = TRIES_BY_DEFAULT;
    int m_result = 0;
    bool m_start = 1;
    bool m_game_mode = 0;
    int m_balls = BALLS_BY_DEFAULT;
    enum scores_changes
    {
        block = 10,
        level = 100,
        fail = -200,
        use_try = -50
    };

};

#endif // RESULTBAR_H
