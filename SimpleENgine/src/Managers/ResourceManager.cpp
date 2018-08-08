#include "ResourceManager.h"

std::unordered_map<std::string, sf::Texture> ResourceManager::map;

const sf::Texture & ResourceManager::get(const std::string & key)
{
	auto find = map.find("default");
	if (find == map.end())
		setDefault();

	find = map.find(key);
	if (find != map.end())
		return find->second;
	else
	{
		std::cout << "Couldn't find texture in memory.. loading!" << std::endl;
		sf::Texture tTemp;
		if (!tTemp.loadFromFile("Images/" + key))
		{
			std::cout << "Couldn't load from file! Take a default one!" << std::endl;
			return map["default"];
		}
		else
		{
			map.insert(std::pair < std::string, sf::Texture>(key, tTemp));
			return map[key];
		}
	}
}

void ResourceManager::setDefault()
{
	sf::Texture fDefault;
	fDefault.loadFromFile("Images/error.png");
	map.insert(std::pair<std::string, sf::Texture>("default", fDefault));
}
