#include "SelectGameState.h"

SelectGameState::~SelectGameState() {
	delete this->mainContentPane;
}

SelectGameState::SelectGameState(StateStack* s, Context* c) : GameState(c) {
	this->stack = s;

	this->name = this->context->SELECT_GAME_STATE;

	this->mainContentPane = new Container(0.0, 0.0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);

	this->mainContentPane->add(new Button("Continue", this->context->SCREEN_WIDTH / 2, 256, this->context), this->context->SELECT_GAME_STATE_CONTINUE);
	this->mainContentPane->add(new TextInputField("Game", this->context->SCREEN_WIDTH / 2 - 128, 320, this->context), this->context->SELECT_GAME_STATE_NAME_INPUT);
}

bool SelectGameState::handleEvent(sf::Event event) {
	bool val = this->mainContentPane->handleEvent(event);
	
	// if value is true, an element in mainContentPane already handled the event
	if (!val) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				this->stack->requestPush(this->context->PAUSE_GAME_STATE);
				return true;
			}
		}
		else if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

				if (static_cast<Button*>(this->mainContentPane->get(this->context->SELECT_GAME_STATE_CONTINUE))->contains(mousePosition)) {
					this->stack->requestPush(this->context->SINGLEPLAYER_GAME_STATE + " Continue");
					return true;
				}
			}
		}
	}

	return false;
}

void SelectGameState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void SelectGameState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);

	this->mainContentPane->render(window);
}