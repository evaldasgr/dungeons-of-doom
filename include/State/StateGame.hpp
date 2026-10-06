#pragma once

#include <State/State.hpp>

class StateGame: public State
{
public:
    StateGame(Game& game);
    virtual ~StateGame();

    virtual void onSetCurrent();
    virtual void onUnsetCurrent();

    virtual void update();
    virtual void draw();
};
