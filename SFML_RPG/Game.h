#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:

	// Variables
	sf::RenderWindow *window; // Pointer to the SFML window.
	sf::Event sfEvent;

	sf::Clock deltaTimeClock;
	float deltaTime;

	std::stack<State*> states;

	// Initialization
	void initWindow(); // Initialize the SFML window.
	void initStates();

	// Constructors/Destructors

public:
	Game();
	virtual ~Game();

	//My public member Functions
	void updateDeltaTime();
	void updateSFMLEvents(); // Updates SFML Events
	void update(); // Update gamelogic and such.
	void render(); // Rendering the game objects
	void run(); // Runs the game loop.

};

#endif