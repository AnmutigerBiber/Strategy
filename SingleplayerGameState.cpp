#include "SingleplayerGameState.h"

SingleplayerGameState::~SingleplayerGameState() {
}

SingleplayerGameState::SingleplayerGameState(StateStack* s, Context* c) {
	this->context = c;

	this->stack = s;
}

bool SingleplayerGameState::handleEvent(sf::Event event) {
	// just for testing purposes
	// pressing escape should show half-transparent pause screen
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			return true;
		}
	}

	return false;
}

void SingleplayerGameState::update(sf::Time dt) {

}

void SingleplayerGameState::render(sf::RenderWindow* window) {
	sf::CircleShape shape;

	shape.setPosition(100, 100);
	shape.setRadius(20);
	shape.setFillColor(sf::Color::Red);

	window->draw(shape); // to show that pushing state has worked
}