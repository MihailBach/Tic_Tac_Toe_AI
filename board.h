//
// Created by Nicky Ichov on 23/11/2021.
//

#ifndef TIC_TAC_TOE_AI_BOARD_H
#define TIC_TAC_TOE_AI_BOARD_H


#include "Player.h"

class board : public Player{
public:
    board();
    void print_board();
    void write_to_board();
    bool winSituation();
private:
    //std::vector<std::vector<char>> square;
    char square[3][3] =
            {
                    {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
            };
};



#endif //TIC_TAC_TOE_AI_BOARD_H
