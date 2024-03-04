#include "MainMenuState.h"

MainMenuState::~MainMenuState()
{
}

void MainMenuState::endState()
{
}

void MainMenuState::updateInput(const float& deltaTime)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& deltaTime)
{
	this->updateInput(deltaTime);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
}
