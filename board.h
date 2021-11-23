//
// Created by Nicky Ichov on 23/11/2021.
//

#ifndef TIC_TAC_TOE_AI_BOARD_H
#define TIC_TAC_TOE_AI_BOARD_H


#include "Player.h"

class board : public Player{
public:
    void print_board();
    board();
    void write_to_board();
    bool winSituation();
    bool get_is_game_on();
    void set_is_game_on();

private:
    //std::vector<std::vector<char>> square;
    char square[3][3] =
            {
                    {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
            };
    bool is_game_on = true;
};



#endif //TIC_TAC_TOE_AI_BOARD_H