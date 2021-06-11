#include "SimpleMenu.h"

#include <Skeleton/Managers/StateManager.h>
#include <Skeleton/GUI/Prompt.h>
#include <Skeleton/GUI/Popup.h>
#include <Skeleton/Application.h>
#include <Skeleton/Util/Helper.h>

unsigned int MenuState::s_pushedStates = 0;

MenuState::MenuState(sf::RenderWindow &window) : m_info("Amount of states: ") {
    std::shared_ptr<sen::Button> popState = std::make_shared<sen::Button>("Pop State");
    std::shared_ptr<sen::Button> pushState = std::make_shared<sen::Button>("Push State");
    std::shared_ptr<sen::Button> spawnPopup = std::make_shared<sen::Button>("Spawn Prompt");
    std::shared_ptr<sen::Button> quit = std::make_shared<sen::Button>("Quit");

    quit->setOnClickCallback([this] {
        m_prompt = sen::spawnPrompt(sen::PromptStyle::BINARY, "Are you sure");
        m_prompt->setOnResponseCallback([&](const sen::Response &r) {
            if (r.response == sen::Response::TRUE) {
                Application::exit();
            }
        });
    });

    pushState->setOnClickCallback([&window, this] {
        m_prompt = sen::spawnPrompt(sen::PromptStyle::BINARY, "Are you sure");
        m_prompt->setOnResponseCallback([&](const sen::Response &r) {
            if (r.response == sen::Response::TRUE) {
                sen::StateManager::pushState<MenuState>(window);
                sen::spawnPopup("Pushed State");
            }
        });
    });
    popState->setOnClickCallback([this] {
        m_prompt = sen::spawnPrompt(sen::PromptStyle::BINARY, "Are you sure");
        m_prompt->setOnResponseCallback([&](const sen::Response &r) {
            if (r.response == sen::Response::TRUE) {
                sen::StateManager::popState();
                sen::spawnPopup("Pushed State");
            }
        });
    });

    spawnPopup->setOnClickCallback([this] {
        m_prompt = sen::spawnPrompt(sen::PromptStyle::INPUT, "Type something..");
        m_prompt->setOnResponseCallback([](auto &response) {
            auto popupInfo = std::string{"You closed the prompt"};
            if (response.response == sen::Response::TRUE) {
                popupInfo = "You typed: " + response.stringInput;
            }
            sen::spawnPopup(popupInfo);
        });
    });

    // Get text object of textbox and set its string
    // and character size
    auto &tObject = m_info.getTextObject();
    tObject.setCharacterSize(26U);
    sf::String ammount = tObject.getString();
    ammount += std::to_string(s_pushedStates);
    tObject.setString(ammount);
    m_info.setPosition(sf::Vector2f(Application::getInitialWindowSize().x / 2.f, 50.f));

    s_pushedStates++;

    m_buttonController.pushButtons(popState, pushState, spawnPopup, quit);
    m_buttonController.placeButtons(100.f);
    m_buttonController.setButtonFixedSize(sf::Vector2f(185.f, 50.f));
}
void MenuState::update(float deltaTime, sf::RenderWindow &) {
    m_buttonController.update(deltaTime);
    if (m_prompt && m_prompt->hasResponse()) {
        m_prompt = nullptr;
    }
}
void MenuState::render(sf::RenderTarget &target) {
    m_info.render(target);
    m_buttonController.render(target);
}
MenuState::~MenuState() {
    // buttons are no longer heap allocated
    // m_buttonController.freeMemory();
    s_pushedStates--;
}
