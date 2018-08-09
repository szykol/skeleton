 #include "Popup.h"

namespace sen {
	Popup::Popup(PopupStyle style, const sf::String& message, bool pausesState, bool blursBG)
        : m_pausesState(pausesState),
		  m_blursBG(blursBG), TextBox(message)
    {
        Box::setFillColor(sf::Color(30,30,30, 235));
        Box::setOutlineColor(sf::Color(255,255,255, 128));
        Box::setOutlineThickness(-5.5);

        m_message.setFillColor(Box::getOutlineColor());
        	if (style == PopupStyle::CUSTOM) return;


        setButtonPlacing(ButtonPlacing::HORIZONTAL);
        auto okButton = std::make_shared<Button>("OK");
        
        okButton->setOnClickCalback(
            [this] {
                m_response["Response"] = true;
            }
        );
        auto declButton = std::make_shared<Button>("CANCEL");
        declButton->setOnClickCalback(
            [this] {
                m_response["Response"] = false;
            }
        );
        auto latButton = std::make_shared<Button>("LATER");
         latButton->setOnClickCalback(
             [this] {
                 m_response["Response"] = "later";
             }
         );
        if (style == PopupStyle::UNARY)
            pushButtons(okButton);
        else if (style == PopupStyle::BINARY)
        {
            okButton->getTextObject().setString("YES");
            declButton->getTextObject().setString("NO");
            pushButtons(declButton, okButton);
        }
        else if (style == PopupStyle::TERNARY)
        {
            latButton->getTextObject().setString("LATER");
            pushButtons(declButton, latButton, okButton);
        }
        setSize(sf::Vector2f(400.f, 300.f));
        placeButtons();
	}
	void Popup::render(sf::RenderTarget & target)
    {
        Box::render(target);
        m_message.render(target);
        ButtonController::render(target);
    }

    void Popup::update(sf::RenderWindow & window)
    {
        ButtonController::update(window);
        if(hasResponse() && m_callback)
            m_callback(m_response);
    }
    bool Popup::hasResponse() const
    {
        return m_response.size();
    }
    const json & Popup::getResponse() const
    {
        return m_response;
    }
    void Popup::setMessage(const sf::String& message)
    {
        m_message.setString(message);
    }

}
