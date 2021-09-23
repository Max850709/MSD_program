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
#include "user.hpp"

class Box{
public:
    //constructor destructor
    Box();
    ~Box();
    
    //Functions
    void update();
    void render();
    void pollEvent();
    void outputBox();
    void updateBox();
    void renderBox();
    void rendermybox();
    
    //mybox
    void updatemyBox();
    
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
    
    //Object
    sf::RectangleShape mybox; // initialized box that user can interact with
    sf::RectangleShape box;
    std::vector<sf::RectangleShape> boxes;
    
    //logic
    float boxtimer;
    float boxtimermax;
    int maxBox; //max box per time
    int points;
    
    //user
//    User* user;
    //user private function

    void initUser();
};


#endif /* box_hpp */
