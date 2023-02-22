#ifndef CLI_HPP
#define CLI_HPP

#include "interface.hpp"
#include <iostream>

class cli : public Interface {
public:
    /// Draws the board based on the moves
    void draw(std::vector<Move> & moves) override {
        int x, y;
        bool player;
        std::string sign;
        std::string m[9]= {" "," "," "," "," "," "," "," "," "};
        for(auto move : moves){
            x = move.get_move()[0];
            y = move.get_move()[1];
            player = move.get_player();
            m[x + 3*y] = player?"X":"O";
        }
        std::cout<<"\n";
        std::cout<<" "<<m[0]<<" | "<<m[1]<<" | "<<m[2]<<" "<<"\n";
        std::cout<<"---+--"<<"-+---"<<"\n";
        std::cout<<" "<<m[3]<<" | "<<m[4]<<" | "<<m[5]<<" "<<"\n";
        std::cout<<"---+--"<<"-+---"<<"\n";
        std::cout<<" "<<m[6]<<" | "<<m[7]<<" | "<<m[8]<<" "<<"\n";
    }

    /// gets move from command line input
    Move get_move(const bool player) override {
        int x, y;
        std::cout << "\nPlayer " << player + 1 << " give X coordinate: ";
        std::cin >> x;
        std::cout << "\nPlayer " << player + 1 << " give Y coordinate: ";
        std::cin >> y;
        Move playedMove(player, x, y);
        return playedMove;
    }

    void finished(const float state) override {
        if(state == 0.5){
            std::cout << "\ndraw!\n";
        } else {
            std::cout << "\nPlayer " << state + 1 << " wins!\n";
        }
    }
};

#endif