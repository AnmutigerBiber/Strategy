#include "GameState.h"

GameState::~GameState() {
}

GameState::GameState(Context* c) {
	this->context = c;
}

void GameState::setName(std::string n) {
	this->name = n;
}

std::string GameState::getName() {
	return this->name;
}