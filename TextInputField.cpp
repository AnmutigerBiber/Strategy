#include "TextInputField.h"

TextInputField::~TextInputField() {
}

TextInputField::TextInputField(std::string t, float x, float y, Context* c) : Component(x, y, this->TARGET_X, this->TARGET_Y, c) {
	this->text.setString(t);
	this->text.setCharacterSize(32);
	this->text.setFont(this->context->font);

	this->text.setOrigin(this->text.getLocalBounds().width / 2.0, this->text.getLocalBounds().height / 2.0);
	this->text.setPosition(sf::Vector2f(x, y));
	this->text.setFillColor(sf::Color(160, 160, 160));

	// somehow the initialization in the superclass does not work
	// but this is not really an issue
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(1);
	this->shape.setSize(sf::Vector2f(this->TARGET_X, this->TARGET_Y));
	this->shape.setOrigin(this->TARGET_X / 2.0, this->TARGET_Y / 2.0);
	this->shape.setPosition(x, y + 8.0);
	this->shape.setFillColor(sf::Color::White);

	this->keycodes.insert({ sf::Keyboard::A, "a" });
	this->keycodes.insert({ sf::Keyboard::B, "b" });
	this->keycodes.insert({ sf::Keyboard::C, "c" });
	this->keycodes.insert({ sf::Keyboard::D, "d" });
	this->keycodes.insert({ sf::Keyboard::E, "e" });
	this->keycodes.insert({ sf::Keyboard::F, "f" });
	this->keycodes.insert({ sf::Keyboard::G, "g" });
	this->keycodes.insert({ sf::Keyboard::H, "h" });
	this->keycodes.insert({ sf::Keyboard::I, "i" });
	this->keycodes.insert({ sf::Keyboard::J, "j" });
	this->keycodes.insert({ sf::Keyboard::K, "k" });
	this->keycodes.insert({ sf::Keyboard::L, "l" });
	this->keycodes.insert({ sf::Keyboard::M, "m" });
	this->keycodes.insert({ sf::Keyboard::N, "n" });
	this->keycodes.insert({ sf::Keyboard::O, "o" });
	this->keycodes.insert({ sf::Keyboard::P, "p" });
	this->keycodes.insert({ sf::Keyboard::Q, "q" });
	this->keycodes.insert({ sf::Keyboard::R, "r" });
	this->keycodes.insert({ sf::Keyboard::S, "s" });
	this->keycodes.insert({ sf::Keyboard::T, "t" });
	this->keycodes.insert({ sf::Keyboard::U, "u" });
	this->keycodes.insert({ sf::Keyboard::V, "v" });
	this->keycodes.insert({ sf::Keyboard::W, "w" });
	this->keycodes.insert({ sf::Keyboard::X, "x" });
	this->keycodes.insert({ sf::Keyboard::Y, "y" });
	this->keycodes.insert({ sf::Keyboard::Z, "z" });
	this->keycodes.insert({ sf::Keyboard::Num0, "0" });
	this->keycodes.insert({ sf::Keyboard::Num1, "1" });
	this->keycodes.insert({ sf::Keyboard::Num2, "2" });
	this->keycodes.insert({ sf::Keyboard::Num3, "3" });
	this->keycodes.insert({ sf::Keyboard::Num4, "4" });
	this->keycodes.insert({ sf::Keyboard::Num5, "5" });
	this->keycodes.insert({ sf::Keyboard::Num6, "6" });
	this->keycodes.insert({ sf::Keyboard::Num7, "7" });
	this->keycodes.insert({ sf::Keyboard::Num8, "8" });
	this->keycodes.insert({ sf::Keyboard::Num9, "9" });
	this->keycodes.insert({ sf::Keyboard::Space, " " });
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
			else if (event.key.code == sf::Keyboard::Backspace) {
				this->text.setString(this->text.getString().substring(0, this->text.getString().getSize() - 1));
			}
			else {
				if (this->keycodes.find(event.key.code) != this->keycodes.end()) {
					this->text.setString(this->text.getString() + this->keycodes.find(event.key.code)->second);
				}
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

	this->shape.setOrigin(this->shape.getLocalBounds().width / 2.0, this->shape.getLocalBounds().height / 2.0);

	this->text.setOrigin(this->text.getLocalBounds().width / 2.0, this->text.getLocalBounds().height / 2.0);
	// somehow the changing of the origin 
	this->text.setPosition(this->shape.getGlobalBounds().left + TARGET_X / 2.0, this->shape.getGlobalBounds().top + TARGET_Y / 2.0 - 5.0);
}

void TextInputField::render(sf::RenderWindow* window) {
	window->draw(this->shape);
	window->draw(this->text);
}