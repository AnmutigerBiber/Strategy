#include "StateStack.h"

StateStack::StateStack() {
	this->states = new std::stack<GameState*>();
}

StateStack::~StateStack() {
	this->clear();

	delete this->states;
}

GameState* StateStack::pop() {
	GameState* gs = this->states->top();
	this->states->pop();
	return gs;
}

GameState* StateStack::peek() {
	return this->states->top();
}

bool StateStack::isEmpty() {
	return this->states->empty();
}

void StateStack::push(std::string name) {
	if (name == "Main Menu State") {
		this->states->push(new MainMenuState());
	}
}

void StateStack::clear() {
	while (!this->isEmpty()) {
		delete this->pop();
	}
}