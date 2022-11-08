#ifndef __STRATEGY_LABEL_HEADER__
#define __STRATEGY_LABEL_HEADER__

#include <SFML/Graphics.hpp>

#include "Component.h"

class Label : public Component { // not ready for usage yet
private:
	sf::Text text;
public:
	Label(std::string name, std::string t);
	~Label();

	void setText(std::string t);
	std::string getText();

	void render(sf::RenderWindow* window);
};

#endif