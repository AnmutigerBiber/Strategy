#include "PauseGameState.h"

PauseGameState::~PauseGameState() {
	delete this->mainContentPane;
}

PauseGameState::PauseGameState(StateStack* s, Context* c) : GameState(s, c) {
	this->name = this->context->PAUSE_GAME_STATE;

	this->mainContentPane = new Container(0, 0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);
	this->mainContentPane->setColor(sf::Color(127, 127, 127, 63));
	
	this->mainContentPane->add(new Button("Quit to Menu", this->context->SCREEN_WIDTH / 2, this->context->SCREEN_HEIGHT / 2 - 100, this->context), this->context->PAUSE_GAME_STATE_QUIT_TO_MENU);
	this->mainContentPane->add(new Button("Back to Game", this->context->SCREEN_WIDTH / 2, this->context->SCREEN_HEIGHT / 2 - 36, this->context), this->context->PAUSE_GAME_STATE_BACK_TO_GAME);
	this->mainContentPane->add(new Button("Save and Quit", this->context->SCREEN_WIDTH / 2, this->context->SCREEN_HEIGHT / 2 + 94, this->context), this->context->PAUSE_GAME_STATE_SAVE_AND_QUIT);

	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT));
	background.setFillColor(sf::Color(127, 127, 127, 63));
}

bool PauseGameState::handleEvent(sf::Event event) {
	this->mainContentPane->handleEvent(event);

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			this->stack->requestPop();
		}
	}
	else if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

			if (static_cast<Button*>(this->mainContentPane->get(this->context->PAUSE_GAME_STATE_QUIT_TO_MENU))->contains(mousePosition)) {
				this->stack->requestClear();
				this->stack->requestPush(this->context->MAIN_MENU_STATE);
			}
			else if (static_cast<Button*>(this->mainContentPane->get(this->context->PAUSE_GAME_STATE_BACK_TO_GAME))->contains(mousePosition)) {
				this->stack->requestPop();
			}
			else if (static_cast<Button*>(this->mainContentPane->get(this->context->PAUSE_GAME_STATE_SAVE_AND_QUIT))->contains(mousePosition)) {
				this->stack->requestClear();
			}
		}
	}
	
	return true;
}

void PauseGameState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void PauseGameState::render(sf::RenderWindow* window) {
	window->draw(background);

	this->mainContentPane->render(window);
}