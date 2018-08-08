 #include "Popup.h"

namespace sen {
	Popup::Popup(const sf::String& message, bool pausesState, bool blursBG)
        : m_pausesState(pausesState),
		  m_blursBG(blursBG), TextBox(message)
    {
        Box::setFillColor(sf::Color(30,30,30, 235));
        Box::setOutlineColor(sf::Color(255,255,255, 128));
        Box::setOutlineThickness(-5.5);

        m_message.setFillColor(Box::getOutlineColor());
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
	std::shared_ptr<Popup> createPopup(PopupStyle style)
	{
		if (style == PopupStyle::CUSTOM)
    		return std::shared_ptr<Popup>();

        auto popup = std::make_shared<Popup>();
        popup->setButtonPlacing(ButtonPlacing::HORIZONTAL);

        json& response = popup->m_response;

        auto okButton = std::make_shared<Button>("OK");
        
        okButton->setOnClickCalback(
            [&response] {
                response["Response"] = true;
            }
        );
        
        auto declButton = std::make_shared<Button>("CANCEL");
        declButton->setOnClickCalback(
            [&response] {
                response["Response"] = false;
            }
        );
        
        auto latButton = std::make_shared<Button>("LATER");
         latButton->setOnClickCalback(
             [&response] {
                 response["Response"] = "later";
             }
         );

        if (style == PopupStyle::UNARY)
        {
            popup->pushButtons(okButton);
            // this won't work because the size/position is about to change
            //popup->placeButtons(popup->getGlobalBounds());
        }
        else if (style == PopupStyle::BINARY)
        {
            okButton->getTextObject().setString("YES");
            declButton->getTextObject().setString("NO");

            popup->pushButtons(declButton, okButton);
        }
        else if (style == PopupStyle::TERNARY)
        {
            latButton->getTextObject().setString("LATER");
            popup->pushButtons(declButton, latButton, okButton);
        }
        popup->setSize(sf::Vector2f(400.f, 300.f));
        //popup->placeButtons(popup->getGlobalBounds());

        return popup;
	}
}
