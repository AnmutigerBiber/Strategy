#include "Context.h"

Context::Context() {
	this->font.loadFromFile(this->SANFW_FONT);

	std::ifstream context_file("settings.txt");
	std::string line;

	while (getline(context_file, line)){
		settings.insert({ line.substr(0, line.find(":")), line.substr(line.find(":") + 1, line.length() - 1) });
	}

	context_file.close();
}

Context::~Context() {
	std::ofstream context_file("settings.txt");

	for (auto it = this->settings.begin(); it != this->settings.end(); it++) {
		context_file << it->first << ":" << it->second << "\n";
	}

	context_file.close();
}

std::string Context::get(std::string key) {
	return this->settings.find(key)->second;
}

void Context::set(std::string key, std::string val) {
	auto it = this->settings.find(key);

	if (it == this->settings.end()) {
		this->settings.insert({ key, val });
	}
	else {
		it->second = val;
	}
}