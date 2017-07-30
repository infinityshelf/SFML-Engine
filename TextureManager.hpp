#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
private:
    static TextureManager *s_instance;
    std::map<std::string,sf::Texture> textures;
    TextureManager();
    
public:
    static TextureManager *instance() {
        if (!s_instance) {
            s_instance = new TextureManager;
        }
        return s_instance;
    }
    ~TextureManager();
    /* Add a texture from a file */
    void loadTexture(const std::string& key, const std::string &fileName);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string &texture);
    
};
#endif