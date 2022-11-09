#ifndef __STRATEGY_MAIN_MENU_STATE_HEADER__
#define __STRATEGY_MAIN_MENU_STATE_HEADER__

#include "Context.h"
#include "GameState.h"
#include "Container.h"
#include "Button.h"

class MainMenuState : public GameState {
private:
	Container *mainContentPane;

	Context* context;
public:
	MainMenuState(Context* c);
	~MainMenuState();

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif