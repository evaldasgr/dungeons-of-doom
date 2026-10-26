#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include <Entity/Entity.hpp>

class Game;

class Level
{
public:
    Level(Game& game);

    void load(const std::string& filename);

    void update();
    void draw();

private:
    Game& m_game;
    std::vector<std::uint8_t> m_walls;
    std::vector<std::uint8_t> m_floors;
    std::vector<std::unique_ptr<Entity>> m_entities;
    int m_width;
    int m_height;
};
