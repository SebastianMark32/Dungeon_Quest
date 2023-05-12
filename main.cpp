#include "Dependencies.h"
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
bool pause = false;
bool game_menu_toggle = true;
bool win = false;

// making a lives system
static int lives = 3;

sf::RenderWindow window(sf::VideoMode(VIEW_WITDH, VIEW_HEIGHT), "Dungeon Quest!", sf::Style::Resize | sf::Style::Close);
sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
sf::RectangleShape game_pause;
sf::RectangleShape game_menu;
sf::RectangleShape game_win_lose_menu;

sf::Event event;
sf::Text scoreText;
sf::Font scoreFont;
sf::Text pause_screen_text;

// for the lives
sf::Text number_of_lives_text;

// when the game starts
sf::Text game_menu_text;
// when the player dies
sf::Text game_win_lose_text;

Music gameMusic("../Assets/VillageConsort-KevinMacLeod.ogg");
Character character("../Assets/Character_animation/Knight.png", sf::IntRect( 0, 0, 16, 16), "../Assets/step.wav");
Enemy enemy1("../Assets/Character_animation/Vampire.png", sf::IntRect(0, 0, 16, 16));
Enemy enemy2("../Assets/Character_animation/FlyingSkull.png", sf::IntRect(0, 0, 16, 16));
Enemy enemy3("../Assets/Character_animation/FlyingSkull.png", sf::IntRect(0, 0, 16, 16));

Sound hurtSound("../Assets/EnemyDie.wav");
Sound lostScoreSound("../Assets/lostScore.wav");
Animation enemy1Animation(*enemy1.getSprite());
Animation enemy2Animation(*enemy2.getSprite());
Animation enemy3Animation(*enemy3.getSprite());
Animation characterAnimation(*character.getSprite());

Level level("../Assets/Dungeon_Tileset.png");
Fireball playerFireball("../Assets/Fireball.png", "../Assets/FireballShoot.wav", "../Assets/FireHitWall.wav");
Animation fireballAnimation(*playerFireball.getSprite());


sf::Texture hero_menu_texture;
sf::Sprite hero_main_screen_sprite;

sf::Texture enemy1_menu_texture;
sf::Sprite enemy1_main_screen_sprite;

sf::Texture fireball_menu_texture;
sf::Sprite fireball_main_screen_sprite;

sf::Texture fireball_skull_menu_texture;
sf::Sprite fireball_skull_main_screen_sprite;

Fireball enemyFireBall1("../Assets/Fireball.png", "../Assets/FireballShoot.wav", "../Assets/FireHitWall.wav");
Fireball enemyFireBall2("../Assets/Fireball.png", "../Assets/FireballShoot.wav", "../Assets/FireHitWall.wav");
Fireball enemyFireBall3("../Assets/Fireball.png", "../Assets/FireballShoot.wav", "../Assets/FireHitWall.wav");
Fireball enemyFireBall4("../Assets/Fireball.png", "../Assets/FireballShoot.wav", "../Assets/FireHitWall.wav");
Animation enemyFireBall1Animation(*enemyFireBall1.getSprite());
Animation enemyFireBall2Animation(*enemyFireBall2.getSprite());
Animation enemyFireBall3Animation(*enemyFireBall3.getSprite());
Animation enemyFireBall4Animation(*enemyFireBall4.getSprite());


