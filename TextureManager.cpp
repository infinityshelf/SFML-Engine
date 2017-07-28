#include "TextureManager.hpp"
const std::string kRobo = "robo";
const std::string kRoboFilePath = "robo.png";
TextureManager *TextureManager::s_instance = nullptr;
TextureManager::TextureManager() {

}
TextureManager::~TextureManager() {
    
}

void TextureManager::loadTexture(const std::string &key, const std::string &fileName)
{
    /* Load the texture */
    sf::Texture texture;
    texture.loadFromFile(fileName);

    /* Add it to the list of textures */
    this->textures[key] = texture;

    return;
}

sf::Texture& TextureManager::getRef(const std::string &texture)
{
    return this->textures.at(texture);
}