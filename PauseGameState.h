#ifndef __PAUSE_GAME_STATE_HEADER__
#define __PAUSE_GAME_STATE_HEADER__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "GameState.h"
#include "StateStack.h"

class StateStack;

class PauseGameState : public GameState {
private:
	Context* context;

	StateStack* stack;

	sf::RectangleShape background;
public:
	~PauseGameState();
	PauseGameState(StateStack* s, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif