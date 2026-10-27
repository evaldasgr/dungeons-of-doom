#include <State/StateHelp.hpp>
#include <Game.hpp>
#include <algorithm>

StateHelp::StateHelp(Game& game):
    State(game),
    m_scroll(0.f),
    m_draggingScrollbar(false)
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

        Rectangle scrollbarRect = {782, 19, 16, 562};
        if (CheckCollisionPointRec(mousePos, scrollbarRect))
        {
            m_draggingScrollbar = true;
            Rectangle currentScrollbarRect = {782, 19 + m_scroll * 378, 15, 184};
            if (CheckCollisionPointRec(mousePos, currentScrollbarRect))
                m_draggingScrollbarFrom = mousePos.y - currentScrollbarRect.y;
            else
                m_draggingScrollbarFrom = 92;
        }
    }
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        m_draggingScrollbar = false;
    }
    
    if (m_draggingScrollbar)
    {
        Vector2 mousePos = GetMousePosition();
        m_scroll = std::clamp((mousePos.y - (19 + m_draggingScrollbarFrom)) / 378, 0.f, 1.f);
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
