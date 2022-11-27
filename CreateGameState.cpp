#include "game/states/CreateGameState.h"

CreateGameState::~CreateGameState() {
	delete this->mainContentPane;
}

CreateGameState::CreateGameState(StateStack* s, Context* c) : GameState(c) {
	this->context = c;

	this->stack = s;

	this->name = this->context->CREATE_GAME_STATE;

	this->mainContentPane = new Container(0.0, 0.0, this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT, this->context);

	this->mainContentPane->add(new Label(this->context->SCREEN_WIDTH / 8.0, 340.0, "Name", this->context), this->context->CREATE_GAME_STATE_GAME_NAME_LABEL);
	this->mainContentPane->add(new TextInputField("", this->context->SCREEN_WIDTH / 8.0 + 256, 340.0, this->context), this->context->CREATE_GAME_STATE_GAME_NAME_INPUT);
	this->mainContentPane->add(new Button("Create", this->context->SCREEN_WIDTH / 8.0 * 7.0, this->context->SCREEN_HEIGHT / 8.0 * 7.0, this->context), this->context->CREATE_GAME_STATE_CREATE_BUTTON);
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
		else if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2f mousePosition(sf::Mouse::getPosition());

			if (static_cast<Button*>(this->mainContentPane->get(this->context->CREATE_GAME_STATE_CREATE_BUTTON))->contains(mousePosition)) {
				this->createNewGame();
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

void CreateGameState::createNewGame() {
	std::string gameName = static_cast<TextInputField*>(this->mainContentPane->get(this->context->CREATE_GAME_STATE_GAME_NAME_INPUT))->getText();

	this->stack->requestClear();
	this->stack->requestPush(this->context->SINGLEPLAYER_GAME_STATE + " " + gameName);
}