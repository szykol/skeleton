#pragma once

#include "../Managers/StateManager.h"
#include "../GUI/Popup.h"
#include "../GUI/Prompt.h"

namespace sen {
    template <typename... Args> static void spawnPopup(Args &&...args) {
        auto prompt = std::make_unique<sen::Popup>(std::forward<Args>(args)...);
        sen::StateManager::pushPopup(std::move(prompt));
    }

    template <typename... Args> static std::shared_ptr<Prompt> spawnPrompt(Args &&...args) {
        auto prompt = std::make_shared<sen::Prompt>(std::forward<Args>(args)...);
        sen::StateManager::pushPrompt(prompt);

        return prompt;
    }
} // namespace sen
