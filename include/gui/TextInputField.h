#ifndef __STRATEGY_TEXT_INPUT_FIELD_HEADER__
#define __STRATEGY_TEXT_INPUT_FIELD_HEADER__

#include <SFML/Graphics.hpp>

#include <map>

#include "Component.h"

class TextInputField : public Component {
private:
	sf::Text text;

	bool active = false;

	std::map<sf::Keyboard::Key, std::string> keycodes;
public:
	~TextInputField();
	TextInputField(std::string s, float x, float y, Context* c);

	void setActive(bool a);
	void clear();

	std::string getText();

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif