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
    this->maxBox=50;
    this->points=0;
}
void Box::initWindows(){
    this->videomode.height=1200;
    this->videomode.width=1000;
    this->window=new sf::RenderWindow(this->videomode, "My window");
    this->window->setFramerateLimit(60); //60 FPS
}

//constructor
Box::Box(){
    this->initVariables();
    this->initWindows();
    this->initbox();
    this->initmybox();
    this->renderBox();
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
        
        //User control
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                this->mybox.move(-40.f, 0.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                this->mybox.move(40.f, 0.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                this->mybox.move(0.f, -40.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                this->mybox.move(0.f, 40.f);
            }
    }
}

//initial box
void Box::initbox(){
    this->box.setPosition(0,0);
    this->box.setSize(sf::Vector2f(80.f,80.f));
    this->box.setFillColor(sf::Color::Blue);
    this->box.setOutlineColor(sf::Color::Green);
    this->box.setOutlineThickness(1.f);
    
}
void Box::initmybox(){
    this->mybox.setPosition(500,1000);
    this->mybox.setSize(sf::Vector2f(50.f,50.f));
    this->mybox.setFillColor(sf::Color::Red);
}

//create box vector
void Box::outputBox(){
    this->box.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->box.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y-900 - this->box.getSize().y))
    );
    
    this->box.setFillColor(sf::Color::Green);
    
    //spawn boxes
    this->boxes.push_back(this->box);
    
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
    //move box downward
    for(int i=0;i<this->boxes.size();i++){
        this->boxes[i].move(0.f,5.f);
    }
}

//mybox update
void Box::updatemyBox(){
    //move mybox downward
    this->mybox.move(0.f,3.f);
}

//show the box
void Box::renderBox(){
    //Render boxes
    for(auto &b:this->boxes){
        this->window->draw(b);
    }
}
void Box::rendermybox(){
    this->window->draw(this->mybox);
}

void Box::update(){
    this->pollEvent();
    this->updateBox();
    this->updatemyBox();
}

//present
void Box::render(){
    this->window->clear();
//    this->user->render(*this->window);
    this->renderBox();
    this->rendermybox();
    this->window->display();
    
}

//
void Box::initUser(){
//    this->user=new User();
}

const bool Box::windowisopen() const{
    return (this->window->isOpen());
}

