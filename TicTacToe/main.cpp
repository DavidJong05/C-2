#include "game.hpp"
#include "cli.hpp"
#include "gui.hpp"
#include "string"

int main(){
    std::string argument;
    std::cout << "Press: G for GUI" << "\n";
    std::cout << "Press: C for CLI" << "\n";
    std::cin >> argument;
    
    if(argument == "G"){
        sf::RenderWindow window{sf::VideoMode{350, 300}, "Tic Tac Toe"};
        gui gui{window};
        TicTacToe game( gui );
        game.main();
    } else if(argument == "C"){
        cli commandline;
        TicTacToe game( commandline );
        game.main();
    }
    return 0;
}