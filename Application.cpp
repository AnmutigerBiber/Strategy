#include "Application.h"

#include <iostream>

Application::~Application() {
	delete this->currentState;
	
	delete this->window;
}

Application::Application() {
	this->window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Strategy", sf::Style::Fullscreen);

	this->currentState = new MainMenuState();
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
		if (this->currentState->handleEvent(event)) {
			this->window->close();
		}
	}
}

void Application::update(sf::Time dt) {
	this->currentState->update(dt);
}

void Application::render() {
	this->window->clear(sf::Color::White);

	this->currentState->render(this->window);

	this->window->display();
}