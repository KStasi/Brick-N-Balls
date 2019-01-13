#ifndef FORM_H
#define FORM_H
#include <QWindow>
#include <QPainter>
#include <QExposeEvent>
#include <QBackingStore>
#include <QElapsedTimer>
#include <QTimer>
#include <QMouseEvent>
#include "game.h"

namespace Ui {
class Form;
}

class Form : public QWindow
{
    Q_OBJECT
public:
    explicit Form(QWindow *parent = 0);
    void setAnimating(bool isAnimating);
    ~Form();

private:
    QElapsedTimer m_updateTimer;
    QTimer m_ballsTimer;
    Game *game;
    bool m_isAnimating = false;
    QBackingStore *m_backingStore = nullptr;
    bool event(QEvent *event);
    void exposeEvent(QExposeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void renderLater();
    void renderNow();
    void renderScene();
    void updateScene();
    void setSize();
    bool isAnimating() const;
    bool m_mouse_pressed = 0;
private slots:
    void pushBalls();
};

#endif // FORM_H
