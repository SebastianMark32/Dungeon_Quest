#include "Dependencies.h"

static int score = 0;

// boolean for mouse being pressed
bool mouseReleased = false;

// this is rendering a window which displays the viewer window
sf::RenderWindow window(sf::VideoMode(2560 , 1600), "Dungeon Quest!", sf::Style::Resize);

// global vector
sf:: Vector2f playerPosition;

bool playerMoving = false;

void update(float dt){

    sf::Sprite hero;

    if(playerMoving){
        hero.move(50.0f*dt, 0);
    }
}
int main(){
    //Create random number
    srand((int)time(0));
    sf::Clock clock;
    //int to get random number from
    int randomNum;
    //player control logic
    bool wKeyReleased = true;
    bool aKeyReleased = true;
    bool sKeyReleased = true;
    bool dKeyReleased = true;
    sf::Event event;

    // game font
    Fonts gameFont("../Assets/ArianaVioleta-dz2K.ttf");
    gameFont.setSize(200);
    gameFont.setStyle(sf::Text::Regular);
    gameFont.setString("Welcome to our game!");
    gameFont.setPosition(700.f, 5.0f);

    //player character
    Character character("../Assets/Knight3Walk.png");
    character.setScale(0.93f, 0.93f);
    character.setPosition(8.0f, 0.0f);


    // this is background
    Background background_sprite("../Assets/background800x600.png");

    // sprite sprite
    Enemy enemy1("../Assets/Enemy.png");
    //enemy1.setScale(0.5f, 1.5f);
    enemy1.setPosition(500.0f, 400.0f);
    enemy1.setScale(0.93f, 0.93f);

    Enemy enemy2("../Assets/images.png");
    enemy2.setPosition(600.f, 800.f);
    enemy2.setScale(2, 2);

    // Music
    Music gameMusic("");

    window.setVerticalSyncEnabled(true);

    float enemyXPos = 0.0f;
    float enemyYPos = 400.f;
    float enemy2XPos = 10.0f;
    float enemy2YPos = 600.f;
    int counter = 0;

    while (window.isOpen()){
        int randomNum = rand();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                std::cout << "Event window handled" << std::endl;
            }
            if (event.type == sf::Event::KeyPressed) {
                cout << "Button is pressed " << endl;

                //for testing cordinates
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                    character.getPosition();
                    gameFont.setString("P");
                }

                // closing the window when user presses escape
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) & wKeyReleased & (character.getPosition().y > 0)) {
                    cout << "Moving Up " << endl;
                    gameFont.setString("W");
                    character.getSprite()->move(0.0f, -121.0f);
                    wKeyReleased = false;
                    enemy1.randomEnemyMove(randomNum);
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) & aKeyReleased & (character.getPosition().x > 8)){
                    cout << "Moving left" << endl;
                    gameFont.setString("A");
                    character.getSprite()->move(-133, 0.0f);
                    aKeyReleased = false;
                    enemy1.randomEnemyMove(randomNum);
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) & sKeyReleased & (character.getPosition().y < 484)) {
                    cout << "Moving Down" << endl;
                    gameFont.setString("S");
                    character.getSprite()->move(0.0f, 121.0f);
                    sKeyReleased = false;
                    enemy1.randomEnemyMove(randomNum);
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) & dKeyReleased & (character.getPosition().x < 673)) {
                    cout << "Moving right" << endl;
                    gameFont.setString("D");
                    character.getSprite()->move(133, 0.0f);
                    dKeyReleased = false;
                    enemy1.randomEnemyMove(randomNum);
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                cout << "Button released " << endl;
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    wKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    aKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    sKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    dKeyReleased = true;
                }
            }
        }

        window.clear();

        // drawing the background
        window.draw(background_sprite.getSprite());

        // Knight sprite
        window.draw(*character.getSprite());

        // sprite sprite
        window.draw(enemy1.getSprite());
        window.draw(enemy2.getSprite());
        counter++;

        // this is the font
        window.draw(gameFont.getText());

        window.display();
    }
    return 0;
}
