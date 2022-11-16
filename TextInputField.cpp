#include "TextInputField.h"

TextInputField::~TextInputField() {
}

TextInputField::TextInputField(std::string t, float x, float y, Context* c) : Component(x, y, this->TARGET_X, this->TARGET_Y, c) {
	this->text.setString(t);
	this->text.setCharacterSize(32);
	this->text.setFont(this->context->font);

	this->text.setPosition(sf::Vector2f(x, y));
	this->text.setFillColor(sf::Color::Black);
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
				this->
			}
		}
	}

	return true;
}