#include "AssetsMan.hpp"

Engine::AssetsMan::AssetsMan()
{
}

Engine::AssetsMan::~AssetsMan()
{
}

void Engine::AssetsMan::addTexture(int Id, const std::string &filePath, bool wantRepeated = false)
{
     auto texture = std::make_unique<sf::Texture>();

     if (texture->loadFromFile(filePath))
     {
          texture->setRepeated(wantRepeated);
          mTexture[Id] = std::move(texture);
     }
};

void Engine::AssetsMan::addFont(int Id, const std::string &filePath)
{
     auto font = std::make_unique<sf::Font>();

     if (font->loadFromFile(filePath))
     {
          mFont[Id] = std::move(font);
     }
};

const sf::Texture &Engine::AssetsMan::getTexture(int Id) const
{
     return *(mTexture.at(Id).get());
};

const sf::Font &Engine::AssetsMan::getFont(int Id) const
{
     return *(mFont.at(Id).get());
};