bool checkCollision(sf::Sprite* sprite1, sf::Sprite* sprite2){
    if (sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds())){
        return true;
    }
    return false;
}
void enemies_init(){
    enemy1.setPosition(1573.0f, 605.0f);
    enemy1.setScale(7.f, 7.f);
    enemy1.setCurrentTile(93);

    enemy2.set_Alive(false);
    enemy3.set_Alive(false);

    enemy1Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemy1Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemy1Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemy1Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemy2Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemy2Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemy2Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemy2Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemy3Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemy3Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemy3Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemy3Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemyFireBall1Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemyFireBall1Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemyFireBall1Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemyFireBall1Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemyFireBall1Animation.update(0.5);
    enemyFireBall1.getSprite()->setScale(7.5, 7.5);
    enemyFireBall2Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemyFireBall2Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemyFireBall2Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemyFireBall2Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemyFireBall2Animation.update(0.5);
    enemyFireBall2.getSprite()->setScale(7.5, 7.5);
    enemyFireBall3Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemyFireBall3Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemyFireBall3Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemyFireBall3Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemyFireBall3Animation.update(0.5);
    enemyFireBall3.getSprite()->setScale(7.5, 7.5);
    enemyFireBall4Animation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    enemyFireBall4Animation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    enemyFireBall4Animation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    enemyFireBall4Animation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    enemyFireBall4Animation.update(0.5);
    enemyFireBall4.getSprite()->setScale(7.5, 7.5);
}
void hero_attributes(){
    character.setScale(7.f, 7.f);
    character.setPosition(242.0f, 242.0f);
    character.setCurrentTile(34);
    characterAnimation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    characterAnimation.addFrame({sf::IntRect(48, 0, 16, 16), 3});

    fireballAnimation.addFrame({sf::IntRect(0, 0, 16, 16), 3});
    fireballAnimation.addFrame({sf::IntRect(16, 0, 16, 16), 3});
    fireballAnimation.addFrame({sf::IntRect(32, 0, 16, 16), 3});
    fireballAnimation.addFrame({sf::IntRect(48, 0, 16, 16), 3});
    fireballAnimation.update(0.5);  //work around to prevent an issue with global bounds being wrong when shooting fireball for first time.
}

void score_text(){
    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(860, 30);
}

void hero_lives(){
    number_of_lives_text.setFont(scoreFont);
    number_of_lives_text.setCharacterSize(50);
    number_of_lives_text.setFillColor(sf::Color::White);
    number_of_lives_text.setPosition(400,30);
}
void handel_close_event(){
    if (event.type == sf::Event::Closed) {
        window.close();
        std::cout << "Event window handled" << std::endl;
    }
}
void score_font(){
    scoreFont.loadFromFile("../Assets/Hack-Regular.ttf");
}

