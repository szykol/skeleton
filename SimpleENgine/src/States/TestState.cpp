#include "TestState.h"
#include "StateManager.h"
#include "../UI/Popup.h"

namespace sen {
	unsigned int TestState::s_pushedStates = 0;

	TestState::TestState(sf::RenderWindow & window)
		: m_info("Amount of states: ")
	{
		std::shared_ptr<Button> popState(new Button("Pop State"));
		std::shared_ptr<Button> pushState(new Button("Push State"));
		std::shared_ptr<Button> spawnPopup(new Button("Spawn Popup"));
		//std::shared_ptr<Button> box(new InputBox());

		pushState->setOnClickCalback([&window, this] {
			// StateManager::pushState<TestState>(window);
			if(!m_popup)
			{
				m_popup = createPopup(PopupStyle::BINARY);
				m_popup->getTextObject().setString("Are you sure");
				m_popup->setPosition(sf::Vector2f(window.getSize()) / 2.f);
				m_popup->placeButtons(m_popup->getGlobalBounds());
				StateManager::pushPopup(m_popup);
			}	
		});
		popState->setOnClickCalback([&window, this] {
			// StateManager::popState();
			if(!m_popup)
			{
				m_popup = createPopup(PopupStyle::BINARY);
				m_popup->getTextObject().setString("Are you sure");
				m_popup->setPosition(sf::Vector2f(window.getSize()) / 2.f);
				m_popup->placeButtons(m_popup->getGlobalBounds());
				StateManager::pushPopup(m_popup);
			}	
		});

		popState->setOnClickCalback([&window, this] {
			// StateManager::popState();
			if(!m_popup)
			{
				m_popup = createPopup(PopupStyle::UNARY);
				m_popup->getTextObject().setString("SPAWNED POPUP");
				m_popup->setPosition(sf::Vector2f(window.getSize()) / 2.f);
				m_popup->placeButtons(m_popup->getGlobalBounds());


				StateManager::pushPopup(m_popup);
			}	
		});

		// Get text object of textbox and set its string
		// and character size
		auto& tObject = m_info.getTextObject();
		tObject.setCharacterSize(26U);
		sf::String ammount = tObject.getString();
		ammount += std::to_string(s_pushedStates);
		tObject.setString(ammount);
		m_info.setPosition(sf::Vector2f(window.getSize().x / 2.f, 50.f));

		s_pushedStates++;

		// setup button controller
		//m_buttonController.setButtonPlacing(ButtonPlacing::HORIZONTAL);
		m_buttonController.pushButtons(popState, pushState, spawnPopup);
		m_buttonController.placeButtons(window);
		m_buttonController.setButtonFixedSize(
			sf::Vector2f(185.f, 50.f)
		);
		
	}
	void TestState::handleEvents(sf::Event &evnt)
	{
		
	}
	void TestState::update(sf::RenderWindow & window)
	{
		m_buttonController.update(window);
		if(m_popup && m_popup->hasResponse())
		{
			std::cout<<"Got response!\n\tThe response is :'"
			 << m_popup->getResponse()["Response"]<<std::endl;
			
			m_popup = nullptr;
		}
	}
	void TestState::input(sf::RenderWindow & window)
	{
	}
	void TestState::render(sf::RenderTarget & target)
	{
		m_info.render(target);
		m_buttonController.render(target);
	}
	TestState::~TestState()
	{
		// buttons are no longer heap allocated
		//m_buttonController.freeMemory();
		s_pushedStates--;
	}
}