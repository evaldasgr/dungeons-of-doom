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

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();
        // Play
        if (CheckCollisionPointRec(mousePos, {0, 159, 800, 43}))
        {
            
        }
        // Slot 1
        else if (CheckCollisionPointRec(mousePos, {0, 202, 800, 41}))
        {
            
        }
        // Slot 2
        else if (CheckCollisionPointRec(mousePos, {0, 243, 800, 38}))
        {
            
        }
        // Toggle Sounds
        else if (CheckCollisionPointRec(mousePos, {0, 281, 800, 41}))
        {
            
        }
        // Toggle Music
        else if (CheckCollisionPointRec(mousePos, {0, 322, 800, 41}))
        {
            
        }
        // Help
        else if (CheckCollisionPointRec(mousePos, {0, 363, 800, 41}))
        {
            
        }
        // Exit
        else if (CheckCollisionPointRec(mousePos, {0, 404, 800, 42}))
        {
            m_game.stop();
        }
    }
}

void StateMenu::draw()
{
    DrawTexture(m_game.getResourceManager().getTexture(TextureId::Menu), 0, 0, WHITE);
}
