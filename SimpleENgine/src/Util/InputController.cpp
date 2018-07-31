#include "InputController.h"


namespace sen {

	InputController::InputController(Text & text)
		: m_text(text), m_cursor(text)
	{
	}

	void InputController::handleInput(const sf::Event& evnt)
	{
		sf::String string = m_text.getString();

		auto unicode = evnt.text.unicode;
		if (unicode >= 'A' && unicode <= 'Z'
			|| unicode >= 'a' && unicode <= 'z'
			|| unicode >= '1' && unicode <= '9'
			|| unicode == ' ')

		{
			string += char(evnt.key.code);
			if(validate())
				m_text.setString(string);
		}
		else if (unicode == '\b' && !string.isEmpty())
		{
			string.erase(string.getSize() - 1);
			if(validate())
				m_text.setString(string);
		}
		
	}

	//void InputController::update()
	//{
	//}

	void InputController::render(sf::RenderTarget & target)
	{
		m_cursor.render(target);
	}
	bool InputController::validate()
	{
		if (m_validateFunc)
			return m_validateFunc(m_text.getString());
		else
			return true;
	}
}
