#ifndef __SELECT_GAME_STATE_HEADER__
#define __SELECT_GAME_STATE_HEADER__

#include "GameState.h"
#include "gui/Container.h"
#include "gui/Button.h"
#include "gui/TextInputField.h"
#include "StateStack.h"

//class StateStack;

class SelectGameState : public GameState {
private:
	StateStack* stack;

	Container* mainContentPane;
public:
	~SelectGameState();
	SelectGameState(StateStack* s, Context* c);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif