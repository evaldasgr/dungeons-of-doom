#pragma once

#include <State/StateManager.hpp>
#include <Resource/ResourceManager.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();

    StateManager& getStateManager();
    ResourceManager& getResourceManager();

private:
    void update();
    void draw();

    StateManager m_stateManager;
    ResourceManager m_resourceManager;
};
