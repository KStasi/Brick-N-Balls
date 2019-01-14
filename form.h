#ifndef FORM_H
#define FORM_H
#include <QWindow>
#include <QPainter>
#include <QExposeEvent>
#include <QKeyEvent>
#include <QBackingStore>
#include <QElapsedTimer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QMouseEvent>
#include "game.h"
#include "menustate.h"

namespace Ui {
class Form;
}

class Form : public QWindow
{
    Q_OBJECT
public:
    explicit Form(QWindow *parent = nullptr);
    void setAnimating(bool isAnimating);
    ~Form();

private:
    QElapsedTimer m_updateTimer;
    QTimer m_ballsTimer;
    Game *game;
    bool m_isAnimating = false;
    QBackingStore *m_backingStore = nullptr;
    QMediaPlayer player;
    QMediaPlaylist playlist;
    bool event(QEvent *event);
    void exposeEvent(QExposeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void drawMenu();
    void renderLater();
    void renderNow();
    void renderScene();
    void updateScene();
    void setSize();
    void setAudio();
    bool isAnimating() const;
    bool m_mouse_pressed = 0;
    bool m_game_loaded = false;
    MenuState menu = MenuState(&m_game_loaded, &game);
private slots:
    void pushBalls();
};

#endif // FORM_H
