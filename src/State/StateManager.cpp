#include <State/StateManager.hpp>
#include <State/State.hpp>
#include <cassert>

StateManager::StateManager():
    m_currentId(StateId::Unset)
{
    
}

void StateManager::add(StateId id, std::unique_ptr<State> state)
{
    m_states[id] = std::move(state);
}

void StateManager::setCurrent(StateId id)
{
    assert(m_states.contains(id));

    m_currentId = id;
}

void StateManager::update()
{
    assert(m_states.contains(m_currentId));

    m_states[m_currentId]->update();
}

void StateManager::draw()
{
    assert(m_states.contains(m_currentId));

    m_states[m_currentId]->draw();
}
