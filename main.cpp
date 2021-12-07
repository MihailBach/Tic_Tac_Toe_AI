
#include <iostream>
#include "board.h"

int main() {
    board x;
    std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
    while(x.winSituation()){
        x.choose_mark();
        x.print_board();
        x.write_to_board();
         /*
        x.write_to_board(0, x.get_mark());
        x.write_to_board(1, x.get_opp_mark());
        x.write_to_board(2, x.get_mark());
        x.write_to_board(3, x.get_opp_mark());
        x.write_to_board(4, x.get_opp_mark());
        x.write_to_board(5, x.get_mark());
        x.print_board();*/
        auto cpu_move = x.bestMove(x);
        std::cout<< "The best move's " << cpu_move <<std::endl;
        x.write_to_board(cpu_move, x.get_opp_mark());
        //x.switch_mark();
    }
    return 0;
}