//code source: https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
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
    if (enemy1.isAlive() && checkCollision(character.getSprite(), enemy1.getSprite())){
        lives -=1;
        hurtSound.play();
    }
    if (enemy2.isAlive() && checkCollision(character.getSprite(), enemy2.getSprite())){
        lives -=1;
        hurtSound.play();
    }
    if (enemy3.isAlive() && checkCollision(character.getSprite(), enemy3.getSprite())){
        lives -=1;
        hurtSound.play();
    }
    if (enemyFireBall1.getIsAlive() && checkCollision(character.getSprite(), enemyFireBall1.getSprite())){
        lives -=1;
        hurtSound.play();
        enemyFireBall1.setIsAlive(false);
    }
    if (enemyFireBall2.getIsAlive() && checkCollision(character.getSprite(), enemyFireBall2.getSprite())){
        lives -=1;
        hurtSound.play();
        enemyFireBall2.setIsAlive(false);
    }
    if (enemyFireBall3.getIsAlive() && checkCollision(character.getSprite(), enemyFireBall3.getSprite())){
        lives -=1;
        hurtSound.play();
        enemyFireBall3.setIsAlive(false);
    }
    if (enemyFireBall4.getIsAlive() && checkCollision(character.getSprite(), enemyFireBall4.getSprite())){
        lives -=1;
        hurtSound.play();
        enemyFireBall4.setIsAlive(false);
    }

    if(enemy1.isAlive() && checkCollision(playerFireball.getSprite(), enemy1.getSprite())){
        score += 1;
        cout << "Enemy hit!" << endl;
        enemy1.set_Alive(false);
        enemy1.respawn(rand());
        //get the fireball off-screen to prevent it from hitting an enemy randomly during enemy respawn.
        playerFireball.setIsAlive(false);
        playerFireball.playFizzleSound();
        playerFireball.getSprite()->setPosition(-100, -100);
        hurtSound.play();
    }
    if(enemy2.isAlive() && checkCollision(playerFireball.getSprite(), enemy2.getSprite())){
        score += 1;
        cout << "Enemy hit!" << endl;
        enemy2.set_Alive(false);
        enemy2.respawn(rand());
        //get the fireball off-screen to prevent it from hitting an enemy randomly during enemy respawn.
        playerFireball.setIsAlive(false);
        playerFireball.playFizzleSound();
        playerFireball.getSprite()->setPosition(-100, -100);
        hurtSound.play();
    }
    if(enemy3.isAlive() && checkCollision(playerFireball.getSprite(), enemy3.getSprite())){
        score += 1;
        cout << "Enemy hit!" << endl;
        enemy3.set_Alive(false);
        enemy3.respawn(rand());
        //get the fireball off-screen to prevent it from hitting an enemy randomly during enemy respawn.
        playerFireball.setIsAlive(false);
        playerFireball.playFizzleSound();
        playerFireball.getSprite()->setPosition(-100, -100);
        hurtSound.play();
    }

    // logic for fireballs
    if(playerFireball.getIsAlive()){
       if(!level.isTileXWalkable(playerFireball.getCurrentTile())){
           playerFireball.setIsAlive(false);
        playerFireball.playFizzleSound();
       }
    }
    if(enemyFireBall1.getIsAlive()){
       if(!level.isTileXWalkable(enemyFireBall1.getCurrentTile())){
           enemyFireBall1.setIsAlive(false);
           enemyFireBall1.playFizzleSound();
       }
    }
    if(enemyFireBall2.getIsAlive()){
        if(!level.isTileXWalkable(enemyFireBall2.getCurrentTile())){
            enemyFireBall2.setIsAlive(false);
            enemyFireBall2.playFizzleSound();
        }
    }
    if(enemyFireBall3.getIsAlive()){
        if(!level.isTileXWalkable(enemyFireBall3.getCurrentTile())){
            enemyFireBall3.setIsAlive(false);
            enemyFireBall3.playFizzleSound();
        }
    }
    if(enemyFireBall4.getIsAlive()){
        if(!level.isTileXWalkable(enemyFireBall4.getCurrentTile())){
            enemyFireBall4.setIsAlive(false);
            enemyFireBall4.playFizzleSound();
        }
    }
}
void handle_levelChange(){

    if(score == 1 and level.getCurrentLevel() == 1) {
        level.nextLevel();\
        character.setPosition(242, 242);
        character.setCurrentTile(34);
        enemy1.setPosition(1573, 242);
        enemy1.setCurrentTile(45);
        enemy1.setSprite("../Assets/Character_animation/FlyingSkull.png");
        enemy1.set_Alive(true);
        enemy2.setPosition(242, 726);
        enemy2.setCurrentTile(98);
        enemy2.set_Alive(true);
        enemy2.setScale(7.5, 7.5);
        enemy3.setPosition(1573, 726);
        enemy3.setCurrentTile(109);
        enemy3.set_Alive(true);
        enemy3.setScale(7.5, 7.5);

    } if(score == 4 && level.getCurrentLevel() == 2){
        level.nextLevel();
        character.setPosition(242, 242);
        character.setCurrentTile(34);
        enemy1.setPosition(968, 363);
        enemy1.setCurrentTile(56);
        enemy1.setSprite("../Assets/Character_animation/SkellyWithScyth.png");
        enemy1.set_Alive(true);
        enemy2.setSprite("../Assets/Character_animation/SkellyWithSword.png");
        enemy2.setPosition(242, 726);
        enemy2.setCurrentTile(98);
        enemy2.set_Alive(true);
        enemy2.setScale(7.5, 7.5);
        enemy3.setSprite("../Assets/Character_animation/SkellyWithSword.png");
        enemy3.setPosition(1573, 726);
        enemy3.setCurrentTile(109);
        enemy3.set_Alive(true);
        enemy3.setScale(7.5, 7.5);

    }
    if(score == 7 && level.getCurrentLevel() == 3){
        level.nextLevel();
        character.setPosition(242, 484);
        character.setCurrentTile(66);
        enemy1.set_Alive(true);
        enemy1.setBoss(true);
        enemy1.setPosition(1573, 484);
        enemy1.setCurrentTile(77);
        enemy1.setSprite("../Assets/Character_animation/EvilKnight.png");
        gameMusic.changeMusic("../Assets/Death-and-Axes-KevinMacLeod.ogg");
    }
    if (score == 8){
        win = true;
    }
}

