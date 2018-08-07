#include "FontManager.h"

std::unordered_map<std::string, sf::Font> FontManager::map;

const sf::Font & FontManager::get(const std::string & key)
{
	auto find = map.find("default");
	if (find == map.end())
		setDefault();

	if (key == "Roboto")
		return map["default"];

	find = map.find(key);
	if (find != map.end())
		return find->second;
	else
	{
		std::cout << "Couldn't find font in memory.. loading from file!" << std::endl;
		sf::Font fTemp;
		if (!fTemp.loadFromFile("Fonts/" + key + ".ttf"))
		{
			std::cout << "Couldn't load from file. Take a default one!" << std::endl;
			return map["default"];
		}
		else
		{
			map.insert(std::pair < std::string, sf::Font>(key, fTemp));
			return map[key];
		}
	}

}

void FontManager::setDefault()
{
	sf::Font fDefault;
	fDefault.loadFromFile("Fonts/Roboto.ttf");
	map.insert(std::pair<std::string, sf::Font>("default", fDefault));
}
