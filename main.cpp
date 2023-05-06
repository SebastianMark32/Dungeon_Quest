#include "Dependencies.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

static int score = 0;
static const float VIEW_WITDH = 1920.f;
static const float VIEW_HEIGHT = 1080.f;

bool wKeyReleased = true;
bool aKeyReleased = true;
bool sKeyReleased = true;
bool dKeyReleased = true;
bool endGame = false;
bool isFireball = false; //is there already a fireball?
bool pause = false;
bool game_menu_toggle = true;

// this is rendering a window which displays the viewer window
//sf::RenderWindow window(sf::VideoMode(VIEW_WITDH, VIEW_HEIGHT), "Dungeon Quest!", sf::Style::Resize | sf::Style::Close);
sf::RenderWindow window(sf::VideoMode(VIEW_WITDH, VIEW_HEIGHT), "Dungeon Quest!", sf::Style::Resize | sf::Style::Close);
sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
sf::RectangleShape game_pause;
sf::RectangleShape game_menu;
sf::RectangleShape game_over;

sf::Event event;
sf::Text scoreText;
sf::Font scoreFont;
sf::Text pause_screen_text;

// when the game starts
sf::Text game_menu_text;
// when the player dies
sf::Text game_over_text;


Sound walkSound("../Assets/step.wav");
Music gameMusic("../Assets/VillageConsort-KevinMacLeod.ogg");
Character character("../Assets/Character_animation/Knight.png", sf::IntRect( 0, 0, 16, 16));
Enemy chest("../Assets/Chest.png");
Enemy enemy1("../Assets/Character_animation/Vampire.png", sf::IntRect(0, 0, 16, 16));
Sound scoreSound("../Assets/Score.wav");
Sound lostScoreSound("../Assets/lostScore.wav");
Animation vampireAnimation(*enemy1.getSprite());
Animation characterAnimation(*character.getSprite());
Level level;
Fireball playerFireball("../Assets/fire.png");


bool checkCollision(sf::Sprite* sprite1, sf::Sprite* sprite2){
    if (sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds())){
        return true;
    }
    return false;
}
void music_attributes(){
    gameMusic.setVolume(50);
}
void walk_attributes(){
    walkSound.getSound().setVolume(50);
    //score sound effect
    scoreSound.getSound().setVolume(50);
}
void enemy_one(){
    enemy1.setPosition(1573.0f, 605.0f);
    enemy1.setScale(7.f, 7.f);
    enemy1.setCurrentTile(93);
    vampireAnimation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    vampireAnimation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    vampireAnimation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    vampireAnimation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
}
void hero_attributes(){
    character.setScale(7.f, 7.f);
    character.setPosition(242.0f, 242.0f);
    character.setCurrentTile(34);
    characterAnimation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
}
void chest_object(){
    chest.setPosition(968.0f, 484.0f);
    chest.setScale(0.93f, 0.93f);
    chest.setCurrentTile(72);
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
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(860, 30);
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
        cout << character.getCurrentTile() << endl;
    }
    // closing the window when user presses escape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }
}

void handle_userInput();

void waitForUnpause();

void handle_collision(){
    if (checkCollision(character.getSprite(), enemy1.getSprite())){
        endGame = true;
    }
//    if (checkCollision(character.getSprite(), chest.getSprite())){
//        chest.respawn(rand());
//        scoreSound.Play();
//        score += 1;
//    }
//    if (checkCollision(enemy1.getSprite(), chest.getSprite())){
//        score -= 1;
//        cout << "Oh no! the enemy stole you treasure!\n";
//        chest.respawn(rand());
//        lostScoreSound.Play();
//    }
    if(checkCollision(playerFireball.getSprite(), enemy1.getSprite())){
        score += 1;
        cout << "Enemy hit!" << endl;
        enemy1.respawn(rand());
    }
    // logic for fireballs
    if(isFireball){
       if(!level.isTileXWalkable(playerFireball.getCurrentTile())){
        isFireball = false;
       }
    }
}
void handle_levelChange(){
    if(score == 3) {
        level.nextLevel();
        score +=1;

    } if(score == 7){
        level.nextLevel();

    }
    if(score == 14){
        cout << "You win!" << endl;
        window.close();
    }
}
void pause_game();
void game_menu_window();
void close_game_menu();
void game_over_window();
int main() {
    window.setView(view);

   // scaling the map size for full screen
    level.getTilemap()->setScale(7.5f,7.5f);
    level.getTilemap()->setPosition(0,0);

    window.setVerticalSyncEnabled(true);
    window.setView(view);
    //Create random number
    srand((int) time(0));
    sf::Clock clock;

    playerFireball.getSprite()->setScale(7.5, 7.5);
    playerFireball.getSprite()->setPosition(-100, -100);

    chest_object();
    hero_attributes();
    enemy_one();
    music_attributes();
    walk_attributes();
    sound_score();
    score_text();
    lost_score();
    score_font();
    game_menu_window();


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            close_window();

            //Code gotten from SFML wiki https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
            resize_window();
            if(event.type == sf::Event::KeyPressed && game_menu_toggle){

                close_game_menu();
            }
            else if (event.type == sf::Event::KeyPressed && pause == false) {
                keyPressed_functions();
                handle_userInput();
                handle_collision();
                }
            else if (event.type == sf::Event::KeyPressed && pause == true){
                waitForUnpause();
            }
            handle_levelChange();
        }
        update_KeyRelease();

        scoreText.setString("Score: " + to_string(score));
        window.clear();
        window.setView(view);
        window.draw(*level.getTilemap());

        // Knight sprite
        characterAnimation.update(0.1);
        window.draw(*character.getSprite());

        // enemy sprite
        vampireAnimation.update(0.1);

        // here is where we draw the chest
