#include "Popup.h"
#include "PopupBinary.h"

#include <memory>

namespace sen {
	PopupBinary::PopupBinary(const sf::RenderWindow & window,
		const sf::String & message,
		bool pausesState, bool blursBG)
		: Popup(window, message, pausesState, blursBG)
	{
        auto declineButton = std::make_shared<Button>("CANCEL");

        auto& jRef = m_response;
        declineButton->setOnClickCalback(
            [&jRef] {
                jRef["Response"] = false;
            }
        );
        m_bc.pushButtons(declineButton);
        m_bc.placeButtons(getGlobalBounds());
	}
	// void PopupBinary::render(sf::RenderTarget & target)
	// {
	// }
	/*void PopupBinary::update(sf::RenderWindow & window)
	{
	}*/
}