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
    gameFont.setPosition(350.f, 10.0f);


    Character character("../Assets/Knight3Walk.png");
    character.setScale(0.5f, 0.5f);
    character.setPosition(300.f, 200.0f);


//    sf::Texture texture;
//    texture.loadFromFile("../Assets/Knight3Walk.png");
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//    sprite.setScale(0.5f, 0.5f);
//    sprite.setPosition(300.f, 200.0f);


    // this is background
    Background background_sprite("../Assets/Background_1080p.png");

    background_sprite.setScale(2.0f, 2.0f);
    // sprite sprite
    Enemy enemy1("../Assets/Enemy.png");
    //enemy1.setScale(0.5f, 1.5f);
    enemy1.setPosition(500.0f, 400.0f);

    Enemy enemy2("../Assets/images.png");
    enemy2.setPosition(600.f, 800.f);

//    sf::Texture texture1;
//    texture1.loadFromFile("../Assets/Enemy.png");
//    sf::Sprite enemy;
//    enemy.setTexture(texture1);
//    enemy.setScale(2.5f, 2.5f);
//    enemy.setPosition(500.0f, 400.0f);

    // Music
    Music gameMusic("");

    window.setVerticalSyncEnabled(true);

    float xpos = 0.0f;
    float ypos = 0.0f;
    float enemyXPos = 0.0f;
    float enemyYPos = 400.f;
    int counter = 0;
    float enemy2XPos = 10.0f;
    float enemy2YPos = 600.f;

    while (window.isOpen()) {
        sf::Event event;


        /***********NEW CODE**************
        // adding a new function here
        updateInput();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
       *********************************/

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
                    character.getSprite()->move(-2.0f, 0.0f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    cout << "Moving right" << endl;
                    gameFont.setString("D");

                    character.getSprite()->move(2.0f, 0.0f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    cout << "Moving Down" << endl;
                    gameFont.setString("S");
                    character.getSprite()->move(0.0f, 2.0f);
                }
            }
//            if (event.type == sf::Event::MouseButtonPressed) {
//                cout << "Mouse button pressed " << endl;
//            }
//            mouseReleased = false;
//            if (event.type == sf::Event::MouseButtonReleased) {
//                mouseReleased = true;
//            }
            if (event.type == sf::Event::KeyReleased) {
                cout << "Button released " << endl;
            }
        }

//        character.setPosition(xpos, ypos);
//        if (counter >= 100) {
//            ypos += 2;
//        }
//        xpos++;
//        //ypos += 0.001;
//        if (xpos > 100 && ypos > 100) {
//            xpos = 0;
//            ypos = 0;
//            counter = 0;
//        }

        // counting the frames
        //cout << counter << endl;


        // One direction

        // Moving right

        // this is the sprite movement
        enemy1.setPosition(enemyXPos, enemyYPos);
        if (counter >= 100) {
            enemyYPos += 2;
        }
        enemyXPos++;

        if (enemyXPos > 400 && enemyYPos > 200) {
            enemyXPos = 0;
            enemyYPos = 100.0f;
            counter = 0;
        }

        if (enemy2XPos > 400 && enemy2YPos > 200) {
            enemy2XPos = 0;
            enemy2YPos = 100.0f;
            counter = 0;
        }

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
