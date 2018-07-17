#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>

template<typename T>
class TestMap : public std::unordered_map<std::string, T>
{
public:
	T & get(const std::string &key);
	const T& operator[](const std::string &key) const;
	T operator[](const std::string &key);
	TestMap();
	~TestMap();
};

class FontMap : public std::unordered_map < std::string, sf::Font>
{
public:
	FontMap();
	const sf::Font& operator[](const std::string &key);
};