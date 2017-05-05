#include "Game.h"
#include "Triangle.h"
#pragma once

Game::Game() {
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Space Commandor");
	sf::Clock clock;
	

	sf::Event event;
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 500; //�������� ����

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			triangle.move(time);
		}

		window->clear();
		triangle.move(time);

		triangle.draw(window);
		/*triangle.SetRotation(window);*/

		if (triangle.MapCollision()) {
			window->close();
		}

		window->display();
	}

}
