
#include "Game.h"

// Static functions

//Initialier functions

// Constructors/Destructors

// Creates the winwod using RenderWindow. Can set the size of the window here.
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "c++ SFML RPG Game");
}

// Constructor: Initializes the game window.
Game::Game()
{
    this->initWindow();
}

// Destructor to clean up the allocated memory for the window.
Game::~Game() 
{
	delete this->window;
}

void Game::updateDeltaTime()
{
    // Updates the deltatime variable with the time it takes to update and render one frame.
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();

}

// Updates SFMLEvents
void Game::updateSFMLEvents()
{
 
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }


}

// Update game logic
void Game::update()
{
    this->updateSFMLEvents();
}

// Renders gameobjects
void Game::render()
{

    this->window->clear();

    // Render items
    this->window->display();
}

// Runs game loop
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }

}

