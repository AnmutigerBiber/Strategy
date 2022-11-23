#ifndef __STRATEGY_GAME_HEADER__
#define __STRATEGY_GAME_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"

class Game {
private:
	Context* context;

	std::string filename;

	void load();
	void save();
public:
	~Game();
	Game(std::string f, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif