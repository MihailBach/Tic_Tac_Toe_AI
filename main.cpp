
#include <iostream>
#include "board.h"

int main() {
    board x;
    std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
    while(x.winSituation()){
        x.choose_mark();
        x.print_board();
        x.write_to_board();
        std::cout << x.minimax(x, 1, true) <<std::endl;
        x.switch_mark();

    }
    return 0;
}