void shootEnemyFireballs(int rand){
    rand = rand % 5;
    if (rand == 0){
        if (!enemyFireBall1.getIsAlive()) {
            enemyFireBall1.shoot(1, enemy1.getCurrentTile() - 16, sf::Vector2f(enemy1.getSprite()->getPosition().x + enemyFireBall1.getSprite()->getGlobalBounds().width/2, enemy1.getSprite()->getPosition().y - 121 - enemyFireBall1.getSprite()->getGlobalBounds().height));
        }
        if (!enemyFireBall2.getIsAlive()) {
            enemyFireBall2.shoot(2, enemy1.getCurrentTile() + 16, sf::Vector2f(enemy1.getSprite()->getPosition().x  + enemyFireBall2.getSprite()->getGlobalBounds().width/2, enemy1.getSprite()->getPosition().y + 121  + enemyFireBall2.getSprite()->getGlobalBounds().height*2));
        }
        if (!enemyFireBall3.getIsAlive()) {
            enemyFireBall3.shoot(3, enemy1.getCurrentTile() - 1, sf::Vector2f(enemy1.getSprite()->getPosition().x - 121 - enemyFireBall3.getSprite()->getGlobalBounds().width, enemy1.getSprite()->getPosition().y  + enemyFireBall3.getSprite()->getGlobalBounds().height/2));
        }
        if (!enemyFireBall4.getIsAlive()) {
            enemyFireBall4.shoot(4, enemy1.getCurrentTile() + 1, sf::Vector2f(enemy1.getSprite()->getPosition().x + 121 + enemyFireBall4.getSprite()->getGlobalBounds().width*2, enemy1.getSprite()->getPosition().y  + enemyFireBall4.getSprite()->getGlobalBounds().height/2));

        }
    }
}

