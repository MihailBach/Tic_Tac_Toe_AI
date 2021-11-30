//
// Created by Misho on 23-Nov-21.
//

#ifndef TIC_TAC_TOE_AI_PLAYER_H
#define TIC_TAC_TOE_AI_PLAYER_H
#include <string>
#include "AI.h"

class Player : public AI{
public:
    Player();
    void set_choice();
    void set_choice(int);
    void switch_mark();
    int get_choice();
    char get_mark();
    char get_opp_mark();
    void choose_mark();
    std::string get_prev_choices();

private:
    char m_player_mark;
    int m_choice;
    std::string prev_choices;
    char m_opponent_mark;
};


#endif //TIC_TAC_TOE_AI_PLAYER_H
