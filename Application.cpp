#include "Application.h"

Application::~Application() {
	delete this->stack;
	
	delete this->window;

	delete this->context;
}

Application::Application(Context* c) {
	this->context = c;

	this->window = new sf::RenderWindow(sf::VideoMode(this->context->SCREEN_WIDTH, this->context->SCREEN_HEIGHT), "Strategy", sf::Style::Fullscreen);
	this->window->setVerticalSyncEnabled(true);

	this->stack = new StateStack(context);
	this->stack->push(c->MAIN_MENU_STATE);
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
		this->stack->handleEvent(event);
	}
}

void Application::update(sf::Time dt) {
	this->stack->update(dt);
}

void Application::render() {
	this->stack->render(this->window);

	this->window->display();
}