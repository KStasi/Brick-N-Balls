#include "game.h"

Game::Game(QWindow *window) : QObject()
{
    m_window = window;
}

Game* Game::start(QWindow *window)
{
    static Game *game = new Game(window);
    game->launchGame();
    return game;
}

void Game::launchGame()
{
    m_map = MapBuilder(m_w, m_h, m_power).generateMap();
    m_balls_pool = new BallsPool();
    m_platform = Platform::create(W_SIZE / 2, H_SIZE - 40, W_SIZE /10, 10);
    tmr = new QTimer();
    m_state=new PlayState();
    connect(tmr, SIGNAL(timeout()), this, SLOT(checkState()));
    tmr->start(200);
}

void Game::draw(QPainter *painter)
{
    painter->setPen(QColor(0, 0, 0));
    painter->setFont(QFont("Helvetica", 20));
    painter->drawText(QRectF(0, 0, W_SIZE, HEADER), "Level: " +
    QString::number(level) + "\tScore: " + QString::number(score) +
    "\tTries left: " + QString::number(n_try) + "\tBalls: " + QString::number(n_balls));
}

void Game::checkState()
{

}
