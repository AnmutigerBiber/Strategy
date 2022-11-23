#ifndef __STRATEGY_CREATE_GAME_STATE_HEADER__
#define __STRATEGY_CREATE_GAME_STATE_HEADER__

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "gui/Container.h"
#include "gui/Label.h"
#include "StateStack.h"

class StateStack;

class CreateGameState : public GameState {
private:
	StateStack* stack;

	Container* mainContentPane;
public:
	~CreateGameState();
	CreateGameState(StateStack* s, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif