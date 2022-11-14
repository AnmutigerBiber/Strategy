#include "SelectGameState.h"

#include <iostream>

SelectGameState::~SelectGameState() {
}

SelectGameState::SelectGameState(StateStack* s, Context* c) : GameState(c) {
	std::cout << "Hallo Welt" << std::endl;
	
	this->stack = s;

	this->name = this->context->SELECT_GAME_STATE;

	std::cout << "Select Game State initialisiert" << std::endl;
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
	this->stack->update(dt);
}

void SelectGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	this->stack->render(window);
}