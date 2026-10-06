#pragma once

#include <State/State.hpp>
#include <string>
#include <Resource/TextureId.hpp>

class StateLoading: public State
{
public:
    StateLoading(Game& game);
    virtual ~StateLoading();

    virtual void onSetCurrent();
    virtual void onUnsetCurrent();

    virtual void update();
    virtual void draw();

private:
    enum class LoadingState
    {
        Initial, TextDrawn, Done, Error
    };

    void loadTexture(TextureId id, const std::string& filename);

    LoadingState m_loadingState;
    std::string m_errorText;
};
