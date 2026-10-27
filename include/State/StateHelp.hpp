#pragma once

#include <State/State.hpp>
#include <raylib.h>

class StateHelp: public State
{
public:
    StateHelp(Game& game);
    virtual ~StateHelp();

    virtual void onSetCurrent();
    virtual void onUnsetCurrent();

    virtual void update();
    virtual void draw();

private:
    float m_scroll;
};
