#include "menustate.h"

MenuState::MenuState(bool *game_loaded, Game **game)
{
    m_game_loaded = game_loaded;
    m_game = game;
}

bool MenuState::processClick(ResultBar &result_bar) {}
void MenuState::changeBehaviour(ResultBar &result_bar) {}

bool MenuState::processClick(QPointF *m_cursor)
{
    if (m_reset_area.contains(m_cursor->toPoint()))
    {
        *m_game = Game::start();
        return (*m_game_loaded = true);
    }
    return false;
}

void MenuState::stopGame()
{
    *m_game_loaded = 0;
    (*m_game)->endGame();
}

void MenuState::drawLogo(QPainter &painter)
{
    painter.setPen(QPen(QColor(237, 237, 237)));
    painter.setBrush(QBrush(QColor(58, 70, 85)));
    painter.drawRoundRect(2 * BLOCK_SIZE, H_SIZE / 6, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
    painter.drawRoundRect(4 * BLOCK_SIZE, H_SIZE / 6, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
    painter.drawRoundRect(6 * BLOCK_SIZE, H_SIZE / 6, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
    painter.drawRoundRect(6 * BLOCK_SIZE, H_SIZE / 6 + 2 * BLOCK_SIZE, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
    painter.setPen(QPen(QColor(237, 154, 78)));
    painter.setBrush(QBrush(QColor(237, 154, 78)));
    painter.drawEllipse(3 * BLOCK_SIZE, H_SIZE / 3, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
}

void MenuState::drawScene(QPainter &painter, Map *map, BallsPool *pool, Platform *platform)
{
    drawResultWindow(painter, QColor("#181C28"), QColor(75, 85, 121));
    painter.drawText(QRect(11 * W_SIZE / 25, 23 * H_SIZE / 37, W_SIZE / 3, H_SIZE / 18), "Start");
    painter.drawText(QRect(7 * W_SIZE / 16, 28 * H_SIZE / 40, W_SIZE / 4, H_SIZE / 20), " Quit");
    drawLogo(painter);
}
