//
// Created by Nicky Ichov on 23/11/2021.
//

#include "board.h"
#include <iostream>

void board::print_board() {
    std::cout << square[0][0] <<"   |   " << square[0][1] << "   |   " << square[0][2]  << std::endl;

    std::cout << "____|_______|____" << std::endl;
    std::cout << square[1][0] <<"   |   " << square[1][1] << "   |   " << square[1][2]  << std::endl;

    std::cout << "____|_______|____" << std::endl;
    std::cout << square[2][0] <<"   |   " << square[2][1] << "   |   " << square[2][2]  << std::endl;

    std::cout << "    |       |   " << std::endl;


}

void board::get_square() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (winSituation()) {
                std::cout << "Enter a number: \n";
                std::cin >> square[i][j];

                print_board();
            }
        }
    }
}

bool board::winSituation() {
    if (square[0][0] == 'x' && square[0][1] == 'x' && square[0][2] == 'x') {
        std::cout << "You win\n";
        return false;
    }
    else if (square[1][0] == 'x' && square[1][1] == 'x' && square[1][2] == 'x'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[2][0] == 'x' && square[2][1] == 'x' && square[2][2] == 'x'){
        std::cout << "You win\n";
        return false;
    }

    else if (square[0][0] == 'x' && square[1][0] == 'x' && square[2][0] == 'x'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][1] == 'x' && square[1][1] == 'x' && square[2][1] == 'x'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][2] == 'x' && square[1][2] == 'x' && square[2][2] == 'x'){
        std::cout << "You win\n";
        return false;
    }

    else if (square[0][0] == 'x' && square[1][1] == 'x' && square[2][2] == 'x'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][2] == 'x' && square[1][1] == 'x' && square[2][0] == 'x'){
        std::cout << "You win\n";
        return false;
    }

    if (square[0][0] == 'o' && square[0][1] == 'o' && square[0][2] == 'o') {
        std::cout << "You win\n";
        return false;
    }
    else if (square[1][0] == 'o' && square[1][1] == 'o' && square[1][2] == 'o'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[2][0] == 'o' && square[2][1] == 'o' && square[2][2] == 'o'){
        std::cout << "You win\n";
        return false;
    }

    else if (square[0][0] == 'o' && square[1][0] == 'o' && square[2][0] == 'o'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][1] == 'o' && square[1][1] == 'o' && square[2][1] == 'o'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][2] == 'o' && square[1][2] == 'o' && square[2][2] == 'o'){
        std::cout << "You win\n";
        return false;
    }

    else if (square[0][0] == 'o' && square[1][1] == 'o' && square[2][2] == 'o'){
        std::cout << "You win\n";
        return false;
    }
    else if (square[0][2] == 'o' && square[1][1] == 'o' && square[2][0] == 'o'){
        std::cout << "You win\n";
        return false;
    }

    else
        return true;
}
