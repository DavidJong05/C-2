#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "object.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "moving_rectangle.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition([ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition([ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }),
		work(work)
	{}

	action(std::function< void() > work) :
		condition([](){return 1;}),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};



int main( int argc, char *argv[] ){
    std::cout << "Starting 1. Muren en stuiteren\n";

    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
    ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{ 6, 6 }, sf::Color ::Blue};
    ball my_ball2{ sf::Vector2f{ 250.0, 200.0 }, sf::Vector2f{ -6, 6 }, sf::Color ::Blue};
    rectangle my_wall_left{ sf::Vector2f{ 0.0, 0.0 }, sf::Color ::Magenta,sf::Vector2f{10, 480} };
    rectangle my_wall_right{ sf::Vector2f{ 630.0, 0.0 }, sf::Color ::Green,sf::Vector2f{10, 480} };
    rectangle my_wall_top{ sf::Vector2f{ 0.0, 0.0 }, sf::Color ::Red,sf::Vector2f{640, 10} };
    rectangle my_wall_down{ sf::Vector2f{ 0.0, 470.0 }, sf::Color ::Yellow,sf::Vector2f{640, 10} };
    moving_rectangle my_moving_rectangle{sf::Vector2f{240.0, 220.0 }, sf::Color ::Cyan, sf::Vector2f{75, 75} };
    std::array< object *, 7 > objects = {&my_ball, &my_ball2, &my_moving_rectangle, &my_wall_down, &my_wall_left, &my_wall_right, &my_wall_top };

    action actions[] = {
            action( sf::Keyboard::Left,  [&](){ my_moving_rectangle.move(sf::Vector2f(-2.0, 0.0 )); }),
            action( sf::Keyboard::Right, [&](){ my_moving_rectangle.move(sf::Vector2f(+2.0, 0.0 )); }),
            action( sf::Keyboard::Up,    [&](){ my_moving_rectangle.move(sf::Vector2f(0.0, -2.0 )); }),
            action( sf::Keyboard::Down,  [&](){ my_moving_rectangle.move(sf::Vector2f(0.0, +2.0 )); }),
            action( [&](){ my_ball.move( sf::Vector2f(  my_ball.get_direction() )); }),
            action( [&](){ my_ball.detect_collision( objects); }),
            action( [&](){ my_ball2.move( sf::Vector2f(  my_ball2.get_direction() )); }),
            action( [&](){ my_ball2.detect_collision( objects); }),
            action( sf::Mouse::Left,     [&](){ my_moving_rectangle.jump(sf::Mouse::getPosition(window )); })
    };

    while (window.isOpen()) {
        for( auto & action : actions ){
            action();
        }

        window.clear();
        for( auto & o : objects ){
            o->draw(window);
        }
        window.display();

        sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                window.close();
            }
        }
    }

    std::cout << "Terminating application\n";
    return 0;
}