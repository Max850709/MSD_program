#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <algorithm>

#include "box.hpp"


int main() {
    
    std::srand(static_cast<unsigned>(time(NULL)));
    
    //init game
    Box box;
    
    while(box.windowisopen()){

        //Update
        box.update();
        //Render
        
        box.render();
        
    }
    
    return 0;
    // Create the main program window.
//    sf::RenderWindow window(sf::VideoMode(1000, 1200), "My window");

    // Run the program as long as the main window is open.
//    while (window.isOpen()) {
//      // Check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event)){
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//
//      // clear the window with black color
//      window.clear(sf::Color::Black);
//
//        std::vector<sf::RectangleShape> rectVec;
//        Box(500, 500, 100,100);
//
//
//        for (int i=0;i<5;i++) {
//            std::vector<int> x={0,100,200,300,400,500,600,700,800,900};
//            std::vector<int> y={100,200,300,400,500,600,700,800,900,1000};
//
//            std::random_shuffle(x.begin(), x.end());
//            std::random_shuffle(y.begin(), y.end());
//
//            int x1=x[x.size()-1];
//            int y1=y[y.size()-1];
//
//              sf::RectangleShape rectangle(sf::Vector2f(100, 100));
//                rectangle.setSize(sf::Vector2f(100, 100));
//                rectangle.setFillColor(sf::Color(100, 250, 50));
//                rectangle.setPosition( x1, y1);
//              rectVec.push_back(rectangle);
//            x.pop_back();
//            y.pop_back();
//        }
//
//        for (sf::RectangleShape rec : rectVec) {
//            window.draw(rec);
//        }
//
//      // end the current frame
//      window.display();
//    }


}
