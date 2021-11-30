
#include <iostream>
#include "board.h"

int main() {
    board x;
    std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
    while(x.winSituation()){
        x.choose_mark();
        x.print_board();
        x.write_to_board();
        x.switch_mark();
    }
    std::cout << x.getValue() <<std::endl;
    return 0;
}
