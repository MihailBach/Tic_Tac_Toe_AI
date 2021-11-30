//
// Created by Misho on 26-Nov-21.
//

#include "AI.h"

int AI::minimax() {
    return 0;
}

int AI::evaluate(char board[3][3]) {
    //check rows
    for(int row = 0; row<3; row++){
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            return 0;
        }
    }
}

int AI::getValue() {
    return this->value;
}
