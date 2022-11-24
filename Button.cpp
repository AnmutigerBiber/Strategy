#include "gui/Button.h"

Button::~Button() {
}

Button::Button(std::string t, float x, float y, Context* c) : Component(x, y, 0.0, 0.0, c) {
	this->text.setString(t);
	this->text.setCharacterSize(32);

	this->text.setFont(this->context->font);

	this->text.setOrigin(this->text.getLocalBounds().width / 2.0, this->text.getLocalBounds().height / 2.0);
	this->text.setPosition(this->position);
	this->text.setFillColor(sf::Color::Black);

	this->isMouseOnButton = false;
}

bool Button::handleEvent(sf::Event event) {
	return false;
}

void Button::update(sf::Time dt) {
	sf::FloatRect r = this->text.getGlobalBounds();
	
	this->shape.setSize(sf::Vector2f(TARGET_X, TARGET_Y));
	this->shape.setOrigin(this->shape.getLocalBounds().width / 2.0, this->shape.getLocalBounds().height / 2.0);
	this->shape.setPosition(this->position);

	this->text.setOrigin(this->text.getLocalBounds().width / 2.0, this->text.getLocalBounds().height / 2.0 + 5.0);
	this->text.setPosition(this->position);

	if (this->shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			this->shape.setFillColor(sf::Color(96, 96, 96));

			this->isButtonPressed = true;
		}
		else {
			this->shape.setFillColor(sf::Color(160, 160, 160));

			this->isButtonPressed = false;
		}
	} else {
		this->shape.setFillColor(sf::Color(192, 192, 192));
	}
}

void Button::render(sf::RenderWindow* window) {
	window->draw(shape);
	window->draw(text);
}

void Button::setMouseIsOnButton(bool b) {
	this->isMouseOnButton = b;
}

void Button::onClick(void(*fnc)()) {
	this->callback = fnc;
}

void Button::click() {
	(*callback)();
}

bool Button::isPressed() {
	return this->isButtonPressed;
}

bool Button::contains(sf::Vector2f pos) {
	return this->shape.getGlobalBounds().contains(pos);
}