#include <Game.hpp>
#include <State/StateId.hpp>
#include <State/StateLoading.hpp>
#include <memory>
#include <raylib.h>

Game::Game():
    m_running(false)
{
    InitWindow(800, 600, "Dungeons of Doom");
    InitAudioDevice();
    SetTargetFPS(60);

    m_stateManager.add(StateId::Loading, std::make_unique<StateLoading>(*this));
    m_stateManager.setCurrent(StateId::Loading);
}

Game::~Game()
{
    CloseWindow();
}

StateManager& Game::getStateManager()
{
    return m_stateManager;
}

ResourceManager& Game::getResourceManager()
{
    return m_resourceManager;
}

void Game::run()
{
    m_running = true;
    while (m_running)
    {
        update();
        draw();
    }
}

void Game::stop()
{
    m_running = false;
}

void Game::update()
{
    if (WindowShouldClose())
        m_running = false;

    m_stateManager.update();
}

void Game::draw()
{
    BeginDrawing();

    m_stateManager.draw();

    EndDrawing();
}