//        window.draw(*chest.getSprite());
        window.draw(*enemy1.getSprite());

        // this is to display the fireball
        if(isFireball) {
            window.draw(*playerFireball.getSprite());
        }
        // drawing the score
        window.draw(scoreText);
        if(pause){
            window.draw(game_pause);
            window.draw(pause_screen_text);
        }
        if(game_menu_toggle){
            window.draw(game_menu);
            window.draw(game_menu_text);
        }
          window.draw(game_over);
          window.draw(game_over_text);
        window.display();

        if (endGame == true){
            cout << "You died. GAME OVER.";
          game_over_window();
          window.draw(game_over);
//          sf::sleep(sf::milliseconds(10000));
//          window.close();
        }
    }
    return 0;
}
void handle_userInput(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        pause_game();
        pause = true;
        return;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isFireball){
        playerFireball.shoot(1, character.getCurrentTile() - 16, sf::Vector2f(character.getPosition().x + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y - 121 + playerFireball.getSprite()->getGlobalBounds().height/2));
        isFireball = true;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isFireball){
        playerFireball.shoot(2, character.getCurrentTile() + 16, sf::Vector2f(character.getPosition().x  + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y + 121  + playerFireball.getSprite()->getGlobalBounds().height/2));
        isFireball = true;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isFireball){
        playerFireball.shoot(3, character.getCurrentTile() - 1, sf::Vector2f(character.getPosition().x - 121 + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y  + playerFireball.getSprite()->getGlobalBounds().height/2));
        isFireball = true;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isFireball){
        playerFireball.shoot(4, character.getCurrentTile() + 1, sf::Vector2f(character.getPosition().x + 121 + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y  + playerFireball.getSprite()->getGlobalBounds().height/2));
        isFireball = true;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && wKeyReleased && (level.isTileXWalkable(character.getCurrentTile() - 16))) {
        character.getSprite()->move(0.0f, -121.0f);
        character.setCurrentTile(character.getCurrentTile() - 16);
        wKeyReleased = false;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

        playerFireball.move();
        walkSound.Play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && aKeyReleased && (level.isTileXWalkable(character.getCurrentTile() - 1))) {
        character.getSprite()->move(-121, 0.0f);
        character.setCurrentTile(character.getCurrentTile() - 1);
        aKeyReleased = false;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

        playerFireball.move();
        walkSound.Play();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && sKeyReleased && (level.isTileXWalkable(character.getCurrentTile() + 16))) {
        character.getSprite()->move(0.0f, 121.0f);
        character.setCurrentTile(character.getCurrentTile() + 16);
        sKeyReleased = false;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

        playerFireball.move();
        walkSound.Play();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && dKeyReleased && (level.isTileXWalkable(character.getCurrentTile() + 1))) {
        character.getSprite()->move(121, 0.0f);
        character.setCurrentTile(character.getCurrentTile() + 1);
        dKeyReleased = false;
        enemy1.randomEnemyMove(rand(), &level);
        chest.randomEnemyMove(rand(), &level);

        playerFireball.move();
        walkSound.Play();
    }
}
void waitForUnpause(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        pause = false;
    }
}
// closing the start screen
void close_game_menu(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        pause = false;
        game_menu_toggle = false;
    }
}
void pause_game(){
    game_pause.setSize(sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    game_pause.setFillColor(sf::Color{105,108, 125, 50});
    game_pause.setOutlineColor(sf::Color::Transparent);
    game_pause.setOutlineThickness(5);
    pause_screen_text.setFont(scoreFont);
    pause_screen_text.setString(" GAME IS PAUSED!\nPRESS P TO UNPAUSE");
    pause_screen_text.setCharacterSize(40);
    pause_screen_text.setFillColor(sf::Color::White);
    pause_screen_text.setPosition(700,500);
}
void game_menu_window(){
    game_menu.setSize(sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    game_menu.setFillColor(sf::Color::Black);
    game_menu.setOutlineThickness(5);
    /**
     * We might want to update the font with old english
     **/
    game_menu_text.setFont(scoreFont);
    game_menu_text.setCharacterSize(20);
//    game_menu.setPosition(500,200);
    game_menu_text.setPosition(650, 300);

    /**
     * THIS IS NOT WORKING RIGHT NOW
     */
    fstream game_menu_file;
    game_menu_file.open("../Assets/text/game_menu.txt", fstream::in);
    string sentence;

    stringstream all_lines;
    while(getline(game_menu_file, sentence)){
       all_lines << sentence << '\n';
    }
//    game_menu_text.setString(all_lines.str().c_str());
// This works for a temp solution
game_menu_text.setString("Welcome to Dungeon Quest!\n\n"
                         "Here is how you play the game:\n\nTo move press wasd\n\n"
                         "To shoot fireballs press the arrow key\n\n"
                         "And kill the enemy/s to move onto the next level.\n\n"
                         "Be careful as danger lurks behind these walls muhahahahah!!\n\n"
                         "Press the space bar to begin playing!");
}
void game_over_window(){
    game_over.setSize(sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    game_over.setFillColor(sf::Color::Black);
    game_over.setOutlineThickness(5);
    /**
     * We might want to update the font with old english
     **/
    game_over_text.setFont(scoreFont);
    game_over_text.setCharacterSize(90);
    game_menu_text.setFillColor(sf::Color::White);
    game_over_text.setPosition(650, 400);

    /**
     * THIS IS NOT WORKING RIGHT NOW
     */

//    game_menu_text.setString(all_lines.str().c_str());
// This works for a temp solution
    game_over_text.setString("GAME OVER");
}