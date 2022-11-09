#ifndef __STRATEGY_CONTAINER_HEADER__
#define __STRATEGY_CONTAINER_HEADER__

#include <map>

#include "Context.h"
#include "Component.h"

class Container : public Component {
private:
	std::map<std::string, Component*>* children;
public:
	Container(Context* c);
	Container(float x, float y, float width, float height, Context *c);
	~Container();

	void add(Component c, std::string key);
	void add(Component* c, std::string key);
	Component* get(std::string key);

	bool handleEvent(sf::Event event);
	void update(sf::Time dt);
	void render(sf::RenderWindow* window);
};

#endif