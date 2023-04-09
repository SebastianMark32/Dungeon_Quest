#include "Dependencies.h"

// boolean for mouse being pressed
bool mouseReleased = false;

// this is rendering a window which displays the viewer window
sf::RenderWindow window(sf::VideoMode(2560 , 1600), "Dungeon Quest!", sf::Style::Resize);

// global vector
sf:: Vector2f playerPosition;

bool playerMoving = false;

void updateInput(){
    sf::Event event;

    while(window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                playerMoving = true;
            }
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right) {
                playerMoving = false;
            }
        }

        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
void update(float dt){

    sf::Sprite hero;

    if(playerMoving){
        hero.move(50.0f*dt, 0);
    }
}
int main(){

    sf::Clock clock;

    // game font
    Fonts gameFont("../Assets/ArianaVioleta-dz2K.ttf");
    gameFont.setSize(200);
    gameFont.setStyle(sf::Text::Regular);
    gameFont.setString("Welcome to our game!");
    gameFont.setPosition(700.f, 5.0f);


    Character character("../Assets/Knight3Walk.png");
    character.setScale(0.5f, 0.5f);
    character.setPosition(1100.f, 500.0f);


    // this is background
    Background background_sprite("../Assets/Background_1080p.png");

    background_sprite.setScale(2.0f, 2.0f);
    // sprite sprite
    Enemy enemy1("../Assets/Enemy.png");
    //enemy1.setScale(0.5f, 1.5f);
    enemy1.setPosition(500.0f, 400.0f);

    Enemy enemy2("../Assets/images.png");
    enemy2.setPosition(600.f, 800.f);

    // Music
    Music gameMusic("");

    window.setVerticalSyncEnabled(true);

    float enemyXPos = 0.0f;
    float enemyYPos = 400.f;
    float enemy2XPos = 10.0f;
    float enemy2YPos = 600.f;
    int counter = 0;

    // speed
    float speedX = 0;
    //  movement speed for right and left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        speedX += 0.1f;
    }
    else{
        //if your speed is close to 0, stop
        if (abs(speedX) <= 0.2f){
            speedX = 0;
        }
        else{
            //decrease the speed
            speedX -= 0.2f;
        }
    }

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Event window handled" << std::endl;
            }
            if (event.type == sf::Event::KeyPressed) {
                cout << "Button is pressed " << endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    cout << "Moving Up " << endl;
                    gameFont.setString("W");
                    character.getSprite()->move(0.0f, -2.0f);
                }
                // closing the window when user presses escape
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    cout << "Moving left" << endl;
                    gameFont.setString("A");
                    character.getSprite()->move(-speedX, 0.0f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    cout << "Moving right" << endl;
                    gameFont.setString("D");

                    character.getSprite()->move(speedX, 0.0f);
                    speedX += 1.1f;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    cout << "Moving Down" << endl;
                    gameFont.setString("S");
                    character.getSprite()->move(0.0f, 2.0f);
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                cout << "Button released " << endl;
            }
        }

        // this is the sprite movement
        enemy1.setPosition(enemyXPos, enemyYPos);
        if (counter >= 100) {
            enemyYPos += 2;
        }
        enemyXPos++;

        enemy2.setPosition(enemy2XPos, enemy2YPos);
        if (counter >= 100) {
            enemy2YPos += 2;
        }
        enemy2XPos++;

        if (enemyXPos > 400 && enemyYPos > 200) {
            enemyXPos = 0;
            enemyYPos = 100.0f;
            counter = 0;
        }

        if (enemy2XPos > 700 && enemy2YPos > 400) {
            enemy2XPos = 0;
            enemy2YPos = 300.0f;
            counter = 0;
        }

        // static member function
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseReleased) {
            cout << "Left mouse button pressed " << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            cout << "Q key pressed" << endl;
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
