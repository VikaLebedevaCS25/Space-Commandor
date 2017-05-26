#include <iostream>
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#pragma once
using namespace sf;


void Triangle::move( float time) {
	float dx = 0;
	float dy = 0;

	if  ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
		dx = dx - 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
		dx = dx + 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
		dy = dy - 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
		dy = dy + 0.1;
	}

	x = x + dx* time;
	y = y + dy* time;

	triangle.setPosition(x, y);

}

void Triangle::draw(sf::RenderWindow* window) {
	window->draw(triangle);
}

bool Triangle::MapCollision() {
	sf::FloatRect boundingBox = triangle.getGlobalBounds();
	for (int i = 1; i <= 640; i++) {
		sf::Vector2f point1;
		point1.x = i;
		point1.y = 0;

		sf::Vector2f point4;
		point4.x = i;
		point4.y = 480;

		if (boundingBox.contains(point1) || boundingBox.contains(point4))
			return true;
	}

	for (int j = 1; j <= 480; j++) {
		sf::Vector2f point2;
		point2.x = 0;
		point2.y = j;

		sf::Vector2f point3;
		point3.x = 640;
		point3.y = j;

		if (boundingBox.contains(point2) || boundingBox.contains(point3))
			return true;
	}
	return false;
}

void Triangle::SetRotation(sf::RenderWindow* window) {
	sf::Vector2i pos = Mouse::getPosition(*window);
	float dX = pos.x - x;
	float dY = pos.y - y;
	float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
	triangle.setRotation(rotation-30);
	}



void Triangle::Shoot(sf::RenderWindow * window, float time) {
	float dy = 0;
	dy = dy - 0.08;
	bullets.setY(bullets.getY() + dy*time);
	bullets.line.setPosition(bullets.getX(), bullets.getY());
}