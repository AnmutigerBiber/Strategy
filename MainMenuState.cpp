#include "MainMenuState.h"

MainMenuState::~MainMenuState() {
	delete this->mainContentPane;
}

MainMenuState::MainMenuState(StateStack* s, Context* c) : GameState(c) {
	this->stack = s;

	this->name = this->context->MAIN_MENU_STATE;

	this->mainContentPane = new Container(0.0, 0.0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);

	this->mainContentPane->add(new Button("Play", this->context->SCREEN_WIDTH / 2, 256, this->context), this->context->MAIN_MENU_STATE_START_GAME_BUTTON);
	this->mainContentPane->add(new Button("Quit", this->context->SCREEN_WIDTH / 2, 320, this->context), this->context->MAIN_MENU_STATE_QUIT_BUTTON);
}

bool MainMenuState::handleEvent(sf::Event event) {
	bool val = this->mainContentPane->handleEvent(event);
	
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			this->stack->requestClear();
		}
	}
	else if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

			if (static_cast<Button*>(this->mainContentPane->get(this->context->MAIN_MENU_STATE_START_GAME_BUTTON))->contains(mousePosition)) {
				this->stack->requestPush(this->context->SELECT_GAME_STATE);
			}
			else if (static_cast<Button*>(this->mainContentPane->get(this->context->MAIN_MENU_STATE_QUIT_BUTTON))->contains(mousePosition)) {
				this->stack->requestClear();
			}
		}
	}

	return false || val;
}

void MainMenuState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void MainMenuState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	this->mainContentPane->render(window);
}