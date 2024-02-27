#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class Game
{
private:

	// Variables
	sf::RenderWindow *window; // Pointer to the SFML window.
	sf::Event sfEvent;

	// Initialization
	void initWindow(); // Initialize the SFML window.

	// Constructors/Destructors


public:
	Game();
	virtual ~Game();

	//My public member Functions
	void updateSFMLEvents(); // Updates SFML Events
	void update(); // Update gamelogic and such.
	void render(); // Rendering the game objects
	void run(); // Runs the game loop.

};

#endif