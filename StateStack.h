#ifndef __STRATEGY_STATE_STACK_HEADER__
#define __STRATEGY_STATE_STACK_HEADER__

#include <stack>

#include "GameState.h"
#include "MainMenuState.h"

class StateStack {
private:
	std::stack<GameState*>* states;

public:
	StateStack();
	~StateStack();

	GameState* pop();
	GameState* peek();
	bool isEmpty();
	void push(std::string name);
	void clear();
};

#endif