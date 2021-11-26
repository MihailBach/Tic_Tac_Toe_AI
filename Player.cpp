//
// Created by Misho on 23-Nov-21.
//

#include <iostream>
#include "Player.h"
#include <ctype.h>


Player::Player() {
    this->m_player_mark = get_mark();
    this->m_choice = get_choice();
    this->prev_choices = get_prev_choices();
}
void Player::switch_mark() {
    if (m_player_mark == 'o'){
        m_player_mark = 'x';
    }
    else{
        m_player_mark = 'o';
    }
}

void Player::set_choice() {
    std::cout << "Your move Mr." <<(char)toupper(m_player_mark)<<":"<<std::endl;
    char temp = 'a';
    std::cin >> temp;
    while( prev_choices.find(temp) != std::string::npos){
        std::cout << "Please input a correct number"<<std::endl;
        std::cin >> temp;
    }
    prev_choices= prev_choices + temp;
    this->m_choice = std::stoi(&temp);

}
int Player:: get_choice(){
    return this->m_choice;
}

char Player::get_mark() {
    return this->m_player_mark;
}

void Player::choose_mark() {
    while (m_player_mark != 'x' && m_player_mark != 'o'){
        std::cout << "Please choose X or O: " <<std::endl;
        std::cin >> m_player_mark;
        m_player_mark = tolower(m_player_mark);
    }
}

std::string Player::get_prev_choices() {
    return prev_choices;
}


