#ifndef __STRATEGY_APPLICATION_HEADER__
#define __STRATEGY_APPLICATION_HEADER__

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "MainMenuState.h"

class Application {
private:
	sf::RenderWindow* window;

	sf::Clock clock;

	GameState* currentState;

	void mainloop();

	void handleEvents();
	void update(sf::Time dt);
	void render();
public:
	Application();
	~Application();

	void start();
};

#endif