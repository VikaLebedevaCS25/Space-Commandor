#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#pragma once

class Enemy {
public:
	Enemy() {
		x = rand() % 640;
		y = 14;
		life = 5;
		triangle.setPointCount(3);
		triangle.setRadius(20);
		triangle.setFillColor(sf::Color(75, 0, 130));
		triangle.setPosition(x, y);
		triangle.setOrigin(20, 20);
		bullets.setX(x - 2);
		triangle.setRotation(180);
		bullets.setY(y + 26);
		bullets.line.setPosition(bullets.getX(), bullets.getY());
	}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void draw(sf::RenderWindow* window);
	bool MapCollision();
	sf::CircleShape getTriangle() { return triangle; }
	void Hit() {
		life = life--;
	}

	void Destroy() {
		if( life==0) triangle.setRadius(20);
		else ;
	}
	void move(float);
	void generationBullets() {
		if (bullets.MapCollision()) {
			bullets.setX(x - 2);
			bullets.setY(y + 26);
		}
	}
	void Shoot(sf::RenderWindow* window, float time);
	void drawShoot(sf::RenderWindow* window) {
		window->draw(bullets.line);
	}
	void generationEnemy() {
		x = rand() % 640;
		y = 14;
		bullets.setX(x - 2);
		bullets.setY(y + 26);
	}
private:
	sf::CircleShape triangle;
	float x;
	int life;
	float y;
	Bullet bullets;

};