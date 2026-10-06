#pragma once

#include <State/StateId.hpp>
#include <unordered_map>
#include <memory>

class State;

class StateManager
{
public:
    StateManager();

    void add(StateId id, std::unique_ptr<State> state);

    void setCurrent(StateId id);

    void update();
    void draw();

private:
    StateId m_currentId;
    std::unordered_map<StateId, std::unique_ptr<State>> m_states;
};
