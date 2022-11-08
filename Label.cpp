#include "Label.h"

// not ready for usage yet
Label::Label(std::string name, std::string t) {
	this->text.setString(t);
	// Load font
}

Label::~Label() {
}

void Label::setText(std::string t) {
	this->text.setString(t);
}

std::string Label::getText() {
	return this->text.getString();
}

void Label::render(sf::RenderWindow* window) {
	window->draw(this->text);
}