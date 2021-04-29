#include "Snake.hpp"

Snake::Snake() : mBody(std::list<sf::Sprite>(4))
{
     mHead = --mBody.end();
     mTail = mBody.begin();
}

Snake::~Snake()
{
}

void Snake::Init(const sf::Texture &texture)
{
     float x = 16.f;
     for (auto &piece : mBody)
     {
          piece.setTexture(texture);
          piece.setPosition({x, 16.f});
          x += 16.f;
     }
}

void Snake::Move(const sf::Vector2f &direction)
{
     mTail->setPosition(mHead->getPosition() + direction);
     mHead = mTail;
     ++mTail;

     if (mTail == mBody.end())
     {
          mTail = mBody.begin();
     }
}

bool Snake::isOn(const sf::Sprite &other) const
{
     return other.getGlobalBounds().intersects(mHead->getGlobalBounds());
}

bool Snake::selfIntersecting() const
{
     bool Flag = false;

     for (auto piece = mBody.begin(); piece != mBody.end(); piece++)
     {
          if (mHead != piece)
          {
               Flag = isOn(*piece);

               if (Flag)
               {
                    break;
               }
          }
     }

     return Flag;
}

void Snake::Grow(const sf::Vector2f &direction)
{
     sf::Sprite newPiece;

     newPiece.setTexture(*(mBody.begin()->getTexture()));
     newPiece.setPosition(mHead->getPosition() + direction);

     mHead = mBody.insert(++mHead, newPiece);
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
     for (auto &piece : mBody)
     {
          target.draw(piece);
     }
}