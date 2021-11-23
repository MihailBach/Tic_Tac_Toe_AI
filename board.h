//
// Created by Nicky Ichov on 23/11/2021.
//

#ifndef TIC_TAC_TOE_AI_BOARD_H
#define TIC_TAC_TOE_AI_BOARD_H


class board {
public:
    void print_board();
    void get_square();
    bool winSituation();
private:
    char square[3][3] = { {' '},{' '} };
};


#endif //TIC_TAC_TOE_AI_BOARD_H
