#include "StateStack.h"

StateStack::StateStack(Context* c) {
	this->states = new std::stack<GameState*>();

	this->context = c;
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
	if (name == this->context->MAIN_MENU_STATE) {
		this->states->push(new MainMenuState(this->context));
	}
}

void StateStack::clear() {
	while (!this->isEmpty()) {
		delete this->pop();
	}
}