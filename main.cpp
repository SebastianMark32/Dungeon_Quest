#include "Dependencies.h"
static int score = 0;
static const float VIEW_WITDH = 1920.f;
static const float VIEW_HEIGHT = 1080.f;

bool wKeyReleased = true;
bool aKeyReleased = true;
bool sKeyReleased = true;
bool dKeyReleased = true;
bool endGame = false;
int randomNum;

// this is rendering a window which displays the viewer window
//sf::RenderWindow window(sf::VideoMode(VIEW_WITDH, VIEW_HEIGHT), "Dungeon Quest!", sf::Style::Resize | sf::Style::Close);
sf::RenderWindow window(sf::VideoMode(VIEW_WITDH, VIEW_HEIGHT), "Dungeon Quest!", sf::Style::Resize | sf::Style::Close);
sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
sf::Vector2f playerPosition;
sf::Event event;
sf::Text scoreText;
sf::Font scoreFont;

Sound walkSound("../Assets/step.wav");
Music gameMusic("../Assets/VillageConsort-KevinMacLeod.ogg");
Background background_sprite("../Assets/background800x600.png");
Character character("../Assets/Knight3Walk.png");
Enemy chest("../Assets/Chest.png");
Enemy enemy1("../Assets/Enemy.png");
Sound scoreSound("../Assets/Score.wav");
Sound lostScoreSound("../Assets/lostScore.wav");

