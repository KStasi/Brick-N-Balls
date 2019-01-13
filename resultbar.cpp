#include "resultbar.h"

ResultBar::ResultBar(){}

int ResultBar::getPower()
{
    return m_power;
}

bool ResultBar::getStart()
{
    return m_start;
}

bool ResultBar::getGameMode()
{
    return m_game_mode;
}

int ResultBar::getLevel()
{
    return m_level;
}

int ResultBar::getScore()
{
    return m_score;
}

int ResultBar::getTry()
{
    return m_try;
}

int ResultBar::getResult()
{
    return m_result;
}

void ResultBar::incrementLevel()
{
    m_level++;
}

void ResultBar::changeScore(int type)
{
    switch (type)
    {
    case 1:
        m_score += block;
        break;
    case 2:
        m_score += level;
        break;
    case -1:
        m_score += use_try;
        break;
    case -2:
        m_score += fail;
        break;
    }
}

void ResultBar::changeResult(int new_result)
{
    m_result = new_result;
}

void ResultBar::decrementTry()
{
    m_try--;
}

void ResultBar::reset()
{
    m_power = POWER_BY_DEFAULT;
    m_level = 1;
    m_score = 0;
    m_try = TRIES_BY_DEFAULT;
    m_result = 0;
}

void ResultBar::newLevel()
{
    m_power = abs(POWER_BY_DEFAULT + m_level * 3);
    m_level += 1;
    m_try = TRIES_BY_DEFAULT - (m_level / 5) * 5;
    m_try = (m_try > 0) ? m_try : 2;
    m_result = 0;
}

void ResultBar::switchStart()
{
    m_start = (m_start == 0);
}

void ResultBar::setGameMode(bool launch)
{
    m_game_mode = launch;
}
