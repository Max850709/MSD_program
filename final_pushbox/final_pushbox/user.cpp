//
//  user.cpp
//  final_pushbox
//
//  Created by max on 9/22/21.
//

#include "user.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//
//User::User(){
//    this->movementSpeed=10.f;
//    
//    this->initSprite();
//    this->initTexture();
//    
//}
//
//User::~User(){
//    
//}
//
//void User::initSprite(){
//    this->sprite.setTexture(this->texture);
//    
//    this->sprite.scale(1.f, 1.f);
//}
//
//void User::initTexture(){
//    //this->sprite.setTexture(this->texture);
//    if(!this->texture.loadFromFile("user.png")){
//        std::cout<<"No texture!\n";
//    }
//}
//
//void User::update(){
//    
//}
//
//void User::render(sf::RenderTarget & target){
//    target.draw(this->sprite);
//}
//
//void User::move(const float direX, const float direY){
//    this->sprite.move(this->movementSpeed*direX, this->movementSpeed*direY);
//}
//class User{
//    private
//}
