#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Entity
{
private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Sprite spriteLeft;
    sf::Sprite spriteRight;
    sf::Sprite spriteUp;
    sf::Sprite spriteDown;
    float movementSpeed
        ;
    sf::CircleShape circle;
    float circleRadius;

public:
    Entity();
    virtual ~Entity();

    // Functions
    virtual void move(const float& deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget* target);
    sf::Vector2f getPlayerPosition() const;
    sf::Vector2f getCirlcePosition() const;
    sf::FloatRect getPlayerGlobalBounds() const;
    float getCircleRadius() const;

    /*
    Removed the update rotation stuff as i think i will go with sprites that are turned instead.
    void rotateSprite(float angle);
    */

};
