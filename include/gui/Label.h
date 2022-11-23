#ifndef __STRATEGY_LABEL_HEADER__
#define __STRATEGY_LABEL_HEADER__

#include <SFML/Graphics.hpp>

#include "Component.h"

class Label : public Component { // not ready for usage yet
private:
	sf::Text text;
public:
	Label(float x, float y, std::string t, Context* c);
	~Label();

	void setText(std::string t);
	std::string getText();

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif