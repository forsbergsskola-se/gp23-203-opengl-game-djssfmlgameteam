#include "Entity.h"

using namespace std;

Entity::Entity()
{
	if (!playerTexture.loadFromFile("standing.png"))
	{
		cout << "Failed to load the player textures" << endl;
	}
	else
	{
		cout << "Player Texture loaded successfully!" << std::endl;
		playerSprite.setTexture(playerTexture);
		cout << "Texture size: " << playerTexture.getSize().x << "x" << playerTexture.getSize().y << std::endl;
		playerSprite.setScale(.1f, .1f);
		playerSprite.setPosition(100.f, 100.f);
		
		this->movementSpeed = 300.f;
	}
	 
}

Entity::~Entity()
{

}

void Entity::move(const float &deltaTime, const float dir_x, const float dir_y)
{
	this->playerSprite.move(dir_x * this->movementSpeed * deltaTime, dir_y * this->movementSpeed * deltaTime);
}

void Entity::update(const float &deltaTime)
{

}

void Entity::render(sf::RenderTarget *target)
{
	target->draw(this->playerSprite);
}

/*
Removed the update rotation stuff as i think i will go with sprites that are turned instead.
void Entity::rotateSprite(float angle) 
{
	playerSprite.setRotation(angle);
}
*/

