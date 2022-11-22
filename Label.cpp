#include "Label.h"

Label::Label(float x, float y, std::string t, Context* c) : Component(c) {
	this->text.setFont(c->font);
	this->text.setString(t);
	this->text.setFillColor(sf::Color::Black);
	this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2);
	this->text.setPosition(x, y);

	this->shape.setSize(sf::Vector2f(this->TARGET_X, this->TARGET_Y));
	this->shape.setOrigin(this->TARGET_X / 2, this->TARGET_Y / 2);
	this->shape.setOutlineThickness(1);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(x, y);
}

Label::~Label() {
}

void Label::setText(std::string t) {
	this->text.setString(t);
	this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2);
	this->text.setPosition(this->shape.getPosition());
}

std::string Label::getText() {
	return this->text.getString();
}

bool Label::handleEvent(sf::Event event) {
	return false;
}

void Label::update(sf::Time dt) {
	this->shape.setPosition(this->text.getPosition());
}

void Label::render(sf::RenderWindow* window) {
	window->draw(this->shape);
	window->draw(this->text);
}