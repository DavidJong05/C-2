#include <SFML/Graphics.hpp>
#include "moving_rectangle.hpp"


moving_rectangle::moving_rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size ) :
        rectangle(position, color, size)
{}


void moving_rectangle::draw(sf::RenderWindow & window ) const {
    sf::RectangleShape rectangle;
    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void moving_rectangle::move(sf::Vector2f delta ){
    position += delta;
}

void moving_rectangle::jump(sf::Vector2f target ){
    position = target;
}

void moving_rectangle::jump(sf::Vector2i target ){
    jump( sf::Vector2f(
            static_cast< float >( target.x ),
            static_cast< float >( target.y )
    ));
}
