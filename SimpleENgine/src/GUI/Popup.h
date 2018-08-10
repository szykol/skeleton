#pragma once

#include "TextBox.h"
#include <SFML/Graphics.hpp>

namespace sen {
    enum class PopupBaseline {TOP, BOTTOM};
    class Popup : public TextBox
    {
    private:
        float m_duration;
        sf::Clock m_timer;
        bool m_shouldVanish;
    public:
        Popup(const sf::RenderWindow& window,const sf::String& string,
              PopupBaseline baseline = PopupBaseline::BOTTOM, float duration = 5.f);
        bool shouldVanish();
    private:
        using TextBox::setPosition;
        using TextBox::move;
        using TextBox::update;
    };
}