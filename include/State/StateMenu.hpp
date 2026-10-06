#pragma once

#include <State/State.hpp>
#include <raylib.h>

class StateMenu: public State
{
public:
    StateMenu(Game& game);
    virtual ~StateMenu();

    virtual void onSetCurrent();
    virtual void onUnsetCurrent();

    virtual void update();
    virtual void draw();

private:
    Music m_music;
};
