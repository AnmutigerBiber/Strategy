#ifndef __STRATEGY_APPLICATION_HEADER__
#define __STRATEGY_APPLICATION_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "game/states/StateStack.h"
#include "game/states/MainMenuState.h"

class Application {
private:
	sf::RenderWindow* window;

	sf::Clock clock;

	StateStack* stack;

	Context* context;

	void mainloop();

	void handleEvents();
	void update(sf::Time dt);
	void render();
public:
	Application(Context* c);
	~Application();

	void start();
};

#endif