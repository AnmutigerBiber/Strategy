#ifndef __SINGLEPLAYER_GAME_STATE__
#define __SINGLEPLAYER_GAME_STATE__

#include <SFML/Graphics.hpp>

#include "GameState.h"class StateStack;

class SingleplayerGameState : public GameState {
private:

public:
	~SingleplayerGameState();
	SingleplayerGameState(StateStack* stack, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif