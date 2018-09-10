#include "TestState.h"
#include "../Managers/StateManager.h"
#include "../GUI/Prompt.h"
#include "../GUI/Popup.h"
#include "../Application.h"

namespace sen {
	unsigned int TestState::s_pushedStates = 0;

	TestState::TestState(sf::RenderWindow & window)
		: m_info("Amount of states: ")
	{
		std::shared_ptr<Button> popState(new Button("Pop State"));
		std::shared_ptr<Button> pushState(new Button("Push State"));
		std::shared_ptr<Button> spawnPopup(new Button("Spawn Prompt"));
		std::shared_ptr<Button> quit(new Button("Quit"));

		//std::shared_ptr<Button> box(new InputBox());

		quit->setOnClickCalback(
			[this, &window] {
				m_prompt = std::make_shared<Prompt>(PromptStyle::BINARY, "Are you sure?");
				m_prompt->setPosition(sf::Vector2f(Application::getInitialWindowSize()) / 2.f);
				StateManager::pushPrompt(m_prompt);
				m_prompt->setOnResponseCallback(
					[&](const Response& r) {
						if (r.response == Response::TRUE)
						{
							window.close();
						}
					}
				);
			}
		);


		pushState->setOnClickCalback([&window, this] {
				m_prompt = std::make_shared<Prompt>(PromptStyle::BINARY, "Are you sure?");
				m_prompt->setPosition(sf::Vector2f(Application::getInitialWindowSize()) / 2.f);
				StateManager::pushPrompt(m_prompt);

				m_prompt->setOnResponseCallback(
					[&](const Response& r) {
						if(r.response == Response::TRUE)
						{
							StateManager::pushState<TestState>(window);
							auto popup = std::make_unique<Popup>("Pushed State");
							StateManager::pushPopup(std::move(popup));
						}
					}
				);
		});
		popState->setOnClickCalback([&window, this] {
				m_prompt = std::make_shared<Prompt>(PromptStyle::BINARY, "Are you sure?");
				m_prompt->setPosition(sf::Vector2f(Application::getInitialWindowSize()) / 2.f);
				StateManager::pushPrompt(m_prompt);
				m_prompt->setOnResponseCallback(
					[&](const Response& r) {
						if(r.response == Response::TRUE)
						{
							StateManager::popState();
							auto popup = std::make_unique<Popup>("Popped State");
							StateManager::pushPopup(std::move(popup));
						}
					}
				);
				
		});

		spawnPopup->setOnClickCalback([&window, this] {
				m_prompt = std::make_shared<Prompt>(PromptStyle::INPUT, "Type something..");
				m_prompt->setPosition(sf::Vector2f(Application::getInitialWindowSize()) / 2.f);
				StateManager::pushPrompt(m_prompt);
		});

		// Get text object of textbox and set its string
		// and character size
		auto& tObject = m_info.getTextObject();
		tObject.setCharacterSize(26U);
		sf::String ammount = tObject.getString();
		ammount += std::to_string(s_pushedStates);
		tObject.setString(ammount);
		m_info.setPosition(sf::Vector2f(Application::getInitialWindowSize().x / 2.f, 50.f));

		s_pushedStates++;

		// setup button controller
		//m_buttonController.setButtonPlacing(ButtonPlacing::HORIZONTAL);
		m_buttonController.pushButtons(popState, pushState, spawnPopup, quit);
		m_buttonController.placeButtons();
		m_buttonController.setButtonFixedSize(
			sf::Vector2f(185.f, 50.f)
		);
	}
	void TestState::update(float deltaTime, sf::RenderWindow & window)
	{
		m_buttonController.update(deltaTime);
		if (m_prompt && m_prompt->hasResponse())
		{
			m_prompt = nullptr;
		}
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