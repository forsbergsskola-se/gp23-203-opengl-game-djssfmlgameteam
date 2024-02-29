
#include "Game.h"

// Static functions

//Initialier functions

// Constructors/Destructors

// Creates the winwod using RenderWindow. Can set the size of the window here.
void Game::initWindow()
{
    std::ifstream ifs("window.ini");
    
    std::string title = "None";
    std::cout << "Title: " << title << std::endl;

    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_Limit = 120;
    bool vertical_synch_enabled = false;

    if (ifs.is_open())
    {
        std::cout << "File opened successfully!" << std::endl;
        if (std::getline(ifs, title))
        {
            std::cout << "Title read from file: " << title << std::endl;
            ifs >> window_bounds.width >> window_bounds.height;
            ifs >> framerate_Limit;
            ifs >> vertical_synch_enabled;
        }
        else
        {
            std::cerr << "Failed to read title from file!" << std::endl;
        }

    }

    // Hardcoding the title since SFML is acting stupid.
    // I was able to get the title from the file and add it to the variable.
    // But using the variable does not work and the string does not even show the default value....
    // This suggests that for some reason SFML can't read the string variable for title.
    // Maybe have to tweek it somehow or use char array... But...
    // I might take a look at this at another time.
    // Or another life.
    this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), "DJ RPG GAME"); 



    ifs.close();

    this->window->setFramerateLimit(framerate_Limit); // Value loads correctly from file
    std::cout << framerate_Limit << std::endl;
    this->window->setVerticalSyncEnabled(vertical_synch_enabled); // Value loads correctly from file
    std::cout << vertical_synch_enabled << std::endl;

    std::cout << "Window configuration loaded successfully!" << std::endl;
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

void Game::initKeys()
{
    // this->supportedKeys.emplace("A", 0);
    // this->supportedKeys.emplace("D", 0);
    // this->supportedKeys.emplace("W", 0);
    // this->supportedKeys.emplace("S", 0);
}

// Constructor: Initializes the game window.
Game::Game()
{
    this->initWindow();
    this->initStates();
}

// Destructor to clean up the allocated memory for the window.
Game::~Game() 
{
	delete this->window;

    while (!this->states.empty())
    {
       delete this->states.top();
       this->states.pop();
    }
}

// Funcitions
void Game::endApplication()
{
    std::cout << "Ending Application" << std::endl;
}

void Game::updateDeltaTime()
{
    // Updates the deltatime variable with the time it takes to update and render one frame.
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();

}

// Updates SFMLEvents
void Game::updateSFMLEvents()
{
 
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }


}

// Update game logic
void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->deltaTime);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

// Renders gameobjects
void Game::render()
{

    this->window->clear();

    // Render items
    if (!this->states.empty())
    {
        this->states.top()->render();
    }
    this->window->display();
}

// Runs game loop
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }

}

