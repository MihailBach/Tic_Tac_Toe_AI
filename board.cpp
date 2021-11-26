//
// Created by Nicky Ichov on 23/11/2021.
//

#include "board.h"
#include <iostream>

board::board() {
    for (int i = 0; i < 9; ++i) {
        square[i / 3][i % 3] = '1' + i;
    }
}

void board::print_board() {
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cout << "|" << square[i][j]<<"|";
        }
        std::cout <<std::endl;
    }
}
void board::write_to_board() {
    this->set_choice();
    int i = this->get_choice();
    square[i/3][(i%3) -1] = get_mark();
}

bool board::winSituation() {
    if (square[0][0] == 'x' && square[0][1] == 'x' && square[0][2] == 'x') {
        std::cout << "x wins\n";
        return false;
    }
    else if (square[1][0] == 'x' && square[1][1] == 'x' && square[1][2] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }
    else if (square[2][0] == 'x' && square[2][1] == 'x' && square[2][2] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }

    else if (square[0][0] == 'x' && square[1][0] == 'x' && square[2][0] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }
    else if (square[0][1] == 'x' && square[1][1] == 'x' && square[2][1] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }
    else if (square[0][2] == 'x' && square[1][2] == 'x' && square[2][2] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }

    else if (square[0][0] == 'x' && square[1][1] == 'x' && square[2][2] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }
    else if (square[0][2] == 'x' && square[1][1] == 'x' && square[2][0] == 'x'){
        print_board();
        std::cout << "x wins\n";
        return false;
    }
    else if (square[0][0] == 'o' && square[0][1] == 'o' && square[0][2] == 'o') {
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else if (square[1][0] == 'o' && square[1][1] == 'o' && square[1][2] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else if (square[2][0] == 'o' && square[2][1] == 'o' && square[2][2] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }

    else if (square[0][0] == 'o' && square[1][0] == 'o' && square[2][0] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else if (square[0][1] == 'o' && square[1][1] == 'o' && square[2][1] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else if (square[0][2] == 'o' && square[1][2] == 'o' && square[2][2] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }

    else if (square[0][0] == 'o' && square[1][1] == 'o' && square[2][2] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else if (square[0][2] == 'o' && square[1][1] == 'o' && square[2][0] == 'o'){
        print_board();
        std::cout << "o wins\n";
        return false;
    }
    else {
        int tie = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(square[i][j] == 'x' || square[i][j] == 'o'){
                    tie++;
                }
            }
        }
        if(tie == 9){
            std::cout << "you tied!" << std::endl;
            print_board();
            return false;
        }
    }
}

