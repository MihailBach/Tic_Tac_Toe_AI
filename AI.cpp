//
// Created by Misho on 26-Nov-21.
//

#include "AI.h"
#include  "board.h"

int AI::minimax(board& b, int depth, bool isMax) {
    b.winSituation();
    //if Maximizer wins
    if (this->value == 10) {
        return this->value;
    }
    //if Maximizer loses
    else if (this->value == -10) {
        return this->value;
    }
    //if it's a tie return 0
        if (b.get_prev_choices().length() == 9){
            return 0;
        }
    //if it's maximizer's turn
    if (isMax) {
        int bestScore = -10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.emptyCell(i, j)) {
                    //do the move
                    b.write_to_board(3 * i + j);
                    // choose best move
                    bestScore = std::max(bestScore, minimax(b, depth + 1, !isMax));
                    //undo move
                    b.undo_move(3 * i + j);
                }
            }
        }
        return bestScore;
    } else {
        b.switch_mark();
        int bestScore = 10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.emptyCell(i, j)) {
                    //do the move
                    b.write_to_board(3 * i + j);
                    // choose best move
                    bestScore = std::max(bestScore, minimax(b, depth + 1, !isMax));
                    //undo move
                    b.undo_move(3 * i + j);
                }
            }
        }
        return bestScore;
    }
}


int AI::getValue() {
    return this->value;
    }

void AI::bestMove(board &b) {

}
/*
int AI::evaluate(board & b) {
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]=='x')
                return +10;
            else if (b[row][0]=='o')
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]=='x')
                return +10;
            else if (b[0][col]=='o')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]=='x')
            return +10;
        else if (b[0][0]=='o')
            return -10;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]=='x')
            return +10;
        else if (b[0][2]=='o')
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}
**/
