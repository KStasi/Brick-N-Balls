#include "menustate.h"

MenuState::MenuState(bool *launch, bool *game_loaded, Game **game)
{
    m_launch = launch;
    m_game_loaded = game_loaded;
    m_game = game;
}

bool MenuState::processClick(ResultBar &result_bar) {}
void MenuState::changeBehaviour(ResultBar &result_bar) {}

bool MenuState::processClick(QPointF *m_cursor)
{
    if (m_reset_area.contains(m_cursor->toPoint()))
    {
        *m_game_loaded = 1;
        *m_game = Game::start();
        return (*m_launch = true);
    }
    return false;
}

void MenuState::stopGame()
{
    *m_game_loaded = 0;
    *m_launch = 0;
    (*m_game)->endGame();
}

void MenuState::drawScene(QPainter *painter, Map *map, BallsPool *pool, Platform *platform)
{
    drawResultWindow(painter, QColor("#181C28"), QColor(75, 85, 121));
    painter->drawText(QRect(11 * W_SIZE / 24, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18), "Start");
}
