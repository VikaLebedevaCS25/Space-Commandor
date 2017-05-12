#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#pragma once

class Triangle {
private:
	sf::CircleShape triangle;
	float x;
	float y;
	Bullet bullets;
public:
	Triangle() {
		x = 300;
		y = 280;
		triangle.setPointCount(3);
		triangle.setRadius(20);
		triangle.setFillColor(sf::Color(139, 0, 0));
		triangle.setPosition(x, y);
		triangle.setOrigin(20, 20);
		bullets.setX((triangle.getPoint(1)).x);
		bullets.setY((triangle.getPoint(1)).y-5);
	}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void move(float);
	void draw(sf::RenderWindow* window);
	bool MapCollision();
	void SetRotation(sf::RenderWindow* window);
	/*void generationBullets();*/
	void Shoot(sf::RenderWindow* window, float time);
	void drawShoot(sf::RenderWindow* window) {
		bullets.line.setPosition(bullets.getX(), bullets.getY());
		window->draw(bullets.line);
	}
	/*void Transposition();*/
};