void pause_game();
void game_menu_window();
void close_game_menu();
void game_over_window();
void you_win_window();
int main() {
    window.setView(view);

   // scaling the map size for full screen
    level.getTilemap()->setScale(7.5f,7.5f);
    level.getTilemap()->setPosition(0,0);

    window.setFramerateLimit(144);
    window.setView(view);
    //Create random number
    srand((int) time(0));
    sf::Clock clock;

    playerFireball.getSprite()->setScale(7.5, 7.5);
    playerFireball.getSprite()->setPosition(-100, -100);

    hero_attributes();
    enemies_init();
    score_text();
    score_font();
    game_menu_window();
    gameMusic.setVolume(50);

    // testing hero lives
    hero_lives();

    while (window.isOpen()) {

        if(lives == 0){
            endGame = true;
        }
        while (window.pollEvent(event)) {
//            handel_close_event();

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
        number_of_lives_text.setString("Lives " + to_string(lives));
        window.clear();
        window.setView(view);
        window.draw(*level.getTilemap());

        // Knight sprite
        characterAnimation.update(0.1);
        window.draw(*character.getSprite());

        // enemy sprite
        if(enemy1.isAlive()){
            enemy1Animation.update(0.1);
            window.draw(*enemy1.getSprite());
        }
        if(enemy2.isAlive()){
            enemy2Animation.update(0.2);
            window.draw(*enemy2.getSprite());
        }
        if(enemy3.isAlive()){
            enemy3Animation.update(0.22);
            window.draw(*enemy3.getSprite());
        }

        if (enemyFireBall1.getIsAlive()){
            enemyFireBall1Animation.update(0.3);
            window.draw(*enemyFireBall1.getSprite());
        }
        if (enemyFireBall2.getIsAlive()){
            enemyFireBall2Animation.update(0.27);
            window.draw(*enemyFireBall2.getSprite());
        }
        if (enemyFireBall3.getIsAlive()){
            enemyFireBall3Animation.update(0.29);
            window.draw(*enemyFireBall3.getSprite());
        }
        if (enemyFireBall4.getIsAlive()){
            enemyFireBall4Animation.update(0.28);
            window.draw(*enemyFireBall4.getSprite());
        }

        // this is to display the fireball
        if (playerFireball.getIsAlive()) {
            fireballAnimation.update(0.3);
            window.draw(*playerFireball.getSprite());
        }

        // drawing the score
        window.draw(scoreText);
        window.draw(number_of_lives_text);
        if(pause){
            window.draw(game_pause);
            window.draw(pause_screen_text);

        }
        if(game_menu_toggle){
            window.draw(game_menu);
            window.draw(game_menu_text);
            window.draw(hero_main_screen_sprite);
            window.draw(enemy1_main_screen_sprite);
            window.draw(fireball_main_screen_sprite);
            window.draw(fireball_skull_main_screen_sprite);

        }

        if (endGame == true){
            cout << "You died. GAME OVER.";
            game_over_window();
            window.draw(game_win_lose_menu);
            window.draw(game_win_lose_text);
            window.display();
            sf::sleep(sf::milliseconds(5000));
            window.close();
        }
        if (win){
            cout << "You win!\n";
            you_win_window();
            window.draw(game_win_lose_menu);
            window.draw(game_win_lose_text);
            window.display();
            sf::sleep(sf::milliseconds(5000));
            window.close();
        }

        window.display();
    }
    return 0;
}
void handle_userInput(){
    bool playerMoved = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        pause_game();
        pause = true;
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !playerFireball.getIsAlive()){
        playerFireball.shoot(1, character.getCurrentTile() - 16, sf::Vector2f(character.getPosition().x + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y - 121 - playerFireball.getSprite()->getGlobalBounds().height));
        playerMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !playerFireball.getIsAlive()){
        playerFireball.shoot(2, character.getCurrentTile() + 16, sf::Vector2f(character.getPosition().x  + playerFireball.getSprite()->getGlobalBounds().width/2, character.getPosition().y + 121  + playerFireball.getSprite()->getGlobalBounds().height*2));
        playerMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !playerFireball.getIsAlive()){
        playerFireball.shoot(3, character.getCurrentTile() - 1, sf::Vector2f(character.getPosition().x - 121 - playerFireball.getSprite()->getGlobalBounds().width, character.getPosition().y  + playerFireball.getSprite()->getGlobalBounds().height/2));
        playerMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !playerFireball.getIsAlive()){
        playerFireball.shoot(4, character.getCurrentTile() + 1, sf::Vector2f(character.getPosition().x + 121 + playerFireball.getSprite()->getGlobalBounds().width*2, character.getPosition().y  + playerFireball.getSprite()->getGlobalBounds().height/2));
        playerMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && wKeyReleased && (level.isTileXWalkable(character.getCurrentTile() - 16))) {
        character.move(0.0f, -121.0f);
        character.setCurrentTile(character.getCurrentTile() - 16);
        playerMoved = true;
        wKeyReleased = false;
        playerFireball.move();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && aKeyReleased && (level.isTileXWalkable(character.getCurrentTile() - 1))) {
        character.move(-121, 0.0f);
        character.setCurrentTile(character.getCurrentTile() - 1);
        playerMoved = true;
        aKeyReleased = false;
        playerFireball.move();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && sKeyReleased && (level.isTileXWalkable(character.getCurrentTile() + 16))) {
        character.move(0.0f, 121.0f);
        character.setCurrentTile(character.getCurrentTile() + 16);
        playerMoved = true;
        sKeyReleased = false;
        playerFireball.move();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && dKeyReleased && (level.isTileXWalkable(character.getCurrentTile() + 1))) {
        character.move(121, 0.0f);
        character.setCurrentTile(character.getCurrentTile() + 1);
        playerMoved = true;
        dKeyReleased = false;
        playerFireball.move();
    }

    if (playerMoved){
        enemy1.randomEnemyMove(rand(), &level);
        enemy2.randomEnemyMove(rand(), &level);
        enemy3.randomEnemyMove(rand(), &level);
        if (enemyFireBall1.getIsAlive()){
            enemyFireBall1.move();
        }
        if (enemyFireBall2.getIsAlive()){
            enemyFireBall2.move();
        }
        if (enemyFireBall3.getIsAlive()){
            enemyFireBall3.move();
        }
        if (enemyFireBall4.getIsAlive()){
            enemyFireBall4.move();
        }
        if (enemy1.isAlive() && enemy1.getBoss()){
            shootEnemyFireballs(rand());
        }
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
        game_menu_toggle = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
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

    game_menu_text.setFont(scoreFont);
    game_menu_text.setCharacterSize(35);
    game_menu_text.setPosition(170, 30);


    hero_menu_texture.loadFromFile("../Assets/Knight_Game_Menu.png");

    hero_main_screen_sprite.setTexture(hero_menu_texture);
    hero_main_screen_sprite.setScale(7.f, 7.f);
    hero_main_screen_sprite.setPosition(150, 900);

    enemy1_menu_texture.loadFromFile("../Assets/Vampire_Game_Menu.png");

    enemy1_main_screen_sprite.setTexture(enemy1_menu_texture);
    enemy1_main_screen_sprite.setScale(7.f, 7.f);
    enemy1_main_screen_sprite.setPosition(430, 900);

    fireball_menu_texture.loadFromFile("../Assets/fire.png");

    fireball_main_screen_sprite.setTexture(fireball_menu_texture);
    fireball_main_screen_sprite.setScale(7.f, 7.f);
    fireball_main_screen_sprite.setPosition(1050, 900);

    fireball_skull_menu_texture.loadFromFile("../Assets/FlyingSkull_Game_Menu.png");

    fireball_skull_main_screen_sprite.setTexture(fireball_skull_menu_texture);
    fireball_skull_main_screen_sprite.setScale(7.f, 7.f);
    fireball_skull_main_screen_sprite.setPosition(730, 910);



    game_menu_text.setString("Welcome to Dungeon Quest!\n\n"
                         "Here is how you play the game:\n\nTo move press W to go up, S to go down, A to go left, and D to go right\n\n"
                         "Press ESC to close the window at any time\n\n"
                         "The hero can shoot a fireball by pressing the arrow keys\n\n"
                         "You can only have 1 active fireball at a time\n\n"
                         "And kill the enemy/s to move onto the next level\n\n"
                         "You will start off with 3 lives, so use them wisely\n\n"
                         "Be careful as danger lurks behind these walls muhahahahah!!\n\n"
                         "Press the space bar to begin playing!\n\n"
                         "Hero\t\tEnemy\t\tEnemy 2\t\tFireball");

}
void game_over_window(){
    game_win_lose_menu.setSize(sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    game_win_lose_menu.setFillColor(sf::Color::Black);
    game_win_lose_menu.setOutlineThickness(5);

    game_win_lose_text.setFont(scoreFont);
    game_win_lose_text.setCharacterSize(100);
    game_win_lose_text.setFillColor(sf::Color::White);
    game_win_lose_text.setPosition(650, 400);

    game_win_lose_text.setString("GAME OVER");
}

void you_win_window(){
    game_win_lose_menu.setSize(sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    game_win_lose_menu.setFillColor(sf::Color::Black);
    game_win_lose_menu.setOutlineThickness(5);

    game_win_lose_text.setFont(scoreFont);
    game_win_lose_text.setCharacterSize(70);
    game_win_lose_text.setFillColor(sf::Color::White);
    game_win_lose_text.setPosition(150, 400);

    game_win_lose_text.setString("YOU WIN, YOU HAVE RID THE WORLD OF EVIL!");
}