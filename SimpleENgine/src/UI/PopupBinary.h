#pragma once

#include "Popup.h"

namespace sen {
    class PopupBinary : public Popup
    {
    public:
        PopupBinary(const sf::RenderWindow& window,
        const sf::String &message = "STANDARD POPUP",
        bool pausesState = true, bool blursBG = false);
        // virtual void render(sf::RenderTarget& target) override;
        //virtual void update(sf::RenderWindow& window) override;
        ~PopupBinary() = default;
    };
}