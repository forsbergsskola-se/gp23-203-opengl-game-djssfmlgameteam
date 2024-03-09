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

void Entity::move(const float& deltaTime, const float dir_x, const float dir_y)
{
    this->playerSprite.move(dir_x * this->movementSpeed * deltaTime, dir_y * this->movementSpeed * deltaTime);
}

void Entity::update(const float& deltaTime)
{

}

void Entity::render(sf::RenderTarget* target)
{

    circle.setRadius(50);
    this->circleRadius = 50.f;
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(0.f, 0.f);
    target->draw(circle);

    target->draw(this->playerSprite);
}

sf::Vector2f Entity::getPlayerPosition() const
{
    return playerSprite.getPosition();
}

sf::FloatRect Entity::getPlayerGlobalBounds() const
{
    return playerSprite.getGlobalBounds();
}

sf::Vector2f Entity::getCirlcePosition() const
{
    return circle.getPosition();
}

float Entity::getCircleRadius() const {
    return circle.getRadius();
}
