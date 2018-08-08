#pragma once

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "ButtonController.h"

#include "../vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

using json = nlohmann::json;

namespace sen {
    enum class PopupStyle {UNARY, BINARY, TERNARY, CUSTOM};
    class Popup : public TextBox, private ButtonController
    {
    protected:
        json m_response;
        Text m_message;
        bool m_pausesState, m_blursBG;
    public:
        Popup(const sf::String &message = "STANDARD MESSAGE",
              bool pausesState = true, bool blursBG = false);
        virtual void render(sf::RenderTarget& target);
        virtual void update(sf::RenderWindow& window);
        bool hasResponse() const;
        const json& getResponse() const;
        bool pausesState() const {return m_pausesState;}
        void setMessage(const sf::String& message);

        using ButtonController::pushButtons;
        using ButtonController::removeButton;
        using ButtonController::setButtonFixedSize;
        using ButtonController::emplaceButtons;
        using ButtonController::placeButtons;

        friend std::shared_ptr<Popup> createPopup(PopupStyle style);
    };
	std::shared_ptr<Popup> createPopup(PopupStyle style);
}