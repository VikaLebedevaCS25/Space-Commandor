#include <iostream>
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#pragma once


class Game {
public:
	Game();
private:
	sf::RenderWindow* window;
	Triangle triangle;
};