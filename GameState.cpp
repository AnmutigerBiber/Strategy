#include "GameState.h"

GameState::~GameState() {
}

GameState::GameState(StateStack* s, Context* c) {
	this->context = c;

	this->stack = s;
}

void GameState::setName(std::string n) {
	this->name = n;
}

std::string GameState::getName() {
	return this->name;
}