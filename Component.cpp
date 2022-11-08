#include "Component.h"

Component::~Component() {
}

Component::Component() {
}

Component::Component(float x, float y, float width, float height) {
	this->setPosition(sf::Vector2f(x, y));
	this->setSize(sf::Vector2f(width, height));
	this->setColor(sf::Color::White);
}

sf::RectangleShape Component::getShape() const {
	return this->shape;
}

void Component::setPosition(sf::Vector2f position) {
	this->shape.setPosition(position);
}

void Component::setSize(sf::Vector2f size) {
	this->shape.setSize(size);
}

void Component::setColor(sf::Color color) {
	this->shape.setFillColor(color);
}

sf::Vector2f Component::getPosition() const {
	return this->shape.getPosition();
}

sf::Vector2f Component::getSize() const {
	return this->shape.getSize();
}

sf::Color Component::getColor() const {
	return this->shape.getFillColor();
}

void Component::render(sf::RenderWindow* window) {
	window->draw(shape);
}

Component* Component::copy() const {
	Component* c = new Component();

	c->setPosition(this->getPosition());
	c->setSize(this->getSize());
	c->setColor(this->getColor());

	return c;
}

bool Component::handleEvent(sf::Event event) {
	return false;
}

void Component::update(sf::Time dt) {
}