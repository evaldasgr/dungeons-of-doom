#pragma once

#include <State/State.hpp>
#include <Level.hpp>

class StateGame: public State
{
public:
    StateGame(Game& game);
    virtual ~StateGame();

    virtual void onSetCurrent();
    virtual void onUnsetCurrent();

    virtual void update();
    virtual void draw();

private:
    Level m_level;
};
