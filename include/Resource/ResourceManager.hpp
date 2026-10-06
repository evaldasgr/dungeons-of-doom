#pragma once

#include <Resource/TextureId.hpp>
#include <raylib.h>
#include <string>
#include <unordered_map>

class ResourceManager
{
public:
    ResourceManager();

    bool loadTexture(TextureId id, const std::string& filename);

    Texture2D& getTexture(TextureId id);

private:
    const char* m_path;
    std::unordered_map<TextureId, Texture2D> m_textures;
};
