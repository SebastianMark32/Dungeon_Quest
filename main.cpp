#include "Dependencies.h"

static int score = 0;
// this is rendering a window which displays the viewer window
sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon Quest!", sf::Style::Resize);

// global vector
sf::Vector2f playerPosition;


int main() {

    //initialize score
    //Create random number
    srand((int) time(0));
    sf::Clock clock;

    int damage = 10;
    int health = 100;
    //int to get random number from
    int randomNum;
    //player control logic
    bool wKeyReleased = true;
    bool aKeyReleased = true;
    bool sKeyReleased = true;
    bool dKeyReleased = true;
    sf::Event event;


    sf::Text scoreText;
    sf::Font scoreFont;
    scoreFont.loadFromFile("../Assets/ArianaVioleta-dz2K.ttf");

    scoreText.setFont(scoreFont);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(window.getSize().x/2 - scoreText.getLocalBounds().width/2, 60);

    // game font
    Fonts gameFont("../Assets/ArianaVioleta-dz2K.ttf");
    gameFont.setSize(70);
    gameFont.setStyle(sf::Text::Regular);
    gameFont.setString("Welcome to our game!");
    gameFont.setPosition(250.f, 10.0f);

    //player character
    Character character("../Assets/Knight3Walk.png");
    character.setScale(0.93f, 0.93f);
    character.setPosition(8.0f, 0.0f);

    //Character::hero = *character.getSprite(); // this is the sprite

    // this is background
    Background background_sprite("../Assets/background800x600.png");

    // sprite sprite
    Enemy enemy1("../Assets/Enemy.png");
    //enemy1.setScale(0.5f, 1.5f);
    enemy1.setPosition(673.0f, 484.0f);
    enemy1.setScale(0.93f, 0.93f);

    // second enemy
    Enemy enemy2("../Assets/monster.png");
    enemy2.setPosition(300.0f, 484.0f);
    enemy2.setScale(0.4f, 0.4f);

    // Music
    //Music gameMusic("../Assets/A01_B.ogg");
    window.setVerticalSyncEnabled(true);

    //walk sound effect
    Sound walkSound("../Assets/step.wav");

    int counter = 0;

    while (window.isOpen()) {
        int randomNum = rand();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Event window handled" << std::endl;
            }
            if (event.type == sf::Event::KeyPressed) {
                //cout << "Button is pressed " << endl;

                //for testing coordinates
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    cout << character.getPosition().x << " " << character.getPosition().y << endl;
                    gameFont.setString("P");
                }

                // closing the window when user presses escape
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && wKeyReleased && (character.getPosition().y > 0)) {
                    //cout << "Moving Up " << endl;
                    gameFont.setString("W");
                    character.getSprite()->move(0.0f, -121.0f);
                    wKeyReleased = false;
                    enemy1.randomEnemyMove(rand());
                    enemy2.randomEnemyMove(rand());
                    walkSound.Play();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && aKeyReleased && (character.getPosition().x > 8)) {
                    //cout << "Moving left" << endl;
                    gameFont.setString("A");
                    character.getSprite()->move(-133, 0.0f);
                    aKeyReleased = false;
                    enemy1.randomEnemyMove(rand());
                    enemy2.randomEnemyMove(rand());
                    walkSound.Play();
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && sKeyReleased &&
                    (character.getPosition().y < 484)) {
                    //cout << "Moving Down" << endl;
                    gameFont.setString("S");
                    character.getSprite()->move(0.0f, 121.0f);
                    sKeyReleased = false;
                    enemy1.randomEnemyMove(rand());
                    enemy2.randomEnemyMove(rand());
                    walkSound.Play();
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && dKeyReleased &&
                    (character.getPosition().x < 673)) {
                    //cout << "Moving right" << endl;
                    gameFont.setString("D");
                    character.getSprite()->move(133, 0.0f);
                    dKeyReleased = false;
                    enemy1.randomEnemyMove(randomNum);
                    enemy2.randomEnemyMove(randomNum);
                    walkSound.Play();
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                //cout << "Button released " << endl;
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    wKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    aKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    sKeyReleased = true;
                }
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    dKeyReleased = true;
                }
            }
        }

        // collision
        if (character.getSprite()->getGlobalBounds().intersects(enemy2.getSprite().getGlobalBounds()) ||
            character.getSprite()->getGlobalBounds().intersects(enemy1.getSprite().getGlobalBounds())) {

            cout << "Hello enemy!" << endl;

        }

        window.clear();

        // drawing the background
        window.draw(background_sprite.getSprite());

        // Knight sprite
        window.draw(*character.getSprite());

        // enemy sprite
        window.draw(enemy1.getSprite());
        window.draw(enemy2.getSprite());
        counter++;

        // font
        window.draw(gameFont.getText());

        // drawing the score
        window.draw(scoreText);

        window.display();
    }
    return 0;
}
