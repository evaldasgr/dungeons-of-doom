#pragma once

#include <raylib.h>

class Menu
{
public:
    void init();

    void update();
    void draw();

private:
    Texture2D m_texture;
};
