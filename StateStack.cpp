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
	else if (name.substr(0, 23) == this->context->SINGLEPLAYER_GAME_STATE) { // SelectGameState also specifies which game should be loaded
		this->states->push(new SingleplayerGameState(this, name.substr(24, name.length()), this->context));
	}
	else if (name == this->context->PAUSE_GAME_STATE) {
		this->states->push(new PauseGameState(this, this->context));
	}
	else if (name == this->context->SELECT_GAME_STATE) {
		this->states->push(new SelectGameState(this, this->context));
	}
}

void StateStack::clear() {
	while (!this->isEmpty()) {
		delete this->pop();
	}
}

void StateStack::handleEvent(sf::Event event) {
	if (!this->states->empty()) {
		this->states->top()->handleEvent(event);
	}
}

void StateStack::update(sf::Time dt) {
	for (auto it = this->actionQueue.begin(); it != this->actionQueue.end(); it++) {
		if ((*it) == "pop") {
			this->states->pop();
		}
		else if ((*it) == "clear") {
			this->clear();
		}
		else {
			this->push(it->substr(5, it->length()));
		}
	}

	actionQueue.clear();

	if (!this->states->empty()) {
		this->states->top()->update(dt);
	}
}

void StateStack::render(sf::RenderWindow* window) {
	if (!this->states->empty()) {
		this->states->top()->render(window);
	}
	else {
		window->close();
	}
}

void StateStack::requestPop() {
	this->actionQueue.push_back("pop");
}

void StateStack::requestPush(std::string name) {
	this->actionQueue.push_back("push " + name);
}

void StateStack::requestClear() {
	this->actionQueue.push_back("clear");
}