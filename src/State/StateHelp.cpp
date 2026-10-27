#include <State/StateHelp.hpp>
#include <Game.hpp>

StateHelp::StateHelp(Game& game):
    State(game),
    m_scroll(0.f)
{
    
}

StateHelp::~StateHelp()
{
    
}

void StateHelp::onSetCurrent()
{
    
}

void StateHelp::onUnsetCurrent()
{
    
}

void StateHelp::update()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, {782, 2, 16, 16}))
        {
            m_scroll = std::max(0.f, m_scroll - 0.1f);
        }
        else if (CheckCollisionPointRec(mousePos, {782, 582, 16, 16}))
        {
            m_scroll = std::min(1.f, m_scroll + 0.1f);
        }
    }
}

void StateHelp::draw()
{
    // Draw border
    DrawRectangleLines(0, 0, 800, 600, GRAY);
    DrawRectangleLines(1, 1, 798, 598, WHITE);

    // Draw scrollbar background
    DrawLine(782, 2, 782, 598, WHITE);
    DrawRectangle(782, 2, 16, 596, LIGHTGRAY);
    // Draw scroll up button
    DrawLineEx({786, 14}, {789.5f, 8}, 2, GRAY);
    DrawLineEx({789.5f, 8}, {793, 14}, 2, GRAY);
    // Draw scroll down button
    DrawLineEx({786, 587}, {789.5f, 593}, 2, GRAY);
    DrawLineEx({789.5f, 593}, {786+7, 587}, 2, GRAY);
    // Draw scrollbar
    DrawRectangle(782, 19 + m_scroll * 378, 15, 184, GRAY);

    // Draw text
    DrawTexturePro(
        m_game.getResourceManager().getTexture(TextureId::Help),
        {0, m_scroll * 1074, 779, 596},
        {2, 2, 779, 596},
        {0, 0},
        0,
        WHITE
    );
}
