//
// Created by Misho on 26-Nov-21.
//

#ifndef TIC_TAC_TOE_AI2_AI_H
#define TIC_TAC_TOE_AI2_AI_H

class board;

class AI{
public:
    int evaluate(board&);
    int minimax(board&, int,int,int, bool);
    int bestMove(board&);
};


#endif //TIC_TAC_TOE_AI2_AI_H
