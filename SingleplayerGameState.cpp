#include "SingleplayerGameState.h"

SingleplayerGameState::~SingleplayerGameState() {
}

SingleplayerGameState::SingleplayerGameState(StateStack* s, Context* c) {
	this->context = c;

	this->stack = s;
}

bool SingleplayerGameState::handleEvent(sf::Event event) {
	// pressing escape should show pause screen
	// half-transparent

	return false;
}

void SingleplayerGameState::update(sf::Time dt) {

}

void SingleplayerGameState::render(sf::RenderWindow* window) {
	sf::CircleShape shape;

	shape.setPosition(100, 100);
	shape.setFillColor(sf::Color::Red);

	window->draw(shape); // to show that pushing state has worked
}