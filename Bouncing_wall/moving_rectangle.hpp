#ifndef MOVING_RECTANGLE_HPP
#define MOVING_RECTANGLE_HPP

#include "rectangle.hpp"

class moving_rectangle : public rectangle {
public:
        moving_rectangle(sf::Vector2f position, sf::Color color , sf::Vector2f size);

        void draw( sf::RenderWindow & window ) const;
        void move( sf::Vector2f delta );
        void jump( sf::Vector2f target );
        void jump( sf::Vector2i target );
};


#endif