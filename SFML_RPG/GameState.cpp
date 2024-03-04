#include "GameState.h"
using namespace std;


GameState::GameState(sf::RenderWindow* window)
	: State(window)
{
	if (!backGroundTexture.loadFromFile("grass.png"))
	{
		cout << "Could not load background texture!" << endl;
	}
	else
	{
	backGroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backGroundTexture);

	sf::Vector2u windowSize = window->getSize();
	backgroundSprite.setScale(static_cast<float>(windowSize.x) / backGroundTexture.getSize().x,
		static_cast<float>(windowSize.y) / backGroundTexture.getSize().y);
	}
}

GameState::~GameState() 
{

}


void GameState::endState()
{
	cout << "Ending Gamestate" << endl;
}

void GameState::updateInput(const float &deltaTime)
{
	this->checkForQuit();

	// Player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->player.move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->player.move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->player.move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->player.move(deltaTime, 0.f, 1.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		cout << "Open Inventory" << endl;
	}
}

void GameState::update(const float &deltaTime)
{
	this->updateInput(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	//	cout << "A was pressed" << endl;
	}
	this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget *target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(backgroundSprite);
	player.render(target);

}
