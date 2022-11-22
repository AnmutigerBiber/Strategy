#include "Game.h"

Game::~Game() {
	this->save();
}

Game::Game(std::string f, Context* c) {
	this->context = c;
	this->context->set("last_game", f);

	this->filename = f;

	this->load();
}

bool Game::handleEvent(sf::Event event) {
	return false;
}

void Game::update(sf::Time dt) {

}

void Game::render(sf::RenderWindow* window) {
	window->clear(sf::Color::White);
	
	sf::CircleShape shape;

	shape.setPosition(100, 100);
	shape.setRadius(20);
	shape.setFillColor(sf::Color::Red);

	window->draw(shape); // to show that creating game has worked
}

void Game::load() {

}

void Game::save() {
	
}