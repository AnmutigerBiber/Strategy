#include "Context.h"

Context::Context() {
	this->font.loadFromFile(this->SANFW_FONT);
}

Context::~Context() {
	std::ofstream context_file("settings.txt");

	context_file << "last_game: " << this->last_game;

	context_file.close();
}