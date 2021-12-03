//
// Created by Nicky Ichov on 23/11/2021.
//

#ifndef TIC_TAC_TOE_AI_BOARD_H
#define TIC_TAC_TOE_AI_BOARD_H


#include "Player.h"

class board : public Player{
public:
    board();
    char** get_square();
    void print_board();
    void undo_move(int);
    void write_to_board();
    void write_to_board(int);
    bool winSituation();
    bool emptyCell(int,int);
private:
    char square[3][3] =
            {
                    {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
            };
};



#endif //TIC_TAC_TOE_AI_BOARD_H
