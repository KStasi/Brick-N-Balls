#include "form.h"
#include "ui_form.h"

Form::Form(QWindow *parent) :
    QWindow(parent),
    m_backingStore(new QBackingStore(this))
{
    setSize();
    game = Game::start(this);
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
    game->m_result_bar.m_cursor = new QPointF(event->localPos());

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
    if (game->n_balls && !game->m_result_bar.getStart())
    {
        game->m_result_bar.m_platform = new QPointF(event->localPos());
        QTimer::singleShot(300, this, SLOT(pushBalls()));
    }
}

void Form::pushBalls()
{
    double x_speed;
    double y_speed;

    game->updatePlatform();

    x_speed = abs(game->m_result_bar.m_platform->x() - game->m_platform->getX() - W_SIZE / 20)
    * ((abs(game->m_result_bar.m_platform->x()) > game->m_platform->getX() + W_SIZE / 20) ? 1 : -1);
    y_speed = abs(game->m_result_bar.m_platform->y() - H_SIZE + 40) * -1;
    game->m_balls_pool->create(&game->n_balls, BLOCK_SIZE / 2,
    game->m_platform->getX() + W_SIZE / 20 - BLOCK_SIZE / 4, H_SIZE - 40, x_speed, y_speed);

    if (game->n_balls > 0)
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

    time_left = static_cast<double>(m_updateTimer.elapsed()) / 1000.f;
    if (time_left > 0)
    {
        m_updateTimer.restart();
        game->m_balls_pool->update(game->m_map, time_left);
    }
}

void Form::renderScene()
{
    m_backingStore->beginPaint(QRect(0, 0, width(), height()));

    QPainter painter(m_backingStore->paintDevice());
    painter.fillRect(0, 0, width(), height(), QColor("#181C28"));
    game->draw(&painter);

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
