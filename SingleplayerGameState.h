#ifndef __SINGLEPLAYER_GAME_STATE__
#define __SINGLEPLAYER_GAME_STATE__

#include <SFML/Graphics.hpp>

#include "Context.h"
#include "GameState.h"

class SingleplayerGameState : public GameState {
private:
	Context* context;
public:
	~SingleplayerGameState();
	SingleplayerGameState(Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif