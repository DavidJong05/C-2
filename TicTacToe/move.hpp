#ifndef MOVE_HPP
#define MOVE_HPP

#include <array>

class Move {
private:
    bool player;
    std::array<int, 2> coord;

public:
    Move(const bool& p, const int& x, const int& y):
        player( p ),
        coord( {x, y} )
    {}

    bool get_player() const{ return player; }

    std::array<int, 2> get_move(){ return coord; }  
};

#endif