#include <iostream>
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#include "Enemy.h"
#pragma once


class Game {
public:
	Game();
	~Game();
	void run();
private:
	sf::RenderWindow* window;
	Triangle triangle;
	Enemy enemy;
};