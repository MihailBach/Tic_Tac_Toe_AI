//
// Created by Misho on 23-Nov-21.
//

#ifndef TIC_TAC_TOE_AI_PLAYER_H
#define TIC_TAC_TOE_AI_PLAYER_H
#include <string>

class Player {
public:
    Player();
    void set_choice();
    void switch_mark();
    int get_choice();
    char get_mark();
    void choose_mark();
    std::string get_prev_choices();

private:
    char m_player_mark = 't';
    int m_choice;
    std::string prev_choices;
};


#endif //TIC_TAC_TOE_AI_PLAYER_H
