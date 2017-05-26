#include <iostream>
#include <SFML/Graphics.hpp>
#pragma once

class Bullet {
public:
	Bullet() {
		line.setSize(sf::Vector2f(4, 6));
	}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	bool MapCollision();
	void setY(float y) { this->y = y; }
	float getDir() { return direction; }
	void setDir(float dir) { direction = dir; }
	sf::RectangleShape line;
private:
	float x;
	float y;
	float direction;
};