bool checkCollision(sf::Sprite* sprite1, sf::Sprite* sprite2){
    if (sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds())){
        return true;
    }
    return false;
}
void music_attributes(){
    gameMusic.setVolume(50);
}
void enemy_attributes(){
    chest.setPosition(274.0f, 484.0f);
    chest.setScale(0.93f, 0.93f);
}
void walk_attributes(){
    walkSound.getSound().setVolume(50);
    //score sound effect
    scoreSound.getSound().setVolume(50);
}
void enemy_one(){
    enemy1.setPosition(673.0f, 484.0f);
    enemy1.setScale(0.93f, 0.93f);
}
void hero_attributes(){
    character.setScale(0.93f, 0.93f);
    character.setPosition(968.0f, 605.0f);
}
void chest_object(){
    chest.setPosition(363.0f, 484.0f);
    chest.setScale(0.93f, 0.93f);
}
void sound_score(){
    scoreSound.getSound().setVolume(50);
}
void lost_score(){
    lostScoreSound.getSound().setVolume(50);
}
void score_text(){
    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(0, 0);
}
void close_window(){
    if (event.type == sf::Event::Closed) {
        window.close();
        std::cout << "Event window handled" << std::endl;
    }
}
void score_font(){
    scoreFont.loadFromFile("../Assets/Hack-Regular.ttf");
}
void resize_window(){
    if (event.type == sf::Event::Resized){
        float windowRatio = event.size.width / (float) event.size.height;
        float viewRatio = view.getSize().x / (float) view.getSize().y;
        float sizeX = 1;
        float sizeY = 1;
        float posX = 0;
        float posY = 0;

        bool horizontalSpacing = true;
        if (windowRatio < viewRatio)
            horizontalSpacing = false;

        // If horizontalSpacing is true, the black bars will appear on the left and right side.
        // Otherwise, the black bars will appear on the top and bottom.
        if (horizontalSpacing) {
            sizeX = viewRatio / windowRatio;
            posX = (1 - sizeX) / 2.f;
        }
        else {
            sizeY = windowRatio / viewRatio;
            posY = (1 - sizeY) / 2.f;
        }
        view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );
    }
}
void update_KeyRelease(){
    if (event.type == sf::Event::KeyReleased) {
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
void keyPressed_functions(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        cout << character.getPosition().x << " " << character.getPosition().y << endl;
    }
    // closing the window when user presses escape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }
}
void character_collision(){
    if (checkCollision(enemy1.getSprite(), chest.getSprite())){
        score -= 1;
        cout << "Oh no! the enemy stole you treasure!\n";
        chest.respawn(rand());
        lostScoreSound.Play();
    }
}
void character_movement();

int main() {

//    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
//    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    // define the level with an array of tile indices
    window.setView(view);

    const int level[] = {
                    // #78 is a black tile
                    78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
                    78, 0, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 5, 78,
                    78, 10, 11, 12, 13, 12, 12, 13, 12, 13, 13, 12, 13, 14, 15, 78,
                    78, 20, 21, 6, 7, 8, 9, 7, 8, 9, 17, 16, 9, 24, 25, 78,
                    78, 30, 21, 16, 17, 27, 28, 29, 18, 17, 7, 6, 7, 24, 35, 78,
                    78, 10, 21, 26, 27, 7, 6, 18, 19, 9, 26, 28, 18, 24, 25, 78,
                    78, 20, 31, 32, 33, 33, 32, 33, 32, 33, 32, 32, 33, 34, 35, 78,
                    78, 40, 41, 42, 43, 41, 42, 43, 44, 41, 42, 43, 44, 41, 45, 78,
                    78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,

            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("../Assets/Dungeon_Tileset.png", sf::Vector2u(16, 16), level, 16, 9))
        return -1;

   // scaling the map size for full screen
    map.setScale(7.5f,7.5f);
    map.setPosition(0,0);

    window.setVerticalSyncEnabled(true);
    window.setView(view);
    //Create random number
    srand((int) time(0));
    sf::Clock clock;

    chest_object();
    hero_attributes();
    enemy_attributes();
    enemy_one();
    music_attributes();
    walk_attributes();
    sound_score();
    score_text();
    lost_score();
    score_font();

    int counter = 0;
    while (window.isOpen()) {
        int randomNum = rand();
        while (window.pollEvent(event)) {
            close_window();

            //Code gotten from SFML wiki https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
            resize_window();

            if (event.type == sf::Event::KeyPressed) {
                keyPressed_functions();
                character_movement();
            }
            update_KeyRelease();
        }
        character_collision();
        scoreText.setString("Score: " + to_string(score));
        window.clear();
        window.setView(view);
        window.draw(map);


        // drawing the background
       // window.draw(background_sprite.getSprite());

        // Knight sprite
        window.draw(*character.getSprite());

        // enemy sprite
        window.draw(*enemy1.getSprite());
        window.draw(*chest.getSprite());
        counter++;
        // drawing the score
        window.draw(scoreText);

        window.display();

        if (endGame == true){
            cout << "You died. GAME OVER.";
            window.close();}
        }
    return 0;
}

void character_movement(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && wKeyReleased && (character.getPosition().y > 242)) {
        character.getSprite()->move(0.0f, -121.0f);
        wKeyReleased = false;
        enemy1.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), enemy1.getSprite())){
            endGame = true;
        }
        chest.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), chest.getSprite())){
            chest.respawn(rand());
            scoreSound.Play();
            score += 1;
        }
        walkSound.Play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && aKeyReleased && (character.getPosition().x > 242)) {
        character.getSprite()->move(-121, 0.0f);
        aKeyReleased = false;
        enemy1.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), enemy1.getSprite())){
            endGame = true;
        }
        chest.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), chest.getSprite())){
            chest.respawn(rand());
            scoreSound.Play();
            score += 1;
        }
        walkSound.Play();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && sKeyReleased &&
        (character.getPosition().y < 700)) {
        character.getSprite()->move(0.0f, 121.0f);
        sKeyReleased = false;
        enemy1.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), enemy1.getSprite())){
            endGame = true;
        }
        chest.randomEnemyMove(rand());
        if (checkCollision(character.getSprite(), chest.getSprite())){
            chest.respawn(rand());
            scoreSound.Play();
            score += 1;
        }
        walkSound.Play();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && dKeyReleased &&
        (character.getPosition().x < 1500)) {
        character.getSprite()->move(121, 0.0f);
        dKeyReleased = false;
        enemy1.randomEnemyMove(randomNum);
        if (checkCollision(character.getSprite(), enemy1.getSprite())){
            endGame = true;
        }
        chest.randomEnemyMove(randomNum);
        if (checkCollision(character.getSprite(), chest.getSprite())){
            chest.respawn(rand());
            scoreSound.Play();
            score += 1;
        }
        walkSound.Play();
    }
}

