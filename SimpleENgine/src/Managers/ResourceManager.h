#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
class ResourceManager
{
private:
	static std::unordered_map<std::string, sf::Texture> map;
public:
	static const sf::Texture& get(const std::string &key);
	static void setDefault();
};

