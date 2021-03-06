#include "form.h"
#include "ui_form.h"

Form::Form(QWindow *parent) :
    QWindow(parent),
    m_backingStore(new QBackingStore(this))
{
    setSize();
    setAudio();
    m_updateTimer.start();
}

void Form::setSize()
{
    setGeometry(0, HEADER, W_SIZE, H_SIZE);
    setMaximumWidth(W_SIZE);
    setMaximumHeight(H_SIZE);
    setMinimumWidth(W_SIZE);
    setMinimumHeight(H_SIZE);
    m_backingStore->resize(size());
}

void Form::setAudio()
{
    playlist.addMedia(QUrl::fromLocalFile(
        "/home/kstasi/Documents/C++/BricksNBalls/background.wav"));
    playlist.setPlaybackMode(QMediaPlaylist::Loop);
    player.setPlaylist(&playlist);
    player.play();
}

bool Form::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest)
    {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void Form::exposeEvent(QExposeEvent *event)
{
    if (isExposed())
        renderNow();
    Q_UNUSED(event);
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_game_loaded || !game->m_result_bar.getGameMode())
        return ;
    game->m_result_bar.m_cursor = QPointF(event->localPos());

    if (game->m_result_bar.getBalls() < 1)
        m_mouse_pressed = 0;

    if (!m_mouse_pressed)
        game->m_platform->update(event->x(), game->m_result_bar.getBalls());
}

void Form::mousePressEvent(QMouseEvent *event)
{
    if (!m_game_loaded)
    {
        menu.processClick(QPointF(event->localPos()));
        if (menu.menuChecked(event->localPos().toPoint()))
            close();
        return ;
    }

    if (m_game_loaded && (game->m_menu_area.contains(event->localPos())
        || game->m_state->menuChecked(event->localPos().toPoint())))
        menu.stopGame();

    if (!m_game_loaded)
        return ;

    game->m_result_bar.m_cursor = QPointF(event->localPos());

    if (game->m_state->processClick(game->m_result_bar))
        m_mouse_pressed = 1;
    else
        m_mouse_pressed = 0;
}

void Form::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_game_loaded || !game->m_result_bar.getGameMode())
    {
        m_mouse_pressed = 0;
        return ;
    }

    game->m_result_bar.m_cursor = QPointF(event->localPos());

    if (game->m_result_bar.m_bonusController.getStreams() > 0
        && !game->m_result_bar.getStart() && m_mouse_pressed)
    {

        game->m_result_bar.m_bonusController.useStream();
        game->m_result_bar.m_platform = QPointF(event->localPos());
        QTimer::singleShot(300, this, SLOT(pushBalls()));
    }
}

void Form::keyPressEvent(QKeyEvent *event)
{
    if (!m_game_loaded && event->key() == Qt::Key_Space)
    {
        m_game_loaded = 1;
        game = Game::start();
    }
    if (!m_game_loaded && event->key() == Qt::Key_Escape)
        close();
}

void Form::pushBalls()
{
    double x_speed;
    double y_speed;

    if (!game->m_result_bar.getGameMode())
        return ;
    game->updatePlatform();

    x_speed = abs(game->m_result_bar.m_platform.x() - game->m_platform->getX() - W_SIZE / 20)
        * ((abs(game->m_result_bar.m_platform.x()) > game->m_platform->getX() + W_SIZE / 20) ? 1 : -1);
    y_speed = abs(game->m_result_bar.m_platform.y() - H_SIZE + 40) * -1;

    game->m_balls_pool->create(*game->m_result_bar.getBallsLink(),
        static_cast<int>(BLOCK_SIZE / 2 * game->m_result_bar.m_bonusController.getSizeIndex()),
        game->m_platform->getX() + W_SIZE / 20 - BLOCK_SIZE / 4, H_SIZE - 40, x_speed, y_speed);

    if (game->m_result_bar.getBalls() > 0 && game->m_result_bar.getStart())
        QTimer::singleShot(300, this, SLOT(pushBalls()));
}

void Form::renderNow()
{
    if (!isExposed())
        return;
    updateScene();
    renderScene();
    if (m_isAnimating)
        renderLater();
}

void Form::renderLater()
{
    requestUpdate();
}

void Form::updateScene()
{
    double time_left;

    time_left = static_cast<double>(m_updateTimer.elapsed()) / 1000;
    if (time_left > 0 && m_game_loaded)
    {
        m_updateTimer.restart();
        game->m_balls_pool->update(game->m_map, time_left,
        game->m_result_bar.m_bonusController);
    }
}

void Form::renderScene()
{
    m_backingStore->beginPaint(QRect(0, 0, width(), height()));

    QPainter painter(m_backingStore->paintDevice());
    painter.fillRect(0, 0, width(), height(), QColor("#181C28"));

    if (m_game_loaded)
        game->draw(painter);
    else
        menu.drawScene(painter);
    m_backingStore->endPaint();
    m_backingStore->flush(QRect(0, 0, width(), height()));
}

bool Form::isAnimating() const
{
    return m_isAnimating;
}

void Form::setAnimating(bool isAnimating)
{
    m_isAnimating = isAnimating;
    if (isAnimating)
        renderLater();
}

Form::~Form()
{
    player.stop();
    if (game)
        delete game;
    delete m_backingStore;
}
