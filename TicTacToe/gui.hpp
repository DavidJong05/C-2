#ifndef GUI_HPP
#define GUI_HPP

#include "interface.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class gui : public Interface {
private:
    sf::RenderWindow& window;
    
public:
    gui(sf::RenderWindow& window):
        window( window )
    {}

    void draw(std::vector<Move> & moves) override {
        float x, y;
        bool player;
        sf::Color color;
        sf::Vector2f size{97.5, 97.5};
        sf::Vector2f pos;
        window.clear();
        // Draw Tic Tac Toe Grid
        draw_rectangle(sf::Vector2f{0.0, 100.0}, sf::Vector2f{300.0, 5.0}, sf::Color::White);
        draw_rectangle(sf::Vector2f{0.0, 200.0}, sf::Vector2f{300.0, 5.0}, sf::Color::White);
        draw_rectangle(sf::Vector2f{100.0, 0.0}, sf::Vector2f{5.0, 300.0}, sf::Color::White);
        draw_rectangle(sf::Vector2f{200.0, 0.0}, sf::Vector2f{5.0, 300.0}, sf::Color::White);
        draw_rectangle(sf::Vector2f{300.0, 0.0}, sf::Vector2f{5.0, 300.0}, sf::Color::White);
        // Draw undo button
        draw_picture(sf::Vector2f{305, 0}, std::string("back.jpeg"));
        
        for(auto move : moves){
            x = move.get_move()[0];
            y = move.get_move()[1];
            player = move.get_player();
            color = player? sf::Color::Blue : sf::Color::Red;
            if(x == 0){pos.x = 0;}
            else if(x == 1){pos.x = 105;}
            else if(x == 2){pos.x = 205;}
            if(y == 0){pos.y = 0;}
            else if(y == 1){pos.y = 105;}
            else if(y == 2){pos.y = 205;}
            draw_rectangle(pos,size,color);
        }
        // Event to prevend not responding window with close event
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    } 

    Move get_move(const bool player) override {
        // If Clicked
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ 
            int x, y;
            auto pos = sf::Mouse::getPosition(window);
            // Check for Undo
            if(pos.x > 305 && pos.y < 25){
                return Move(-1, -1 , -1);
            }
            if (pos.x > 0 && pos.x < 300){ // check if in field
                if(pos.y > 0 && pos.y < 300){
                    // Determine X
                    if(pos.x > 0 && pos.x < 100 ){ x = 0;}
                    else if(pos.x > 105 && pos.x < 200){ x = 1;}
                    else if(pos.x > 205 && pos.x < 300){ x = 2;}
                    // Determine Y
                    if(pos.y > 0 && pos.y < 100){ y = 0;}
                    else if(pos.y > 105 && pos.y < 200){ y = 1;}
                    else if(pos.y > 205 && pos.y < 300){ y = 2;}
                    // Return Move
                    return Move(player, x, y);
                }
            }
        }
        // Default if no mouse click was registered
        return Move(-2, -2 , -2);
    }

    void finished(const float state) override {
        auto color = sf::Color::Red;
        window.clear();
        if(state == 0.5){
            color = sf::Color::Magenta;
        }else if(state){
            color = sf::Color::Blue;
        }
        draw_rectangle(sf::Vector2f{0, 0}, sf::Vector2f{300, 300}, color);
        window.display();
        sf::sleep(sf::seconds(5)); // 5 seconds to see who won
        window.close();
    }

    void draw_rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color Color) {
        sf::RectangleShape rectangle;
        rectangle.setPosition(position);
        rectangle.setSize(size);
        rectangle.setFillColor(Color);
        window.draw(rectangle);
    }

    void draw_picture(sf::Vector2f position, std::string filename){
        sf::Texture texture;
        sf::Sprite sprite;
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(sf::Vector2f(0.20, 0.20));
        window.draw(sprite);
    }

};

#endif