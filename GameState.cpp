#include "GameState.h"

GameState::~GameState() {
}

GameState::GameState() {
}

void GameState::setName(std::string n) {
	this->name = n;
}

std::string GameState::getName() {
	return this->name;
}