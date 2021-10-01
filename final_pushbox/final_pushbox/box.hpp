#pragma once
//  box.hpp
//  final_pushbox
//
//  Created by max on 9/21/21.
//

#ifndef box_hpp
#define box_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>

class Box{
public:
    //constructor destructor
    Box();
    ~Box();
    void pollEvent();
    //Accessors
    const bool& getEndGame() const;
    const bool& getWinegame()const;
    //Functions
    void update();
    void render();
    //Enimey-----
    void outputBox();
    void updateBox();
    void renderBox();
    //User------
    void rendermybox();
    void updatemyBox();
    void updateGUI();
    void renderGUI();
    //background----
    void initBackground();
    void renderBackground();
    
    
    void updateCombate();
    void updateCollision(); //make sure not out bound
    
    const bool windowisopen() const;
    
   
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videomode;
    
    //Private Functions
    void initVariables();
    void initWindows();
    void initbox();
    void initmybox();//
    void initGUI();//point
    void renderblowup(float a,float b);
    
    //Object
    sf::RectangleShape mybox; // initialized box that user can interact with
    sf::RectangleShape box;
    //std::vector<sf::RectangleShape> boxes;
    std::vector<sf::Sprite> boxes;
//    std::map<sf::Sprite, bool> boxes;
    //logic
    float boxtimer;
    float boxtimermax;
    int maxBox; //max box per time
    int points;
    bool endGame;//
    bool winGame;
    
    //User picture
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite sprite1;
    sf::Texture texture1;
    sf::Sprite blowsprite;
    sf::Texture blowtexture;
    
    
    void initSprite();
    void initTexture();
    
    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text endGameText;
    sf::Text winGameText;
    //background
    sf::Texture backroundTexture;
    sf::Sprite background;
    
    
    //user
//    User* user;
    //user private function

    void initUser();
};


#endif /* box_hpp */
