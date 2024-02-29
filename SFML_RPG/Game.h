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

	std::map<char*, int> supportedKeys;

	// Initialization
	void initWindow(); // Initialize the SFML window.
	void initStates();
	void initKeys();

	// Constructors/Destructors

public:
	Game();
	virtual ~Game();

	// My public member Functions
	
	// Regular
	void endApplication();

	// Update
	void updateDeltaTime();
	void updateSFMLEvents(); // Updates SFML Events
	void update(); // Update gamelogic and such.
	
	// Render
	void render(); // Rendering the game objects

	// Core
	void run(); // Runs the game loop.
};

#endif