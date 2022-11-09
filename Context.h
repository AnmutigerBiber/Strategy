#ifndef __STRATEGY_CONTEXT_HEADER__
#define __STRATEGY_CONTEXT_HEADER__

#include <SFML/Graphics.hpp>

class Context {
public:
	const int SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
	const int SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;

	const std::string SANFW_FONT = "assets/fonts/sanf_w.ttf";
};

#endif