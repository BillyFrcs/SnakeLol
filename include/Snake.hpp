#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <list>

class Snake : public sf::Drawable
{
private:
    std::list<sf::Sprite> mBody;
    std::list<sf::Sprite>::iterator mHead;
    std::list<sf::Sprite>::iterator mTail;

public:
    Snake();
    ~Snake();

    //Method
    void Init(const sf::Texture &texture);
    void Move(const sf::Vector2f &direction);
    bool isOn(const sf::Sprite &other) const;
    bool isSelfIntersecting(bool &isFlag) const;
    void Grow(const sf::Vector2f &direction);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};