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

	sf::Vector2f movementDirection(0.f, 0.f);
	// Player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movementDirection.x = -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movementDirection.x = 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movementDirection.y = -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movementDirection.y = 1.f;
	}

	this->updateRotation(movementDirection);
	player.move(deltaTime, movementDirection.x, movementDirection.y);

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

void GameState::updateRotation(const sf::Vector2f& direction)
{
	float angle = std::atan2(direction.y, direction.x) * (180.f / pi);
	player.rotateSprite(angle);
}