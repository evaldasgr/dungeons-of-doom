#include <State/StateGame.hpp>
#include <Game.hpp>

StateGame::StateGame(Game& game):
    State(game),
    m_level(game)
{

}

StateGame::~StateGame()
{
    
}

void StateGame::onSetCurrent()
{
    m_level.load("levl0.txt");
}

void StateGame::onUnsetCurrent()
{
    
}

void StateGame::update()
{
    m_level.update();
}

void StateGame::draw()
{
    m_level.draw();
}
