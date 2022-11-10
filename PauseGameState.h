#ifndef __PAUSE_GAME_STATE_HEADER__
#define __PAUSE_GAME_STATE_HEADER__

#include <SFML/Graphics.hpp>

#include "GameState.h"

class PauseGameState : public GameState {
private:
	Container* mainContentPane;

	sf::RectangleShape background;
public:
	~PauseGameState();
	PauseGameState(StateStack* s, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif