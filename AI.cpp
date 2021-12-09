//
// Created by Misho on 26-Nov-21.
//

#include <iostream>
#include "AI.h"
#include "board.h"

int AI::minimax(board& b, int depth,int alpha, int beta, bool isMax) {
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
        return 4;
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
                    score = minimax(b, depth+1,alpha,beta, !isMax);
                    bestScore = std::max(bestScore, score);
                    //alpha beta pruning
                    alpha = std::max(alpha, score);
                    //undo move
                    b.undo_move(i * 3 + j);
                    //check if this move is best
                    if (beta <= alpha){
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.emptyCell(i, j)) {
                    //do the move
                    b.write_to_board((i * 3 + j), b.get_mark());
                    // choose best move
                    score = minimax(b, depth+1,alpha,beta, !isMax);
                    bestScore = std::min(bestScore, score);
                    //rewrite beta
                    beta = std::min(beta, score);
                    //undo move
                    b.undo_move(i * 3 + j);
                    //check if this move is best
                    if(beta<=alpha){
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    }

}


int AI::bestMove(board &b) {
    int bestVal = 0;
    int bestMove = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(b.emptyCell(i,j)){
                b.write_to_board(i*3+j, b.get_opp_mark());
                int moveVal = b.minimax(b, 0,-1000000,1000000, false);
                b.undo_move(i*3+j);
                if(moveVal > bestVal){
                    bestMove = i*3+j;
                }
            }
        }
    }
    return bestMove;
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
