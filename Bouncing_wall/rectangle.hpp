#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

class rectangle : public object {
public:

    rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size);

    void draw(sf::RenderWindow & window ) const override;

    sf::FloatRect get_collider() override;

protected:
    sf::Vector2f size;
};

#endif