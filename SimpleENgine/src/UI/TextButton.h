//#pragma once
//
//#include "Textbox.h"
//#include "InterfaceButton.h"
//
//namespace sen {
//	/**
//		Extends functionality of TextBox and InterfaceButton
//		overrides all methods provided in InterfaceButton
//	*/
//	class TextButton : public InterfaceButton
//	{
//	public:
//		/**
//			Calls TextBox constructor which bassicly sets the Box around the text
//
//			@param string String that will be displayed inside of button
//		*/
//		TextButton(const std::string &string);
//		/**
//			Overriden from InterfaceButton.
//			Changes the button on mouse hover
//		*/
//		virtual void onHover()									override;
//		/**
//			Overriden from InterfaceButton.
//			Changes the button on mouse leaving the button
//		*/
//		virtual void onUnhover()								override;
//		/**
//			Overriden from InterfaceButton.
//			Changes the button on mouse click
//		*/
//		virtual void onClick()									override;
//		/**
//			Overriden from InterfaceButton.
//			Checks if mouse hovers over the button
//
//			@param window Window is needed to tell the position of Mouse
//		*/
//	};
//}