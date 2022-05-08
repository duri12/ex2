//
// Created by harel on 08/05/2022.
//
#include "Player.h"
#include "utilities.cpp"
#include <string.h>
#include <iostream>


Player::Player(char *name, int maxHP, int force) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_maxHP = maxHP;
    m_HP = maxHP;
    m_force = force;
    m_level = 1;
    m_coins =0;
}

Player::Player(const Player& p1){
    m_name = new char[strlen(p1.m_name) + 1];
    strcpy(m_name, p1.m_name);
    m_maxHP = p1.m_maxHP;
    m_force = p1.m_force;
    m_level = p1.m_level;
    m_coins =p1.m_coins;
}

Player::~Player(){
    delete[] m_name;
}

Player operator=(const Player& p2) {
    this->m_level = p2->m_level;
    this->m_force = p2->m_force;
    int m_MaxHP;
    int m_HP;
    int m_coins
}


void Player::printInfo() const {
    printPlayerInfo(this->m_name,this->m_level,this->m_force , this->m_HP , this->m_coins);
}
void Player::levelUpdate() {
    if(this->)
}