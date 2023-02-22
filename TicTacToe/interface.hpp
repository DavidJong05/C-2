#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "move.hpp"
#include <vector>

class Interface {
public:
    Interface(){}

    virtual Move get_move(const bool player){ return Move(-2, -2, -2); };

    virtual void finished(const float state){};

    virtual void draw(std::vector<Move> & moves){};
};

#endif