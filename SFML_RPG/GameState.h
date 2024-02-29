#pragma once
#include "State.h"
class GameState :
    public State
{
private:
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

