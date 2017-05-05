#include <iostream>
#include <SFML/Graphics.hpp>
#pragma once

class Triangle {
private:
	sf::CircleShape triangle;
	float x;
	float y;
	int side;
public:
	Triangle() {
		x = 300;
		y = 280;
		side = 20;
	}
	float getX() { return x; }
	float getY() { return y; }
	int getSide() { return side; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void move(float);
	void draw(sf::RenderWindow* window);
	bool MapCollision();
	void SetRotation(sf::RenderWindow* window);
	void Transposition();
};
