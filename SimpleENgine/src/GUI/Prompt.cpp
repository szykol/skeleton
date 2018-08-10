 #include "Prompt.h"

namespace sen {
	Prompt::Prompt(PromptStyle style, const sf::String& message, bool pausesState, bool blursBG)
        : m_pausesState(pausesState),
		  m_blursBG(blursBG), TextBox(message)
    {
        Box::setFillColor(sf::Color(30,30,30, 235));
        Box::setOutlineColor(sf::Color(255,255,255, 128));
        Box::setOutlineThickness(-5.5);

        m_message.setFillColor(Box::getOutlineColor());
        	if (style == PromptStyle::CUSTOM) return;


        setButtonPlacing(ButtonPlacing::HORIZONTAL);
        setButtonBaseline(ButtonBaseline::END);
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

            setTextOffset({0.f, -50.f});
            okButton->setOnClickCalback(
            [this] {
                m_response["Response"] = std::string(m_input->getTextObject().getString());
            }
        );
        }
        setSize(sf::Vector2f(400.f, 300.f));
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

    void Prompt::update(sf::RenderWindow & window)
    {
        ButtonController::update(window);
        if(hasResponse() && m_callback)
            m_callback(m_response);
        if(m_shouldUpdateButtonPlacing)
        {
            placeButtons();
            if(m_input)
                m_input->setPosition(getPosition());
        }   
        if(m_input)
            m_input->update(window);
    }
    bool Prompt::hasResponse() const
    {
        return m_response.size();
    }
    const json & Prompt::getResponse() const
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
