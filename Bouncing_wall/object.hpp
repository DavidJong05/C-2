#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

class object{
protected:
    sf::Vector2f position;
    sf::Color color;
public:
    object( sf::Vector2f position, sf::Color color):
        position{position},
        color{color}
    {}

    virtual void draw( sf::RenderWindow & window ) const = 0;

    virtual sf::FloatRect get_collider() = 0;

};
#endif