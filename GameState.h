#ifndef __STRATEGY_GAME_STATE_HEADER__
#define __STRATEGY_GAME_STATE_HEADER__

#include <SFML/Graphics.hpp>

class GameState {
protected:
	std::string name;
public:
	GameState();
	virtual ~GameState();

	virtual bool handleEvent(sf::Event event) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void render(sf::RenderWindow* window) = 0;

	void setName(std::string n);
	std::string getName();
};

#endif