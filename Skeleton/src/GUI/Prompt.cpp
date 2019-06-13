 #include "Prompt.h"

namespace sen {
	Prompt::Prompt(PromptStyle style, const sf::String& message, bool pausesState)
        : m_pausesState(pausesState),
		  TextBox(message)
    {
        Box::setFillColor(sf::Color(30,30,30, 235));
        Box::setOutlineColor(sf::Color(255,255,255, 128));
        Box::setOutlineThickness(-5.5);

        m_message.setFillColor(Box::getOutlineColor());
        	if (style == PromptStyle::CUSTOM) return;


        setButtonPlacing(ButtonPlacing::HORIZONTAL);
        setButtonBaseline(ButtonBaseline::END);
        auto okButton = std::make_shared<Button>("OK");
        
        // if user presses ok/yes the response 
        // will be true, if presses cancel/no
        // the response will be false
        okButton->setOnClickCallback(
            [this] {
                m_response.response = Response::TRUE;
            }
        );
        auto declButton = std::make_shared<Button>("CANCEL");
        declButton->setOnClickCallback(
            [this] {
               m_response.response = Response::FALSE;
            }
        );
        auto latButton = std::make_shared<Button>("LATER");
         latButton->setOnClickCallback(
             [this] {
                 m_response.response = Response::DISCARD;
             }
         );
        if (style == PromptStyle::UNARY)
            pushButtons(okButton);
        else if (style == PromptStyle::BINARY)
        {
            okButton->getTextObject().setString("YES");
            declButton->getTextObject().setString("NO");
            pushButtons(declButton, okButton);
        }
        else if (style == PromptStyle::TERNARY)
        {
            latButton->getTextObject().setString("LATER");
            pushButtons(declButton, latButton, okButton);
        }
        else if (style == PromptStyle::INPUT)
        {
            pushButtons(declButton, okButton);
            m_input = std::make_unique<InputBox>(m_message.getString());
            m_input->setPosition(getPosition());
            InputController::bindText(m_input->getTextObject());
            m_input->onFocus();
            m_input->setFitTextSize(true);

            // prompt message will act as a placeholder when a input has focus
            setTextOffset({0.f, -50.f});
            // the response will be whatever was placed inside of the input
            okButton->setOnClickCallback(
            [this] {
				std::string tempString = m_input->getTextObject().getString();
				if (tempString == "" || tempString == m_input->getPlaceholder())
					m_response.response = Response::FALSE;
				else
				{
					m_response.response = Response::TRUE;
					m_response.stringInput = std::string(m_input->getTextObject().getString());
				}
            }
        );
        }
        setSize(sf::Vector2f(400.f, 300.f));
		setFillColor(sf::Color(25, 25, 25, 245));
        placeButtons();
	}
	void Prompt::render(sf::RenderTarget & target)
    {
        Box::render(target);
        if(!m_input || m_input->hasFocus())
            m_message.render(target);

        if(m_input)
            m_input->render(target);
        

        ButtonController::render(target);
    }

    void Prompt::update(float deltaTime)
    {
        ButtonController::update(deltaTime);
        if(hasResponse() && m_callback)
            m_callback(m_response);
        // if size/position changed..
        if(m_shouldUpdateButtonPlacing)
        {
            placeButtons();
            if(m_input)
                m_input->setPosition(getPosition());
        }   
        if(m_input)
            m_input->update(deltaTime);
    }
    bool Prompt::hasResponse() const
    {
        return m_response.response != Response::NONE;
    }
    const Response & Prompt::getResponse() const
    {
        return m_response;
    }
    void Prompt::setMessage(const sf::String& message)
    {
        m_message.setString(message);
    }

	void Prompt::setButtonBaseline(ButtonBaseline baseline)
	{
        ButtonController::setButtonBaseline(baseline);
        m_shouldUpdateButtonPlacing = true;
	}

	void Prompt::placeButtons(float gap)
	{
        ButtonController::placeButtons(
            getGlobalBounds(), gap
        );
        m_shouldUpdateButtonPlacing = false;
	}

	void Prompt::setPosition(const sf::Vector2f & position)
	{
        TextBox::setPosition(position);
        m_shouldUpdateButtonPlacing = true;
	}

	void Prompt::setSize(const sf::Vector2f & size)
	{
        TextBox::setSize(size);
        m_shouldUpdateButtonPlacing = true;
	}

}
