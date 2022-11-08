#ifndef __STRATEGY_COMPONENT_HEADER__
#define __STRATEGY_COMPONENT_HEADER__

#include <SFML/Graphics.hpp>

#include <string>

class Component {
private:

protected:
	sf::RectangleShape shape;

public:
	virtual ~Component();
	Component();
	Component(float x, float y, float width, float height);

	virtual sf::RectangleShape getShape() const;

	virtual void setPosition(sf::Vector2f position);
	virtual void setSize(sf::Vector2f size);
	virtual void setColor(sf::Color color);

	virtual sf::Vector2f getPosition() const;
	virtual sf::Vector2f getSize() const;
	virtual sf::Color getColor() const;

	virtual Component* copy() const;

	virtual bool handleEvent(sf::Event event);
	virtual void update(sf::Time dt);
	virtual void render(sf::RenderWindow* window);
};

#endif