#include <Resource/ResourceManager.hpp>
#include <cassert>

ResourceManager::ResourceManager()
{
    // corrupts when written to std::string
    m_path = GetApplicationDirectory();
}

bool ResourceManager::loadTexture(TextureId id, const std::string& filename)
{
    m_textures[id] = LoadTexture(TextFormat("%s/textures/%s", m_path, filename.c_str()));
    
    if (m_textures[id].width == 0)
    {
        m_textures.erase(id);
        return false;
    }

    return true;
}

Texture2D& ResourceManager::getTexture(TextureId id)
{
    assert(m_textures.contains(id));

    return m_textures[id];
}
