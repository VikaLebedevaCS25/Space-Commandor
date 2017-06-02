#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#pragma once

class Triangle {
private:
	sf::CircleShape triangle;
	sf::Vector2f direction;
	float x;
	float y;
	int life;
	Bullet bullets;
	bool isShoot;
	float dy;
	float dx;
public:
	Triangle() {
		x = 300;
		y = 280;
		life = 5;
		isShoot = 0;
		triangle.setPointCount(3);
		triangle.setRadius(20);
		triangle.setFillColor(sf::Color(139, 0, 0));
		triangle.setPosition(x, y);
		triangle.setOrigin(20, 20);
		bullets.setX(x);
		bullets.setY(y);
		bullets.line.setOrigin(x-298, y-302);
		bullets.line.setPosition(bullets.getX(), bullets.getY());
	}
	sf::CircleShape getTriangle() { return triangle; }
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void move(float);
	void Hit() {
		life = life--;
	}

	void Destroy() {
		if (life == 0) triangle.setRadius(20);
		else;
	}
	void draw(sf::RenderWindow* window);
	bool MapCollision();
	void SetRotation(sf::RenderWindow* window);
	void generationBullets() {
		if (bullets.MapCollision()) {
			bullets.setX(x);
			bullets.setY(y);
			isShoot = 0;
		}
		
	}
	void Shoot(sf::RenderWindow* window, float time);
	void drawShoot(sf::RenderWindow* window) {
		window->draw(bullets.line);
	}
	/*void Transposition();*/
};
