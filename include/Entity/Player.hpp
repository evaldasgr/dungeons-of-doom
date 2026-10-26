#pragma once

#include <Entity/Entity.hpp>

class Player: public Entity
{
public:
    Player(Game& game, Level& level);
    ~Player();

    void update();
    void draw();
};
