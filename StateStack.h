#ifndef __STRATEGY_STATE_STACK_HEADER__
#define __STRATEGY_STATE_STACK_HEADER__

#include <stack>

#include "Context.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "SingleplayerGameState.h"

class StateStack {
private:
	std::stack<GameState*>* states;

	Context* context;
public:
	StateStack(Context* c);
	~StateStack();

	GameState* pop();
	bool isEmpty();
	void push(std::string name);
	void clear();

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif