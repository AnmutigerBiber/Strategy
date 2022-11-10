#ifndef __STRATEGY_CONTEXT_HEADER__
#define __STRATEGY_CONTEXT_HEADER__

#include <SFML/Graphics.hpp>

class Context {
public:
	const int SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
	const int SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;

	const std::string MAIN_MENU_STATE = "Main Menu State";
	const std::string MAIN_MENU_STATE_START_GAME_BUTTON = "MainMenuState.StartGame";
	const std::string MAIN_MENU_STATE_QUIT_BUTTON = "MainMenuState.Quit";

	const std::string SINGLEPLAYER_GAME_STATE = "Singleplayer Game State";

	const std::string PAUSE_GAME_STATE = "Pause Game State";
	const std::string PAUSE_GAME_STATE_QUIT_TO_MENU = "PauseGameState.QuitToMenu";
	const std::string PAUSE_GAME_STATE_BACK_TO_GAME = "PauseGameState.BackToGame";

	const std::string SANFW_FONT = "assets/fonts/sanfw.ttf";
};

#endif