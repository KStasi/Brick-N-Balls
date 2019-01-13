#ifndef RESULTBAR_H
#define RESULTBAR_H
#include "drawable.h"
#define POWER_BY_DEFAULT 10
#define TRIES_BY_DEFAULT 2

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
    void newLevel();
    bool getStart();
    void switchStart();
    bool getGameMode();
    void setGameMode(bool launch);
    QPointF  *m_cursor = nullptr;
    QPointF  *m_platform = nullptr;
private:
    int m_power = POWER_BY_DEFAULT;
    int m_level = 1;
    int m_score = 0;
    int m_try = TRIES_BY_DEFAULT;
    int m_result = 0;
    bool m_start = 1;
    bool m_game_mode = 0;
    enum scores_changes
    {
        block = 10,
        level = 100,
        fail = -200,
        use_try = -50
    };

};

#endif // RESULTBAR_H
