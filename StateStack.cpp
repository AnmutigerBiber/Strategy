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

bool StateStack::isEmpty() {
	return this->states->empty();
}

void StateStack::push(std::string name) {
	if (name == this->context->MAIN_MENU_STATE) {
		this->states->push(new MainMenuState(this, this->context));
	}
	else if (name == this->context->SINGLEPLAYER_GAME_STATE) {
		this->states->push(new SingleplayerGameState(this, this->context));
	}
}

void StateStack::clear() {
	while (!this->isEmpty()) {
		delete this->pop();
	}
}

bool StateStack::handleEvent(sf::Event event) {
	return this->states->top()->handleEvent(event);
}

void StateStack::update(sf::Time dt) {
	this->states->top()->update(dt);
}

void StateStack::render(sf::RenderWindow* window) {
	this->states->top()->render(window);
}