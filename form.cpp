#include "form.h"
#include "ui_form.h"

Form::Form(QWindow *parent) :
    QWindow(parent),
    m_backingStore(new QBackingStore(this))
{
    setGeometry(0, HEADER, W_SIZE, H_SIZE);
    setMaximumWidth(W_SIZE);
    setMaximumHeight(H_SIZE);
    setMinimumWidth(W_SIZE);
    setMinimumHeight(H_SIZE);
    m_backingStore->resize(size());
    game = Game::start(this);
    m_updateTimer.start();
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
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
    m_mouse = new QPointF(event->localPos());

    if (game->n_balls < 1)
        m_mouse_pressed = 0;

    if (!m_mouse_pressed)
        game->m_platform->update(event->x(), game->n_balls);
}

void Form::mousePressEvent(QMouseEvent *event)
{
    m_mouse_pressed = 1;
}

void Form::mouseReleaseEvent(QMouseEvent *event)
{
    if (game->n_balls && !m_ballsTimer.isActive())
    {

        m_ballsTimer.start();
        m_ballsTimer.setInterval(300);
        connect(&m_ballsTimer, SIGNAL(timeout()), this, SLOT(pushBalls()));
    }
}

void Form::pushBalls()
{
    double x_speed;
    double y_speed;

    if (game->n_balls < 1)
    {
        game->n_balls = 0;
        game->m_platform->update(game->m_platform->getX(), game->n_balls);
    }
    x_speed = abs(m_mouse->x() - game->m_platform->getX() - W_SIZE / 20) * ((m_mouse->x() > W_SIZE / 2) ? 1 : -1);
    y_speed = abs(m_mouse->y() - H_SIZE + 40) * ((m_mouse->y() > H_SIZE / 2) ? -1 : 1);
    game->m_balls_pool->create(&game->n_balls, BLOCK_SIZE / 2,
    game->m_platform->getX() + W_SIZE / 20, H_SIZE - 40, x_speed, y_speed);
    if (!game->n_balls)
        m_ballsTimer.stop();
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

    time_left = static_cast<double>(m_updateTimer.elapsed()) / 1000.f;
    if (time_left > 0)
    {
        m_updateTimer.restart();
        game->m_balls_pool->update(game->m_map, time_left);
    }
}

void Form::renderScene()
{
    QPaintDevice *device;

    m_backingStore->beginPaint(QRect(0, 0, width(), height()));
    device = m_backingStore->paintDevice();

    QPainter painter(device);
    painter.fillRect(0, 0, width(), height(), Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);
    game->m_state->drawScene(&painter, game->m_map, game->m_balls_pool, game->m_platform);
    game->draw(&painter);
    painter.end();

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

}
