#pragma once

#include <State/State.hpp>

class StateMenu: public State
{
public:
    StateMenu(Game& game);
    virtual ~StateMenu();

    virtual void update();
    virtual void draw();
};
