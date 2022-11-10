#include "SingleplayerGameState.h"

SingleplayerGameState::~SingleplayerGameState() {
}

SingleplayerGameState::SingleplayerGameState(StateStack* s, Context* c) {
	this->context = c;

	this->name = this->context->SINGLEPLAYER_GAME_STATE;

	this->stack = s;
}

bool SingleplayerGameState::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			this->stack->requestPush(this->context->PAUSE_GAME_STATE);
		}
	}

	return false;
}

void SingleplayerGameState::update(sf::Time dt) {

}

void SingleplayerGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	sf::CircleShape shape;

	shape.setPosition(100, 100);
	shape.setRadius(20);
	shape.setFillColor(sf::Color::Red);

	window->draw(shape); // to show that pushing state has worked
}