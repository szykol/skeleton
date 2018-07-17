#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>

class FontManager
{
private:
	static std::unordered_map<std::string, sf::Font> map;
public:
	static const sf::Font& get(const std::string &key);
	static void setDefault();
};
