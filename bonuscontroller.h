#ifndef BONUSCONTROLLER_H
#define BONUSCONTROLLER_H
#include <QRandomGenerator>

class BonusController
{
public:
    BonusController();
    ~BonusController();
    double getBonusIndex();
    double getSizeIndex();
    double getTryIndex();
    double getStreams();
    void generateBonus();
    void resetBonuses();
    void resetStream();
    void useStream();
private:
    double m_bonus_index = 1.0;
    double m_size_index = 1.0;
    double m_try_index = 1.0;
    int m_streams = 1;
};

#endif // BONUSCONTROLLER_H
