#include "SelectGameState.h"

SelectGameState::~SelectGameState() {
}

SelectGameState::SelectGameState(StateStack* s, Context* c) : GameState(c) {
	this->stack = s;

	this->name = this->context->SELECT_GAME_STATE;
}

bool SelectGameState::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			this->stack->requestPush(this->context->PAUSE_GAME_STATE);
		}
	}

	return false;
}

void SelectGameState::update(sf::Time dt) {
	
}

void SelectGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);
}