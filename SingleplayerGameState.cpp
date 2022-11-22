#include "SingleplayerGameState.h"

SingleplayerGameState::~SingleplayerGameState() {
	delete this->game;
}

SingleplayerGameState::SingleplayerGameState(StateStack* s, std::string f, Context* c) : GameState(c) {
	this->stack = s;

	this->name = this->context->SINGLEPLAYER_GAME_STATE;

	this->game = new Game(f, c);
}

bool SingleplayerGameState::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			this->stack->requestPush(this->context->PAUSE_GAME_STATE);
			return true;
		}
	}

	bool val = game->handleEvent(event);

	return val;
}

void SingleplayerGameState::update(sf::Time dt) {
	this->game->update(dt);
}

void SingleplayerGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	this->game->render(window);
}