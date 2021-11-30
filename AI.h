//
// Created by Misho on 26-Nov-21.
//

#ifndef TIC_TAC_TOE_AI2_AI_H
#define TIC_TAC_TOE_AI2_AI_H

class AI{
public:
    int minimax();
    int evaluate(char[3][3]);
    int getValue();

protected:
    int depth;
    int value;

};


#endif //TIC_TAC_TOE_AI2_AI_H
