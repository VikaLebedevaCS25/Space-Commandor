#include <SFML/Graphics.hpp>
#include "Bullet.h"

bool Bullet::MapCollision() {
	sf::FloatRect boundingBox = line.getGlobalBounds();
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
