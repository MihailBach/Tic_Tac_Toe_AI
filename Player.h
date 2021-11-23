//
// Created by Misho on 23-Nov-21.
//

#ifndef TIC_TAC_TOE_AI_PLAYER_H
#define TIC_TAC_TOE_AI_PLAYER_H


class Player {
public:
    void choice(int choicex, int choicey);
    char mark(char mark);
private:
    char m_player_mark;
    int m_choicex;
    int m_choicey;
};


#endif //TIC_TAC_TOE_AI_PLAYER_H
