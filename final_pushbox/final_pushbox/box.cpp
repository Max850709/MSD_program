//
//  box.cpp
//  final_pushbox
//
//  Created by max on 9/21/21.
//

#include "box.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include <iostream>
#include <ctime>

//Private functions

void Box::initVariables(){
    this->window=nullptr;
    
    //logic
    this->boxtimer=this->boxtimermax;
    this->boxtimermax=30.f;
    this->maxBox=15;
    this->points=5;
}

void Box::initWindows(){
    this->videomode.height=1200;
    this->videomode.width=1000;
    this->window=new sf::RenderWindow(this->videomode, "My window");
    this->window->setFramerateLimit(60); //60 FPS
}

const bool Box::windowisopen() const{
    return (this->window->isOpen());
}

//box constructor
Box::Box(){
    this->initVariables();
    this->initWindows();
    this->initbox();
    this->initmybox();
    this->renderBox();
    this->initGUI();
//    this->updateCombate();
    this->initBackground();
    //this->initTexture();
//    this->initUser();
}

Box::~Box(){
    delete this->window;
//    delete this->user;
}

//Functions
void Box::pollEvent(){
    while(this->window->pollEvent(this->ev)){
        if (this->ev.type == sf::Event::Closed) {
          this->window->close();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->window->close();
        }
        
        //User control
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                this->sprite.move(-40.f, 0.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                this->sprite.move(40.f, 0.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                this->sprite.move(0.f, -40.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                this->sprite.move(0.f, 40.f);
            }
    }
}

//Obstacles box----------------------------------------------------------------------------------------
void Box::initbox(){
    this->texture1.loadFromFile("box.png");
    this->sprite1.setTexture(texture1);
    this->sprite1.setPosition(500,500);
    this->sprite1.scale(0.5, 0.5);
    
//    this->box.setPosition(0,0);
//    this->box.setSize(sf::Vector2f(80.f,80.f));
//    this->box.setFillColor(sf::Color::Blue);
//    this->box.setOutlineColor(sf::Color::Green);
//    this->box.setOutlineThickness(1.f);
    
}

//create box vector
void Box::outputBox(){
    this->sprite1.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->sprite1.getScale().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y-900 - this->sprite1.getScale().y))
    );
    
    //this->box.setFillColor(sf::Color::Green);
    
    //spawn boxes
    this->boxes.push_back(this->sprite1);
    
}

//box update
void Box::updateBox(){
    //update the timer for ouputing box
    if(this->boxes.size()<this->maxBox){
        if(this->boxtimer>=this->boxtimermax){
            //output box and reset timer
            this->outputBox();
            this->boxtimer=0.f;
        }
        else{
            this->boxtimer+=1.f;
        }
    }
    if(this->boxes.size()==this->maxBox){
        this->winGame = true;
    }
    //move box downward
    for(int i=0;i<this->boxes.size();i++){
        this->boxes[i].move(0.f,5.f);
    }
}

//show the box
void Box::renderBox(){
    //Render boxes
    for(auto &b:this->boxes){
        this->window->draw(b);
    }
}


//User----------------------------------------------------------------------------------------------------
void Box::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(10.f, 10.f);
    this->sprite.setPosition(500.f, 500.f);
}

void Box::initTexture(){
    //this->sprite.setTexture(this->texture);
    if(!this->texture.loadFromFile("box.png")){
        std::cout<<"No texture!\n";
    }
}

