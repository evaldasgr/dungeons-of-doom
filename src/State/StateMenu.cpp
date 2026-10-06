#include <State/StateMenu.hpp>
#include <Game.hpp>

StateMenu::StateMenu(Game& game):
    State(game)
{

}

StateMenu::~StateMenu()
{
    
}

void StateMenu::update()
{
    
}

void StateMenu::draw()
{
    DrawTexture(m_game.getResourceManager().getTexture(TextureId::Menu), 0, 0, WHITE);
}
