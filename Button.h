#ifndef __STRATEGY_BUTTON_HEADER__
#define __STRATEGY_BUTTON_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "Component.h"

class Button : public Component {
private:
	sf::Text text;
	sf::Font f;

	const int TARGET_X = 220;
	const int TARGET_Y = 50;

	bool isMouseOnButton;
public:
	Button(std::string t, float x, float y, Context* c);
	~Button();

	void setMouseIsOnButton(bool b);

	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif