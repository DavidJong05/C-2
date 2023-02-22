#ifndef GAME_HPP
#define GAME_HPP

#include "move.hpp"
#include <vector>
#include "interface.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class TicTacToe {
private:
    std::vector<Move> moves;
    Interface& interface;

public:
    TicTacToe(Interface& interface):
        interface( interface )
    {}

    bool add_move( Move m ){
        // Undo a move with -1 -1
        if(m.get_move()[0] == -1 && m.get_move()[1] == -1){ 
            if(!moves.empty()){
                moves.pop_back();
                sf::sleep(sf::milliseconds(500)); 
                return true;
            }
        }
        // Move already happened
        for(auto move : moves){
            if(m.get_move() == move.get_move()){
                return false;
            }
        } 
        // valid move, add to moves
        if(m.get_move()[0] >= 0 && m.get_move()[0] < 3 && m.get_move()[1] >= 0 && m.get_move()[1] < 3){
                moves.push_back(m);
                return true;
        }
        return false;
    }

    float check_win(){
        int board[3][3]={{2,2,2},{2,2,2},{2,2,2}}; // players are 0 and 1
        int x, y;
        bool player;
        for(auto move : moves){
            x = move.get_move()[0];
            y = move.get_move()[1];
            player = move.get_player();
            board[y][x] = player? 0 : 1;
        }

        for (int i=0; i<=2; i++){
            // any of the rows is same
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=2){
                return 1;
            }
            // any of the colums is same
            if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=2){
                return 1;
            }
        }
        // 1st diagonal is same
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=2){
            return 1;
        }
        // 2nd diagonal is same
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!=2){
            return 1;
        }
        // full board
        if(moves.size() > 8){
            return 0.5;
        }
        return 0;
    }

    bool get_last_player(){ return moves.back().get_player(); }

    void main(){
        bool player = 0;
        while( check_win() == 0.0 ){
            if(add_move(interface.get_move(player))){ // move is valid and added
                player = !player; // switch player
            }
            interface.draw(moves);
            sf::sleep(sf::milliseconds(20));
        }
        if(check_win() == 0.5){
            interface.finished( 0.5 );
        } else {
            interface.finished(get_last_player());
        }   
    }
};

#endif