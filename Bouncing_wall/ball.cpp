#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"

ball::ball(sf::Vector2f position, sf::Vector2f direction, sf::Color color, float size) :
        object(position, color),
        size{ size }, direction{direction}
{}


void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setFillColor(color);
	circle.setPosition(position);
	window.draw(circle);
}


void ball::move( sf::Vector2f delta ){
    position += delta;
}


sf::FloatRect ball::get_collider(){
    sf::FloatRect collider(position, sf::Vector2f {size * 2, size * 2});
    return collider;
};


sf::Vector2f ball::get_direction(){
    return direction;
};

void ball::detect_collision(std::array< object *, 7 > objects){
    sf::FloatRect collider(position,sf::Vector2f{size * 2, size * 2}); //rectangle the ballshape
    for( auto & o : objects ){
        sf::FloatRect result; //returns the overlapped rectangle in the intersection parameter.
        bool collision = collider.intersects(o->get_collider(), result); // true if collider shape intersects with any object
        if(collision == true){
            sf::Vector2f collider_middlepoint{collider.left + (collider.width / 2), (collider.top + (collider.height / 2))};
            if(result.left > collider_middlepoint.x){ // left side of result
                if(direction.x > 0){
                    direction.x = -direction.x;
                }
            }else if (result.left + result.width  < collider_middlepoint.x){ // right side of result
                if(direction.x < 0){
                    direction.x = (direction.x * -1);
                }
            }else if (result.top + result.height  < collider_middlepoint.y){ // bottom of result
                if(direction.y < 0){
                    direction.y = (direction.y * -1);
                }
            }else if (result.top  > collider_middlepoint.y){ // top of result
                if(direction.y > 0){
                    direction.y = -direction.y;
                }
            }
        }
    }
};