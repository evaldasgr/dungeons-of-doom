#include <Level.hpp>
#include <Entity/Entity.hpp>
#include <Game.hpp>
#include <fstream>
#include <raylib.h>
#include <iostream>

Level::Level(Game& game):
    m_game(game),
    m_width(0),
    m_height(0)
{

}

void Level::load(const std::string& filename)
{
    auto path = TextFormat("%s/levels/%s", GetApplicationDirectory(), filename.c_str());
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Could not load level " << filename << std::endl;
        return;
    }

    file >> m_width >> m_height;
    if (m_width <= 0 || m_height <= 0 || m_width > 32 || m_height > 32)
    {
        std::cerr << "Invalid level size " << filename << std::endl;
        return;
    }

    m_walls.resize(m_width * m_height);
    m_floors.resize(m_width * m_height);

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int tileId;
            if (!(file >> tileId) || tileId < 0 || tileId > 255)
            {
                std::cerr << "Invalid wall tile data " << filename << std::endl;
                return;
            }
            m_walls[j + i * m_width] = tileId;
        }
    }

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int tileId;
            if (!(file >> tileId) || tileId < 0 || tileId > 255)
            {
                std::cerr << "Invalid flor tile data " << filename << std::endl;
                return;
            }
            m_floors[j + i * m_width] = tileId;
        }
    }
}

void Level::update()
{
    for (auto& e : m_entities)
    {
        e->update();
    }
}

void Level::draw()
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            uint8_t tileId = m_floors[j + i * m_width];

            DrawTexturePro(
                m_game.getResourceManager().getTexture(TextureId::Floors),
                {(float)((tileId % 8) * 32), (float)((tileId / 8) * 32), 32.f, 32.f},
                {(float)(j * 32), (float)(i * 32), 32.f, 32.f},
                {0.0f, 0.0f},
                0.f,
                WHITE
            );
        }
    }

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            uint8_t tileId = m_walls[j + i * m_width];
            if (tileId == 0)
                continue;

            DrawTexturePro(
                m_game.getResourceManager().getTexture(TextureId::Walls),
                {(float)((tileId % 8) * 32), (float)((tileId / 8) * 32), 32.f, 32.f},
                {(float)(j * 32), (float)(i * 32), 32.f, 32.f},
                {0.0f, 0.0f},
                0.f,
                WHITE
            );
        }
    }

    for (auto& e : m_entities)
    {
        e->draw();
    }
}
