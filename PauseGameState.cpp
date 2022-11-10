#include "PauseGameState.h"

PauseGameState::~PauseGameState() {
}

PauseGameState::PauseGameState(StateStack* s, Context* c) {
	this->context = c;

	this->stack = s;

	this->name = this->context->PAUSE_GAME_STATE;

	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT));
	background.setFillColor(sf::Color(127, 127, 127, 127));
}

bool PauseGameState::handleEvent(sf::Event event) {
	return true;
}

void PauseGameState::update(sf::Time dt) {
}

void PauseGameState::render(sf::RenderWindow* window) {
	window->draw(background);
}