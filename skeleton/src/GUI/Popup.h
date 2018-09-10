#pragma once

#include "TextBox.h"
#include <SFML/Graphics.hpp>

namespace sen {
    enum class PopupBaseline {TOP, BOTTOM};
    /** 
     * @brief  This is just a simple class that lets you
     * create simple notifications that will be displayed
     * either at the top or bottom of the screen for 
     * a certain duration
     * @note   Use this class with StateManager as it supports
     * all logic needed for this to work. You simply create 
     * a pointer to this object and pass it to StateManager
     * it will take care of freeing memory after it's used
     */
    class Popup : public TextBox
    {
    private:
        float m_duration;
		float m_time = 0.f;
        bool m_shouldVanish;
    public:
        /** 
         * @brief  This constructor lets you create the popup
         * simply with only one call. Set's objects position
         * inside the window, string that will be displayed
         * in the notification body, it will be placed
         * at the bottom or top of the screen for a certain duration
         * @param  window: Window needed to size, place the notifiaction
         * @param  string: Message that will be displayed
         * @param  baseline: Top or Bottom
         * @param  duration: Duration in which the popup will be displayed
         */
        Popup(const sf::String& string,
              PopupBaseline baseline = PopupBaseline::BOTTOM, float duration = 5.f);
        /** 
         * @brief  If the time passed from creating notification to
         * the moment you call this function is greaten than
         * duration it will return true
         * @note   
         * @retval 
         */
        bool shouldVanish(float deltaTime);
    private:
        /** 
         * Those functions are private because popup shouldn't 
         * be able to move its position
         */
        using TextBox::setPosition;
        using TextBox::move;
        using sf::Shape::update;
    };
}