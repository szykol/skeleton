#pragma once

#include "Box.h"
#include "Button.h"
#include "Text.h"
#include "../Managers/ButtonController.h"
#include "InputBox.h"
#include "../Managers/InputController.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <functional>

namespace sen {

	struct Response
	{
		int response = NONE;
		std::string stringInput = "";
		enum {NONE = -1, FALSE = 0, TRUE = 1, DISCARD = 2};
	};

    using OnResponseCallback = std::function<void(const Response&)>;
    enum class PromptStyle {UNARY, BINARY, TERNARY, INPUT, CUSTOM};
    /** 
     * @brief  This class acts like a Prompt (hence its name)
     * It will display a message and provide the user with 
     * buttons needed for interaction. The amount of buttons
     * is variable. There are some "out of the box" prompt styles
     * which you can use when calling a constructor. Then you can
     * set it's size and position (it comes with default ones)
     * and then pass it to StateManager as a shared_ptr.
     * @note   Choose CUSTOM PrompStyle to create your own type
     * of prompt. Remember to specify the action of buttons 
     * you will be using in this prompt. (Closing window for example)
     */
    class Prompt : public TextBox, public ButtonController
    {
    protected:
        Response m_response;
		bool m_pausesState;
        OnResponseCallback m_callback;
        bool m_shouldUpdateButtonPlacing = false;
        std::unique_ptr<InputBox> m_input;
    public:
        /** 
         * @brief  Creates a new prompt. If style isn't set to custom
         * the prompt will be already set for you to use. 
         * @param  style: Style of prompt you want to use
         * @param  &message: Message that will be displayed 
         * inside prompt
         * @param  pausesState: If set pauses updating the 
         * state.
         */
        Prompt(PromptStyle style, const sf::String &message = "STANDARD MESSAGE",
              bool pausesState = true);
        /** 
         * @brief  Renders prompt on the target
         * @param  target: Target to render
         * @retval None
         */
        virtual void render(sf::RenderTarget& target);
        /** 
         * @brief  Updates all prompt logic (it's basically used
         * by the StateManager)
         * @param  window: Window needed for this 
         * prompt to work properly
         * @retval None
         */
        virtual void update(float deltaTime);
        /** 
         * @brief  If prompt has update this function returns true
         * @note You can use this function to check if your pointer
         * to this object is still needed. When prompt has update it
         * is no longer needed by the state manager, neither should
         * be used by you
         */
        bool hasResponse() const;
        /** 
         * @brief  Returns the response which could 
         * be true/false (based on which button will be pressed)
         * or for example the input from user
         * @note   It's needed for building standard prompts,
         * but if you want to build a custom one, you should
         * avoid creating responses. Much easier way would be
         * specifying what each button does (there's no need for 
         * the response then)
         * @retval 
         */
        const Response& getResponse() const;
        /** 
         * @brief  Returns true if pauses state.
         * @note   Needed for StateManager class.
         * @retval 
         */
        bool pausesState() const {return m_pausesState;}
        /** 
         * @brief  Sets message that will be displayed
         * inside of the promptt
         * @param  message: new Message
         * @retval None
         */
        void setMessage(const sf::String& message);
        /** 
         * @brief  If the prompt has a response ready
         * it will call this callback (if exists)
         * @note   Used for specyfying what will
         * happen based on response coming from
         * prompt.
         * @param  callback: callback to be executed
         * when response is ready
         * @retval None
         */
        void setOnResponseCallback(const OnResponseCallback& callback) {m_callback = callback;}
        /** 
		 * @brief  Set baseline of buttons (either START/CENTER/END).
		 * If ButtonPlacing is set to vertical those buttons will be
		 * placed according to y axis else they will be placed
		 * according to x axis.
		 * For example: setting Baseline to START while ButtonPlacing
		 * is set to vertical -> pushes all buttons to the left side
		 * of bounding box, but setting same baseline while ButtinPlacing
		 * is set to horizontal -> pushes all buttons to the top.
		 * @note   It acts similiar to css flexbox
		 * @param  baseline: 
		 * @retval None
		 */
		void setButtonBaseline(ButtonBaseline baseline);
        /** 
         * @brief  Places buttons within it's bounds,
         * based on ButtonPlacing and ButtonBaseline.
         * @note   make sure to set ButtonPlacing and 
         * ButtonBaseline before calling this function
         * @param  gap: Gap between each of the buttons
         * @retval None
         */
		void placeButtons(float gap = 30.f);
        /** 
         * @brief  Sets position of the prompt
         * @note It is done automatically by the 
         * constructor, and set size/position
         * functions -> bounds are known everytime
         * @param  position: new Position
         * @retval None
         */
        void setPosition(const sf::Vector2f& position);
        /** 
         * @brief  Sets size of the prompt
         * @param  size: new size
         * @retval None
         */
        void setSize(const sf::Vector2f& size);
    private:
        /** 
         * @brief  placeButton with window as a parameter
         * doesn't make sense when using prompt class
         * @retval None
         */
        using ButtonController::placeButtons;
    };
}