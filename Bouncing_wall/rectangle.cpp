#include <SFML/Graphics.hpp>
#include "rectangle.hpp"


rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
        object(position, color), size{size}
{}

void rectangle::draw( sf::RenderWindow & window ) const {
    sf::RectangleShape rectangle;
    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

sf::FloatRect rectangle::get_collider(){
    sf::FloatRect collider(position, size);
    return collider;
};