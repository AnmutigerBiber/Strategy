#include "MainMenuState.h"

MainMenuState::~MainMenuState() {
	delete mainContentPane;
}

MainMenuState::MainMenuState() {
	this->mainContentPane = new Container(0.0, 0.0, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

	this->mainContentPane->add(new Button("Play", sf::VideoMode::getDesktopMode().width / 2, 256), "MainMenuState.StartGame");
}

bool MainMenuState::handleEvent(sf::Event event) {
	bool val = this->mainContentPane->handleEvent(event);
	
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			return true;
		}
	}

	return false;
}

void MainMenuState::update(sf::Time dt) {
	this->mainContentPane->update(dt);
}

void MainMenuState::render(sf::RenderWindow* window) {
	this->mainContentPane->render(window);
}