#ifndef __SELECT_GAME_STATE_HEADER__
#define __SELECT_GAME_STATE_HEADER__

#include "GameState.h"
#include "StateStack.h"

class StateStack;

class SelectGameState : public GameState {
private:
	StateStack* stack;
public:
	~SelectGameState();
	SelectGameState(StateStack* s, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif