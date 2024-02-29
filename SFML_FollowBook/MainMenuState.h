#pragma once
#include "State.h" // Include the header file that contains the State class declaration

class MainMenuState : public State {
public:
    MainMenuState(sf::RenderWindow* window);
    virtual ~MainMenuState();

    // Other member functions and variables
    void endState();

    void updateInput(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = NULL);
};
