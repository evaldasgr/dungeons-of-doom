#pragma once

#include <State/State.hpp>

class StateGame: public State
{
public:
    StateGame(Game& game);
    virtual ~StateGame();

    virtual void update();
    virtual void draw();
};
