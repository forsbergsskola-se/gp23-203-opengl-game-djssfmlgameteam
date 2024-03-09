#pragma once
#include "State.h"
//#include <SFML/Graphics.hpp>
class GameState :
    public State
{
private:
    sf::Texture backGroundTexture;
    sf::Sprite backgroundSprite;

    Entity player;
    Entity circle;
    // There will be no pie today.
    // const float pi = 3.14159265f;

public:
    GameState(sf::RenderWindow *window);
    virtual ~GameState();

    // Functions
    void endState();

    void updateInput(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
    /*
    Removed the update rotation stuff as i think i will go with sprites that are turned instead.
    void updateRotation(const sf::Vector2f& direction);
    */
};

