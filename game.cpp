#include "game.h"

Game::Game() : QObject()
{}

Game* Game::start()
{
    static Game *game = new Game();
    game->launchGame();
    return game;
}

void Game::launchGame()
{
    levelStart();
    m_platform = Platform::create(W_SIZE / 2, H_SIZE - 40, W_SIZE /10, 10);
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateReult()));
    tmr->start(200);
}

void Game::levelStart()
{
    m_state = new PlayState();
    m_map = MapBuilder(m_w, m_h, m_result_bar.getPower()).generateMap();
    newTry();
    m_result_bar.setGameMode(1);
    m_result_bar.switchStart();
}

void Game::newTry()
{
    if (m_result_bar.getTry() < 1)
        return ;
    m_balls_pool = new BallsPool();
    m_blocks = m_map->map.size();
    m_try = m_result_bar.getTry();
    n_balls = BALLS_BY_DEFAULT;
}

void Game::updatePlatform()
{
    if (n_balls == BALLS_BY_DEFAULT)
    {
        m_result_bar.switchStart();
        m_platform->update(m_platform->getX(), 0);
    }
    if (n_balls < 1)
        n_balls = 0;
}

void Game::draw(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing);
    m_state->drawScene(painter, m_map, m_balls_pool, m_platform);


    painter->setPen(QColor(240, 240, 255));
    if (m_result_bar.getGameMode())
    {
        painter->setFont(QFont("Helvetica", 25));
        painter->drawText(QRectF(10, 10, W_SIZE, HEADER), "Level: " +
        QString::number(m_result_bar.getLevel()) + "\t\tScore: " +
        QString::number(m_result_bar.getScore()) + "\t\tTries: " +
        QString::number(m_result_bar.getTry()) + "\t\tBalls: " +
        QString::number(n_balls));
        painter->drawEllipse(m_menu_area);
    }
    else
    {
        painter->setFont(QFont("Helvetica", 45));
        painter->drawText(QRectF(W_SIZE / 3.5, HEADER, W_SIZE / 2, HEADER * 6), "Level: " +
        QString::number(m_result_bar.getLevel()) + "\nScore: " +
        QString::number(m_result_bar.getScore()));
    }
    painter->end();
}

void Game::changeStrategy()
{
    if (m_result_bar.getResult() == 2)
        return ;
    if (!m_result_bar.getTry())
        m_result_bar.changeResult(-1);
    else if (!m_balls_pool->pool.isEmpty() && m_map->map.isEmpty())
        m_result_bar.changeResult(1);
}

void Game::executeStrategy()
{
    while (m_blocks != m_map->map.size())
    {
        m_blocks--;
        m_result_bar.changeScore(1);
    }
    if (!m_balls_pool->pool.size())
    {
        m_result_bar.decrementTry();
        m_result_bar.changeScore(-1);
        m_result_bar.switchStart();
        newTry();
    }
}

void Game::changeState()
{
    switch (m_result_bar.getResult())
    {
    case 1:
        delete m_state;
        m_state = new WinState();
        break;
    case -1:
        delete m_state;
        m_state = new FailState();
        break;
    case 2:
        delete m_state;
        levelStart();
        m_result_bar.changeResult(0);
        break;
    }
    if(m_result_bar.getResult())
        m_state->changeBehaviour(m_result_bar);
}

void Game::updateReult()
{
    if (!m_result_bar.getStart() && !m_result_bar.getResult()
    && m_result_bar.getTry())
        ;
    else
    {
        changeStrategy();
        changeState();
        if (m_result_bar.getGameMode() && m_result_bar.getStart())
            executeStrategy();
    }
    changeState();
}

void Game::endGame()
{
    delete m_state;
    delete m_map;
    delete m_balls_pool;
    m_state = new FailState();
    m_state->changeBehaviour(m_result_bar);
    m_result_bar.reset();
    m_result_bar.changeResult(2);
    tmr->stop();
    delete tmr;
}
