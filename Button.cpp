#include "Button.h"

Button::~Button() {
}

Button::Button(std::string t, float x, float y) : Component(x, y, 0, 0) {
	this->text.setString(t);
	this->text.setCharacterSize(32);

	// must be migrated to FontLoader class
	f.loadFromFile("assets/fonts/sanfw.ttf");
	this->text.setFont(f);

	this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2);
	this->text.setPosition(sf::Vector2f(x, y));
	this->text.setFillColor(sf::Color::Black);

	this->isMouseOnButton = false;
}

void Button::update(sf::Time dt) {
	sf::FloatRect r = this->text.getGlobalBounds();
	
	this->shape.setSize(sf::Vector2f(TARGET_X, TARGET_Y));
	this->shape.setOrigin(this->shape.getSize().x / 2, this->shape.getSize().y / 2);
	this->shape.setPosition(this->text.getPosition().x, this->text.getPosition().y + 7);

	if (this->shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			this->shape.setFillColor(sf::Color(96, 96, 96));
		}
		else {
			this->shape.setFillColor(sf::Color(160, 160, 160));
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