#include <State/StateLoading.hpp>
#include <Game.hpp>
#include <raylib.h>
#include <State/StateMenu.hpp>

StateLoading::StateLoading(Game& game):
    State(game),
    m_loadingState(LoadingState::Initial)
{

}

StateLoading::~StateLoading()
{
    
}

void StateLoading::onSetCurrent()
{

}

void StateLoading::onUnsetCurrent()
{
    
}

void StateLoading::update()
{
    if (m_loadingState == LoadingState::TextDrawn)
    {
        loadTexture(TextureId::Menu, "menu.png");

        if (m_loadingState != LoadingState::Error)
        {
            m_game.getStateManager().add(StateId::Menu, std::make_unique<StateMenu>(m_game));
            m_game.getStateManager().setCurrent(StateId::Menu);
            // Just in case
            m_loadingState = LoadingState::Done;
        }
    }
}

void StateLoading::draw()
{
    ClearBackground(BLACK);

    switch (m_loadingState)
    {
    case LoadingState::Initial:
        DrawText("Loading...", 0, 0, 20, WHITE);
        m_loadingState = LoadingState::TextDrawn;
        break;
    case LoadingState::Error:
        DrawText(m_errorText.c_str(), 0, 0, 20, RED);
        break;
    }
}

void StateLoading::loadTexture(TextureId id, const std::string& filename)
{
    if (!m_game.getResourceManager().loadTexture(id, filename))
    {
        m_loadingState = LoadingState::Error;
        m_errorText = "Failed to load " + filename;
    }
}
