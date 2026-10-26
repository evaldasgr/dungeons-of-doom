#pragma once

class Game;
class Level;

class Entity
{
public:
    Entity(Game& game, Level& level);
    virtual ~Entity();

    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    Game& m_game;
    Level& m_level;
};
