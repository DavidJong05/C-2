#ifndef _BALL_HPP
#define _BALL_HPP


#include <SFML/Graphics.hpp>
#include "object.hpp"

class ball : public object{
public:

	ball(sf::Vector2f position, sf::Vector2f direction = {1, 1} , sf::Color color = sf::Color ::White, float size = 30.0);

    sf::FloatRect get_collider() override;

	void draw( sf::RenderWindow & window ) const override;

    sf::Vector2f get_direction();

    void move( sf::Vector2f delta );
    
    void detect_collision(std::array< object *, 7> objects);

private:
	float size;
	sf::Vector2f direction;
};

#endif