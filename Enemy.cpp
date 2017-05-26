#include <SFML/Graphics.hpp>
#include <cmath>
#include "Enemy.h"

void Enemy::draw(sf::RenderWindow* window) {
	window->draw(triangle);
}

bool Enemy::MapCollision() {
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

void Enemy::Shoot(sf::RenderWindow * window, float time) {
	float dy = 0;
	dy = dy + 0.08;
	bullets.setY(bullets.getY() + dy*time);
	bullets.line.setPosition(bullets.getX(), bullets.getY());
}

void Enemy::move(float time) {
	float dy = 0;
	float dx = 0;
	dy = dy + 0.05;
	y = y + dy* time;
	dx =dy;
	/*switch (rand() % 4) {
	case 0: dx = log(dy);
	case 1: dx =  -dy;
	case 2: dx =  dy;
	case 3: dx = tan(dy);
	}*/
	x = x + dx* time;
	triangle.setPosition(x, y);
}