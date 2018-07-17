#include "TestMap.h"



template<typename T>
const T & TestMap<T>::operator[](const std::string & key) const
{

	// TODO: insert return statement here
}

template<typename T>
T TestMap<T>::operator[](const std::string & key)
{
	return T();
}

FontMap::FontMap()
{
	sf::Font fDefault;
	fDefault.loadFromFile("Fonts/Roboto.ttf");
	this->insert(std::pair < std::string, sf::Font>("default", fDefault));
}

const sf::Font & FontMap::operator[](const std::string & key)
{
	auto find = this->find(key);
	if (find != this->end())
	{
		std::cout << "Znalazlem!" << std::endl;
		return find->second;
	}
	else
	{
		std::cout << "Nie znalazlem.. laduje!" << std::endl;
		sf::Font fTemp;
		if (!fTemp.loadFromFile("Fonts/" + key + ".ttf"))
		{
			std::cout << "Nie udalo sie zaladowac! Daje ci standardowa czcionke!" << std::endl;
			return this->operator[]("default");
		}
		else
		{
			this->insert(std::pair < std::string, sf::Font>(key, fTemp));
			return this->operator[](key);
		}
	}

}
