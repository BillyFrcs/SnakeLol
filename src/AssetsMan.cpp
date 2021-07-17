#include "AssetsMan.hpp"

Engine::AssetsMan::AssetsMan()
{
}

Engine::AssetsMan::~AssetsMan()
{
}

//Texture
void Engine::AssetsMan::addTexture(int id, const std::string &filePath, bool wantRepeated)
{
     auto texture = std::make_unique<sf::Texture>();

     if (texture->loadFromFile(filePath))
     {
          texture->setRepeated(wantRepeated);
          mTexture[id] = std::move(texture);
     }
};

//Font
void Engine::AssetsMan::addFont(int id, const std::string &filePath)
{
     auto font = std::make_unique<sf::Font>();

     if (font->loadFromFile(filePath))
     {
          mFont[id] = std::move(font);
     }
};

const sf::Texture &Engine::AssetsMan::getTexture(int id) const
{
     return *(mTexture.at(id).get());
};

const sf::Font &Engine::AssetsMan::getFont(int id) const
{
     return *(mFont.at(id).get());
};