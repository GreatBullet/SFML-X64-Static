#include<SFML\Graphics.hpp>
#include<iostream>
int main()
{
	float playerspeed = 10;
	int frame = 0;
	int row = 2;
	sf::RenderWindow window(sf::VideoMode(2560, 1440),"SFML window",sf::Style::Close|sf::Style::Resize);
	window.setFramerateLimit(60);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Red);
	player.setOrigin(50.0f, 50.0f);
	sf::Texture spriteSheet;
	sf::Sprite playerSprite;
	int frameCounter = 0;
	if (!spriteSheet.loadFromFile("oorjG.png"))
	{
		std::cout << "Fail at spriting!" << std::endl;
	}
	playerSprite.setTexture(spriteSheet);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("New window width: %i New window height: %i \n", evnt.size.width, evnt.size.height);
				break;
			}
		}
		playerSprite.setTextureRect(sf::IntRect(0, 0, 90, 90));
		if (frameCounter == 60)
		{
			frame = (frame + 1) % 4;
			frameCounter = 0;
		}
		frameCounter++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			
			playerSprite.move(-playerspeed, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			playerSprite.setTextureRect(sf::IntRect(0, 90, 90, 90));
			playerSprite.move(playerspeed, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			playerSprite.move(0.0f, playerspeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			playerSprite.move(0.0f, -playerspeed);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			playerSprite.setPosition(mousePos.x,mousePos.y);
		}

		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}
	return 0;
}