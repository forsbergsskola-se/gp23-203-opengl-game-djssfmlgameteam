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

public:
    GameState(sf::RenderWindow *window);
    virtual ~GameState();

    // Functions
    void endState();

    void updateInput(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

