#pragma once

#ifndef ASSETSMAN_HPP

	#include <SFML/Graphics/Font.hpp>
	#include <SFML/Graphics/Texture.hpp>

	#include <map>
	#include <memory>
	#include <string>

namespace Engine
{
class AssetsMan
{
private:
	std::map<int, std::unique_ptr<sf::Texture>> mTexture;
	std::map<int, std::unique_ptr<sf::Font>> mFont;

public:
	AssetsMan();
	~AssetsMan();

	void addTexture(int id, const std::string& filePath, bool wantRepeated = false);
	void addFont(int id, const std::string& filePath);

	const sf::Texture& getTexture(int id) const;
	const sf::Font& getFont(int id) const;
};
} //Namespace Engine

#endif