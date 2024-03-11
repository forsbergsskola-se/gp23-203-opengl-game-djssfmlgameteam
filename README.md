
![2024-03-11 23_06_00-Window](https://github.com/forsbergsskola-se/gp23-203-opengl-game-djssfmlgameteam/assets/89846079/d814b8e1-9753-4984-9d9b-5f46b66987b1)

Description:
This game is a botched attempt at making a RPG game.

After the getting stuck on a million issues a million times in a week I realized that I would not be able to create a RPG game.

I was also very put off by SFML being so slow and requiring way to much coding for things to happen.

In Unity I can set up the same scene I did in SFML but instead of in 2 weeks it would take me 5 minutes.

This bored and frustrated me.

Especially after sinking 8 hours trying to get the game work with a sprite sheet for movement.

I never got it to work and discarded all the code.

I did not feel like I learned anything while doign SFML.

So i divided up my time working on this "Game" and studying a great C++ course on udemy named: 

Beginning C++ Programming - From Beginner to Beyond

After the two weeks I have completed 153 / 305 lessons.

I felt like doing the course was very fun and I filled in a lot of my c++ holes that I felt I had.

Back to the "Game".
Evetually I just threw together so that the character could stand in a blue box and then it prints to the console.
Overall the experience with SFML can be summarized in one word "Tedious".

One Class is documented:

```
// Gamestate.h
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

``` 

```
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

void GameState::updateInput(const float& deltaTime)
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

void GameState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);

    sf::Vector2f playerPosition = player.getPlayerPosition();

    sf::Vector2f circlePosition = player.getCirlcePosition();

    // Calculate distance between player and circle
    float distance = sqrt(pow(playerPosition.x - circlePosition.x, 2) + pow(playerPosition.y - circlePosition.y, 2));

    float sumOfRadii = player.getPlayerGlobalBounds().width / 2 + player.getCircleRadius();

    if (distance < sumOfRadii)
    {
        cout << "Player is in the circle.";
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //	cout << "A was pressed" << endl;
    }
    this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    target->draw(backgroundSprite);
    player.render(target);
}
```



[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UqIUAt8b)


