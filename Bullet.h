#include <iostream>
#include <SFML/Graphics.hpp>
#pragma once

class Bullet {
public:
	Bullet() {
		line.setSize(sf::Vector2f(5, 2));
	}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	sf::RectangleShape line;
private:
	float x;
	float y;
};