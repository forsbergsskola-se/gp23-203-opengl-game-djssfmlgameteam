#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{

}

GameState::~GameState() 
{

}


void GameState::endState()
{
	std::cout << "Ending Gamestate" << std::endl;
}

void GameState::updateKeybinds(const float &deltaTime)
{
	this->checkForQuit();
}

void GameState::update(const float &deltaTime)
{
	this->updateKeybinds(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A was pressed" << std::endl;
	}
	this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget *target)
{
	if (target)
	{

	}
	else
	{
	this->player.render(this->window);
	}

}
