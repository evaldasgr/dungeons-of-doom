#include <State/StateMenu.hpp>
#include <Game.hpp>

StateMenu::StateMenu(Game& game):
    State(game)
{
    m_music = LoadMusicStream(TextFormat("%s/music/menu2.wav", GetApplicationDirectory()));
}

StateMenu::~StateMenu()
{
    
}

void StateMenu::onSetCurrent()
{
    PlayMusicStream(m_music);
}

void StateMenu::onUnsetCurrent()
{
    StopMusicStream(m_music);
}

void StateMenu::update()
{
    UpdateMusicStream(m_music);
}

void StateMenu::draw()
{
    DrawTexture(m_game.getResourceManager().getTexture(TextureId::Menu), 0, 0, WHITE);
}
