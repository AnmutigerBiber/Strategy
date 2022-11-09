#ifndef __STRATEGY_MAIN_MENU_STATE_HEADER__
#define __STRATEGY_MAIN_MENU_STATE_HEADER__

#include "Context.h"
#include "GameState.h"
#include "Container.h"
#include "Button.h"
#include "StateStack.h";

class StateStack;

class MainMenuState : public GameState {
private:
	Container *mainContentPane;

	Context* context;

	StateStack* stack;
public:
	MainMenuState(StateStack* s, Context* c);
	~MainMenuState();

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif