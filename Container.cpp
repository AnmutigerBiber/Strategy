#include "gui/Container.h"

Container::Container(Context* c) : Component(c) {
	this->children = new std::map<std::string, Component*>();
}

Container::Container(float x, float y, float width, float height, Context* c) : Component(x, y, width, height, c) {
	this->children = new std::map<std::string, Component*>();
}

Container::~Container() {
	for (auto it = this->children->begin(); it != this->children->end(); it++) {
		delete it->second;
	}

	delete children;
}

void Container::add(Component c, std::string key) {
	this->children->insert({ key, c.copy() });
}

void Container::add(Component* c, std::string key) {
	this->children->insert({ key, c });
}

Component* Container::get(std::string key) {
	for (auto it = this->children->begin(); it != this->children->end(); it++) {
		if (it->first == key) {
			return it->second;
		}
	}
}

bool Container::handleEvent(sf::Event event) {
	bool val = false;

	for (auto it = this->children->begin(); it != this->children->end(); it++) {
		val |= it->second->handleEvent(event);
	}

	return false || val;
}

void Container::render(sf::RenderWindow* window) {
	window->draw(this->shape);

	for (auto it = this->children->begin(); it != this->children->end(); it++) {
		it->second->render(window);
	}
}

void Container::update(sf::Time dt) {
	for (auto it = this->children->begin(); it != this->children->end(); it++) {
		it->second->update(dt);
	}
}