/** 
 * This file is needed in order to convert 
 * some sfml and sen datatypes to json and vice versa
 * @note   For more informations check
 * here https://github.com/nlohmann/json#arbitrary-types-conversions
 */
#pragma once

#include <SFML/Graphics.hpp>
#include "../vendor/nlohmann/json.hpp"
#include "../UI/Text.h"
using json = nlohmann::json;

namespace sf {
    // sf::Color
    inline void to_json(json& j, const Color& c)
    {
		j = json{ {"red", c.r},{"green", c.g}, {"blue", c.b},
        {"alpha",c.a}};
    }
    inline void from_json(const json& j, Color& c)
    {
        c.r = j.at("red").get<sf::Uint8>();
        c.g = j.at("green").get<sf::Uint8>();
        c.b = j.at("blue").get<sf::Uint8>();
        c.a = j.at("alpha").get<sf::Uint8>();
    }
    // end sf::Color

    // sf::Vector<T>
    template<typename T>
    inline void to_json(json& j, const sf::Vector2<T>& v)
    {
        j = json{
            {"x", v.x},
            {"y", v.y}
        };
    }
    template<typename T>
    inline void from_json(const json& j, sf::Vector2<T>& v)
    {
        v.x = j.at("x").get<T>();
        v.y = j.at("y").get<T>();
    }
    // end sf::Vector<T>
}
