#pragma once

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "ButtonController.h"

#include "../vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

using json = nlohmann::json;

namespace sen {
    class Popup : public Box
    {
    private:
        json m_response;
        Text m_message;
        ButtonController m_bc;
        bool m_pausesState, m_blursBG;
    public:
        Popup(const sf::RenderWindow& window,
              const sf::String &message = "STANDARD POPUP",
              bool pausesState = false, bool blursBG = false);
        virtual void render(sf::RenderTarget& target);
        virtual void update(sf::RenderWindow& window);
        bool hasResponse() const;
        const json& getResponse() const;
        bool pausesState() const {return m_pausesState;}
        void setMessage(const sf::String& message);
    };
}