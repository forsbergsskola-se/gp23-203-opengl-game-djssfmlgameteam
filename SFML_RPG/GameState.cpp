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
}

void GameState::update(const float& deltaTime)
{
	std::cout << "Hellow from GameState" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{

}
