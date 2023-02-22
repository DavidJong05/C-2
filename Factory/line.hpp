#ifndef LINE_HPP
#define LINE_HPP

#include "drawable.hpp"

class line : public drawable {
public:
    line(sf::Vector2f position, sf::Vector2f size, sf::Color Color = sf::Color::White ):
        drawable(position,size, Color)
    {}

    void draw(sf::RenderWindow& window) const {
        sf::Vertex line[] ={
            sf::Vertex(sf::Vector2f(position.x, position.y), Color),
            sf::Vertex(sf::Vector2f(size.x, size.y), Color)
        };
        window.draw(line, 2, sf::Lines);
    }

    void writeType(std::ofstream & output) override { output << "LINE ";}

    void writeSpecific(std::ofstream & output) override {
        writeColor(output);
		output << "(" << size.x << "," << size.y << ")\n";
    }
};

#endif