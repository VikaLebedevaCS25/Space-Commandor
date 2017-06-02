#include "Game.h"
#include "Triangle.h"
#pragma once

Game::~Game() {
	delete window;
}

Game::Game() {
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Space Commandor");
	
}

void Game::run() {

	sf::Clock clock;
	sf::Clock clock2;


	sf::Event event;
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;

		float time2 = clock2.getElapsedTime().asMicroseconds();
		clock2.restart();
		time2 = time2 / 500;

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}

		window->clear();
		triangle.move(time);

		triangle.draw(window);
		triangle.SetRotation(window);
		triangle.Shoot(window, time2);
		triangle.drawShoot(window);
		triangle.generationBullets();

		enemy.move(time);
		enemy.draw(window);
		enemy.Shoot(window, time);
		enemy.drawShoot(window);
		enemy.generationBullets();

		if (enemy.MapCollision()) {
			enemy.generationEnemy();
		}



		if (triangle.MapCollision()) {
			window->close();
		}

		window->display();
	}

}