#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;

int main() {

    bool mouseReleased = false;

    // this is rendering a window which displays the viewer window
    sf::RenderWindow window(sf::VideoMode(1024, 780), "Sebastian SFML!");

    // font style
    sf::Font font;
    if (!font.loadFromFile("../Assets/ArianaVioleta-dz2K.ttf")) {
        cout << "Hello there! " << endl;
    }

    // game font
    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(70);
    text1.setStyle(sf::Text::Regular);
    text1.setString("Welcome to our game!");
    text1.setPosition(350.f, 10.0f);

    // hero sprite
    sf::Texture texture;
    texture.loadFromFile("../Assets/Knight3Walk.png");
    sf::Sprite character;
    character.setTexture(texture);
    character.setScale(0.5f, 0.5f);
    character.setPosition(300.f, 200.0f);

    // this is background
    sf::Texture texture2;
    texture2.loadFromFile("../Assets/Game_Background.png");
    sf::Sprite background_sprite(texture2);
    background_sprite.setScale(sf::Vector2f(3, 4.5));
    // enemy sprite
    sf::Texture texture1;
    texture1.loadFromFile("../Assets/Enemy.png");
    sf::Sprite enemy;
    enemy.setTexture(texture1);
    enemy.setScale(2.5f, 2.5f);
    enemy.setPosition(500.0f, 400.0f);

    window.setFramerateLimit(144);

    float xpos = 0.0f;
    float ypos = 0.0f;
    float enemyXPos = 0.0f;
    float enemyYPos = 400.f;
    int counter = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Event window handled" << std::endl;
                //exit();
            }
            if (event.type == sf::Event::KeyPressed) {
                cout << "Button is pressed " << endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    cout << "A key pressed " << endl;
                    text1.setString("A");
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    cout << "R key pressed " << endl;
                    text1.setString("R");
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                cout << "Mouse button pressed " << endl;
            }
            mouseReleased = false;
            if (event.type == sf::Event::MouseButtonReleased) {
                mouseReleased = true;
            }
            if (event.type == sf::Event::KeyReleased) {
                cout << "Button released " << endl;
            }
        }

        character.setPosition(xpos, ypos);
        if (counter >= 100) {
            ypos += 2;
        }
        xpos++;
        //ypos += 0.001;
        if (xpos > 100 && ypos > 100) {
            xpos = 0;
            ypos = 0;
            counter = 0;
        }

        // counting the frames
        //cout << counter << endl;

        // this is the enemy movement
        enemy.setPosition(enemyXPos, enemyYPos);
        if (counter >= 100) {
            enemyYPos += 2;
        }
        enemyXPos++;

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
        window.draw(background_sprite);

        // Knight character
        window.draw(character);

        // enemy character
        window.draw(enemy);
        counter++;

        // this is the font
        window.draw(text1);

        window.display();
    }

    return 0;
}
