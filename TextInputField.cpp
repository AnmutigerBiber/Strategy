#include "TextInputField.h"

TextInputField::~TextInputField() {
}

TextInputField::TextInputField(std::string t, float x, float y, Context* c) : Component(x, y, this->TARGET_X, this->TARGET_Y, c) {
	this->text.setString(t);
	this->text.setCharacterSize(32);
	this->text.setFont(this->context->font);

	this->text.setPosition(sf::Vector2f(x, y));
	this->text.setFillColor(sf::Color::Black);

	// somehow the initialization in the superclass does not work
	// but this is not really an issue
	this->shape.setSize(sf::Vector2f(this->TARGET_X, this->TARGET_Y));
	this->shape.setOrigin(this->TARGET_X / 2, this->TARGET_Y / 2);
	this->shape.setPosition(x, y);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(1);
}

void TextInputField::clear() {
	this->text.setString("");
}

void TextInputField::setActive(bool a) {
	this->active = a;
}

std::string TextInputField::getText() {
	return this->text.getString();
}

bool TextInputField::handleEvent(sf::Event event) {
	if (this->active) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				this->active = false;
				return true;
			}
		}
	}
	
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (this->shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))) {
				this->active = true;
				return true;
			}
			else {
				this->active = false;
			}
		}
	}

	return false;
}

void TextInputField::update(sf::Time dt) {
	if (this->active) {
		this->shape.setOutlineColor(sf::Color(160, 160, 160));
	}
	else {
		this->shape.setOutlineColor(sf::Color::Black);
	}
}

void TextInputField::render(sf::RenderWindow* window) {
	window->draw(this->shape);
	window->draw(this->text);
}