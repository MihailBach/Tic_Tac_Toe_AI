//
// Created by Misho on 26-Nov-21.
//

#include <iostream>
#include "AI.h"
#include  "board.h"

int AI::minimax(board& b, int depth, bool isMax) {
    int score = evaluate(b);
    //if Maximizer wins
    if (score == 10) {
        return score;
    }
        //if Maximizer loses
     if (score == -10) {
        return score;
    }
    //if it's a tie return 0
    if(!b.isMoveLeft()){
        return 4;   //BIG BODGE
    }
    //if it's maximizer's turn
    if (isMax) {
        int bestScore = -10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.emptyCell(i, j)) {
                    //do the move
                    b.write_to_board(i * 3 + j, b.get_opp_mark());
                    // choose best move
                    score = minimax(b, depth+1, !isMax);
                    bestScore = std::max(bestScore, score);
                    //undo move
                    b.undo_move(i * 3 + j);
                }
            }
        }
        return bestScore;
    } else {
        //b.switch_mark();
        int bestScore = 10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.emptyCell(i, j)) {
                    //do the move
                    b.write_to_board((i * 3 + j), b.get_mark());
                    // choose best move
                    score = minimax(b, depth+1, !isMax);
                    bestScore = std::min(bestScore, score);
                    //undo move
                    b.undo_move(i * 3 + j);
                }
            }
        }
        return bestScore;
    }

}


int AI::bestMove(board &b) {
    int bestVal = 0;
    int cord = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(b.emptyCell(i,j)){
                b.write_to_board(i*3+j, b.get_opp_mark());
                int moveVal = b.minimax(b, 0, false);
                b.undo_move(i*3+j);
                if(moveVal > bestVal){
                    //b.switch_mark();
                    //b.write_to_board(i*3+j ,b.get_opp_mark());
                    std::cout <<"Best move is: "<< "x: " << i << " y: " <<j << std::endl;
                    cord = i*3+j;
                }
            }
        }
    }
    return cord;
}

AI::AI() {
    this->value = 1;
    this->depth = 0;
}

int AI::evaluate(board & b) {
        // Checking for Rows for X or O victory.
        for (int row = 0; row<3; row++)
        {
            if (b.check_square(row, 0)==b.check_square(row, 1) &&
                b.check_square(row, 1)==b.check_square(row,2))
            {
                if (b.check_square(row, 0)==b.get_mark())
                    return -10;
                else if (b.check_square(row, 0)==b.get_opp_mark())
                    return +10;
            }
        }

        // Checking for Columns for X or O victory.
        for (int col = 0; col<3; col++)
        {
            if (b.check_square(0, col)==b.check_square(1, col) &&
                b.check_square(0, col)==b.check_square(2, col))
            {
                if (b.check_square(0, col)==b.get_mark())
                    return -10;
                else if (b.check_square(0, col)==b.get_opp_mark())
                    return +10;
            }
        }
        // Checking for Diagonals for X or O victory.
        if (b.check_square(0,0)==b.check_square(1,1) && b.check_square(1,1)==b.check_square(2,2))
        {
            if (b.check_square(0, 0)==b.get_mark()) {
                return -10;
            }
            else if (b.check_square(0, 0)==b.get_opp_mark()) {
                return +10;
            }
        }

        if (b.check_square(0, 2)==b.check_square(1,1) && b.check_square(1,1)==b.check_square(2, 0))
        {
            if (b.check_square(0, 2)==b.get_mark())
                return -10;
            else if (b.check_square(0,2)==b.get_opp_mark())
                return +10;
        }
        // Else if none of them have won then return 0
        return 0;
    }
