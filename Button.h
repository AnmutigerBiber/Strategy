#ifndef __STRATEGY_BUTTON_HEADER__
#define __STRATEGY_BUTTON_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "Component.h"

class Button : public Component {
private:
	sf::Text text;

	bool isMouseOnButton;
	bool isButtonPressed;

	void (*callback)();
public:
	Button(std::string t, float x, float y, Context* c);
	~Button();

	void setMouseIsOnButton(bool b);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);

	bool isPressed();

	bool contains(sf::Vector2f pos);

	void onClick(void (*fnc)());
	void click();
};

#endif