void Box::initmybox(){
    this->texture.loadFromFile("user.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(500.f, 700.f);
    this->sprite.scale(0.15, 0.15);
    
//    this->mybox.setPosition(500,800);
//    this->mybox.setSize(sf::Vector2f(50.f,50.f));
//    this->mybox.setFillColor(sf::Color::Red);
}
//mybox update
void Box::updatemyBox(){
    //move mybox downward
    this->sprite.move(0.f,3.f);
}

void Box::rendermybox(){
    this->window->draw(this->sprite);
}

const bool& Box::getEndGame() const{
    return this->endGame;
}
const bool& Box::getWinegame() const{
    return this->winGame;
}






void Box::update(){
    this->pollEvent();
    if(this->endGame == false){
    
        this->updateBox();
        this->updatemyBox();
        //this->updateCombate();
        this->updateCollision();
        this->updateGUI();
    }
    
    
}

//present-----------------------------------------------------------------------------------------------
void Box::render(){
//    sf::Texture texture;
//    texture.loadFromFile("user.png");
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
    
    this->window->clear();
    //draw background
    this->renderBackground();
    this->window->draw(sprite);
    this->renderBox();
    this->rendermybox();
    
    //if user out bound(downward), die!!
    if(this->sprite.getPosition().y>1200){
        //this->sprite.setPosition(500, 500);
        this->points=0;
        if(this->points<1){
            this->endGame = true;
        }
    }
    this->renderblowup(1500,1500);
    this->updateCombate();
    
    this->renderGUI();
    this->window->display();
    
}


//show background pic----------------------------------------------------------------------------------
void Box::initBackground(){
    if(!backroundTexture.loadFromFile("background.png")){
        std::cout<<"No background pic!";
    }
    this->background.setTexture(this->backroundTexture);
    this->background.setScale(0.4, 0.5);
    this->background.setPosition(300,400);
}

void Box::renderBackground(){
    this->window->draw(this->background);
}


//touch and the obstacles disspaear---------------------------------------------------------------------
void Box::updateCombate(){
    for(int i=0;i<this->boxes.size();i++){
        
        if(this->sprite.getGlobalBounds().intersects(boxes[i].getGlobalBounds())){
            //this->blowsprite.setPosition(boxes[i].getScale().x, boxes[i].getScale().y);
            this->renderblowup(boxes[i].getPosition().x,boxes[i].getPosition().y);
            this->boxes.erase(boxes.begin() + i);
            this->points-=1;
            //this->sprite.setPosition(500, 500);
            if(this->points<1){
                this->endGame = true;
            }
        }
        
    }
}

//blow up effect----------------------------------------------------------------------------------------
void Box::renderblowup(float a,float b){
    this->blowtexture.loadFromFile("heart.png");
    this->blowsprite.setTexture(blowtexture);
    this->blowsprite.setPosition(a, b);
    this->blowsprite.setScale(0.2, 0.2);
    this->window->draw(blowsprite);
}

//can't cross the left and right bound------------------------------------------------------------------
void Box::updateCollision(){
    if(this->sprite.getGlobalBounds().left<0.f){
        this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
    }
    if(this->sprite.getGlobalBounds().left>900.f){
        this->sprite.setPosition(880.f, this->sprite.getGlobalBounds().top);
    }
}

//score----------------------------------------------------------------------------------------------------
void Box::initGUI(){
    if(!this->font.loadFromFile("font.ttf")){
        std::cout<<"No font!\n";
    }
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(50);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("Your Points : "+std::to_string(this->points));
    
    //end game font
    this->endGameText.setFont(this->font);
    this->endGameText.setPosition(sf::Vector2f(250,700));
    this->endGameText.setCharacterSize(50);
    this->endGameText.setFillColor(sf::Color::Red);
    this->endGameText.setString("Mike is being dumped!");
    
    this->winGameText.setFont(this->font);
    this->winGameText.setPosition(sf::Vector2f(400,700));
    this->winGameText.setCharacterSize(50);
    this->winGameText.setFillColor(sf::Color::Red);
    this->winGameText.setString("Mike Wins!");
}

void Box::renderGUI(){
    this->pointText.setString("Your Points : "+std::to_string(this->points));
    this->window->draw(pointText);
    if (endGame == true) {
        this->window->draw(this->endGameText);
    }
    else if(winGame == true){
        this->window->draw(this->winGameText);
    }
}










void Box::updateGUI(){
    //this->updateCombate();
}
//
void Box::initUser(){
//    this->user=new User();
}
