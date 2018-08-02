#include "TestState.h"
#include "StateManager.h"

namespace sen {
	unsigned int TestState::s_pushedStates = 0;

	TestState::TestState(sf::RenderWindow & window)
		: m_info("Ammount of states: ")
	{
		std::shared_ptr<Button> popState(new Button("Pop State"));
		std::shared_ptr<Button> pushState(new Button("Push State"));
		//std::shared_ptr<Button> box(new InputBox());

		pushState->setOnClickCalback([&window] {
			StateManager::pushState<TestState>(window);
		});
		popState->setOnClickCalback([] {
			StateManager::popState();
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
		m_buttonController.pushButtons(popState, pushState);// , box);
		m_buttonController.placeButtons(window);
		m_buttonController.setButtonFixedSize(
			sf::Vector2f(170.f, 50.f)
		);


	}
	void TestState::handleEvents(sf::Event &evnt)
	{
		
	}
	void TestState::update(sf::RenderWindow & window)
	{
		m_buttonController.update(window);
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