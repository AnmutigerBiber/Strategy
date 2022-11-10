#ifndef __STRATEGY_STATE_STACK_HEADER__
#define __STRATEGY_STATE_STACK_HEADER__

#include <stack>
#include <vector>

#include "Context.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "SingleplayerGameState.h"
#include "PauseGameState.h"

class StateStack {
private:
	std::stack<GameState*>* states;

	std::vector<std::string> actionQueue;

	Context* context;
public:
	StateStack(Context* c);
	~StateStack();

	GameState* pop();
	bool isEmpty();
	void push(std::string name);
	void clear();

	void requestPop();
	void requestPush(std::string name);
	void requestClear();

	void handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif