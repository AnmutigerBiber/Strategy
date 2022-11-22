#include "CreateGameState.h"

CreateGameState::~CreateGameState() {
	delete this->mainContentPane;
}

CreateGameState::CreateGameState(StateStack* s, Context* c) : GameState(c) {
	this->context = c;

	this->stack = s;

	this->name = this->context->CREATE_GAME_STATE;

	this->mainContentPane = new Container(0, 0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);

	this->mainContentPane->add(new Label(this->context->SCREEN_WIDTH / 4.0, 340, "Name", this->context), this->context->CREATE_GAME_STATE_GAME_NAME_LABEL);
}

bool CreateGameState::handleEvent(sf::Event event) {
	bool val = this->mainContentPane->handleEvent(event);

	if (!val) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				this->stack->requestPush(this->context->PAUSE_GAME_STATE);
				return true;
			}
		}
	}

	return val;
}

void CreateGameState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void CreateGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	this->mainContentPane->render(window);
}