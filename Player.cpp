//
// Created by harel on 08/05/2022.
//
#include "Player.h"
#include "utilities.cpp"
#include <string.h>
#include <iostream>


static const int MAX_LEVEL =10 ;

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
    if(this->m_level<MAX_LEVEL){
        this->m_level++;
    }
}

int Player::getLevel() const{
    return this->m_level;
}

void Player::buff(int amount) {
    if(amount >0){
        this->m_force+=amount;
    }
}

void Player::heal(int amount) {
    if(amount >0){
        if(amount + this->m_HP >=this->m_maxHP){
            this->m_HP = this->m_maxHP;
        }
        else{
            this->m_HP += amount;
        }
    }
}

void Player::damage(int amount) {
    if(amount >0){
        if(this->m_HP - amount > 0){
            this->m_HP -= amount;
        }
        else{
            this->m_HP = 0;
        }
    }
}


void Player::addCoins(int amount) {
    if(amount >0){
        this->m_coins += amount;
    }
}

int Player::getAttackStrength() const{
    return this->m_level+this->m_force;
}