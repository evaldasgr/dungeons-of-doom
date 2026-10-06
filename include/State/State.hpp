#pragma once

class Game;

class State
{
public:
    State(Game& game);
    virtual ~State();

    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    Game& m_game;
};
