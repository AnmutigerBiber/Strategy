#include "MainMenuState.h"

MainMenuState::~MainMenuState() {
	delete mainContentPane;
}

MainMenuState::MainMenuState(StateStack* s, Context* c) {
	this->context = c;
	this->stack = s;

	this->name = this->context->MAIN_MENU_STATE;

	this->mainContentPane = new Container(0.0, 0.0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);

	this->mainContentPane->add(new Button("Play", this->context->SCREEN_WIDTH / 2, 256, this->context), this->context->MAIN_MENU_STATE_START_GAME_BUTTON);
}

bool MainMenuState::handleEvent(sf::Event event) {
	bool val = this->mainContentPane->handleEvent(event);
	
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			return true;
		}
	}
	else if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

		if (static_cast<Button*>(this->mainContentPane->get(this->context->MAIN_MENU_STATE_START_GAME_BUTTON))->contains(mousePosition)) {
			this->stack->requestPush(this->context->SINGLEPLAYER_GAME_STATE);
		}
	}

	return false || val;
}

void MainMenuState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void MainMenuState::render(sf::RenderWindow* window) {
	this->mainContentPane->render(window);
}