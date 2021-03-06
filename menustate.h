#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "state.h"
#include "game.h"

class MenuState : public State
{
public:
    MenuState(bool *game_loaded, Game **game);
    void drawLogo(QPainter &painter);
    void drawScene(QPainter &painter);
    bool processClick(QPointF m_cursor);
    void stopGame();
private:
    bool *m_game_loaded;
    Game **m_game;
};

#endif // MENUSTATE_H
