#include "Application.h"

#include <iostream>

Application::~Application() {
	delete this->stack;
	
	delete this->window;
}

Application::Application() {
	this->window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Strategy", sf::Style::Fullscreen);

	this->stack = new StateStack();
	this->stack->push("Main Menu State");
}

void Application::start() {
	this->mainloop();
}

void Application::mainloop() {
	while (window->isOpen()) {
		this->handleEvents();

		this->update(this->clock.restart());

		this->render();
	}
}

void Application::handleEvents() {
	sf::Event event;

	while (this->window->pollEvent(event)) {
		if (this->stack->peek()->handleEvent(event)) {
			this->window->close();
		}
	}
}

void Application::update(sf::Time dt) {
	this->stack->peek()->update(dt);
}

void Application::render() {
	this->window->clear(sf::Color::White);

	this->stack->peek()->render(this->window);

	this->window->display();
}