 #include "Popup.h"

namespace sen {
	Popup::Popup(const sf::RenderWindow& window,
        const sf::String& message, bool pausesState, bool blursBG)
        : m_acceptButton("OK"), m_message(message), m_pausesState(pausesState),
		  m_blursBG(blursBG)
    {
        Box::setFillColor(sf::Color(30,30,30, 235));
        Box::setOutlineColor(sf::Color(255,255,255, 128));
        Box::setOutlineThickness(-5.5);

        Box::setPosition({window.getSize().x/2.f, window.getSize().y/2.f});
        const sf::Vector2f textSize(
            m_message.getLocalBounds().width,
            m_message.getLocalBounds().height
        );
        Box::setSize({textSize.x * 2.5f, textSize.y * 4.f + 100});
        
        m_message.setPosition(Box::getPosition());
		m_message.setFillColor(Box::getOutlineColor());
        m_acceptButton.setPosition(Box::getPosition());
        m_acceptButton.move({Box::getSize().x / 2.f - m_acceptButton.getSize().x,
                            m_acceptButton.getSize().y * 1.25f});
        m_acceptButton.getTextObject().setCharacterSize(24U);

        json& respRef = m_response;
        m_acceptButton.setOnClickCalback(
            [&respRef] {
              respRef["Response"] = true;
            }
        );
	}
	void Popup::render(sf::RenderTarget & target)
    {
        Box::render(target);
        m_message.render(target);
        m_acceptButton.render(target);
    }

    void Popup::update(sf::RenderWindow & window)
    {
        m_acceptButton.update(window);
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
