#include "gui/Component.h"

Component::~Component() {
}

Component::Component(Context* c) {
	this->context = c;
}

Component::Component(float x, float y, float width, float height, Context* c) {
	this->context = c;

	this->position = sf::Vector2f(x, y);

	this->setPosition(this->position);
	this->setSize(sf::Vector2f(width, height));
	this->setColor(sf::Color::White);
}

sf::RectangleShape Component::getShape() const {
	return this->shape;
}

void Component::setPosition(sf::Vector2f p) {
	this->shape.setPosition(p);
}

void Component::setSize(sf::Vector2f size) {
	this->shape.setSize(size);
}

void Component::setColor(sf::Color color) {
	this->shape.setFillColor(color);
}

sf::Vector2f Component::getPosition() const {
	return this->position;
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
	Component* c = new Component(this->context);

	c->setPosition(this->position);
	c->setSize(this->getSize());
	c->setColor(this->getColor());

	return c;
}

bool Component::handleEvent(sf::Event event) {
	return false;
}

void Component::update(sf::Time dt) {
}