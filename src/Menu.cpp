#include <Menu.hpp>
#include <iostream>

void Menu::init()
{
    const char* resourcePath = GetApplicationDirectory();
    m_texture = LoadTexture(TextFormat("%s/textures/menu.png", resourcePath));
}

void Menu::update()
{
    
}

void Menu::draw()
{
    DrawTexture(m_texture, 0, 0, WHITE);
}
