#pragma once

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "ButtonController.h"
#include "InputBox.h"
#include "../Util/InputController.h"

#include "../vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <functional>

using json = nlohmann::json;

namespace sen {
    typedef std::function<void(const json&)> OnResponseCallback;
    enum class PromptStyle {UNARY, BINARY, TERNARY, INPUT, CUSTOM};
    class Prompt : public TextBox, public ButtonController
    {
    protected:
        json m_response;
        bool m_pausesState, m_blursBG;
        OnResponseCallback m_callback;
        bool m_shouldUpdateButtonPlacing = false;
        std::unique_ptr<InputBox> m_input;
    public:
        Prompt(PromptStyle style, const sf::String &message = "STANDARD MESSAGE",
              bool pausesState = true, bool blursBG = false);
        virtual void render(sf::RenderTarget& target);
        virtual void update(sf::RenderWindow& window);
        bool hasResponse() const;
        const json& getResponse() const;
        bool pausesState() const {return m_pausesState;}
        void setMessage(const sf::String& message);
        void setOnResponseCallback(const OnResponseCallback& callback) {m_callback = callback;}
		void setButtonBaseline(ButtonBaseline baseline);
		void placeButtons(float gap = 30.f);
        void setPosition(const sf::Vector2f& position);
        void setSize(const sf::Vector2f& size);
    private:
        using ButtonController::placeButtons;
    };
}