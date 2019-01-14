#include "bonuscontroller.h"

BonusController::BonusController(){}

BonusController::~BonusController(){}


double BonusController::getBonusIndex()
{
    return m_bonus_index;
}

double BonusController::getSizeIndex()
{
    return m_size_index;
}


double BonusController::getStreams()
{
    return m_streams;
}

double BonusController::getTryIndex()
{
    return m_try_index;
}

void BonusController::useStream()
{
    if (m_streams > 0)
        m_streams--;
    else
        m_streams = 0;
}

void BonusController::resetBonuses()
{
    m_bonus_index = 1.0;
    m_size_index = 1.0;
    m_try_index = 1.0;
    m_streams = 1;
}

void BonusController::resetStream()
{
    m_streams = 1;
}

void BonusController::generateBonus()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    if (rand() % 100 > 85)
        m_bonus_index = 1 + rand() % 61 / 10;
    else if (rand() % 100 > 55 && rand() % 100 < 65)
        m_streams++;
    else if (rand() % 100 > 64)
        m_try_index = 1.1 + rand() % 26 / 10;
    else if (rand() % 100 < 15)
        m_size_index = 1.2 + rand() % 11 / 10;
    else if (rand() % 100 > 11  && rand() % 100 < 50)
        resetBonuses();
}
