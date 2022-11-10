#ifndef __STRATEGY_GAME_STATE_HEADER__
#define __STRATEGY_GAME_STATE_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "StateStack.h"

class StateStack;

class GameState {
protected:
	std::string name;

	Context* context;

	StateStack* stack;
public:
	GameState(StateStack* s, Context* c);
	virtual ~GameState();

	virtual bool handleEvent(sf::Event event) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void render(sf::RenderWindow* window) = 0;

	void setName(std::string n);
	std::string getName();
};

#endif