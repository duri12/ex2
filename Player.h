#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

class Player {
    std::string m_name;
    int m_level;
    int m_force;
    int m_MaxHP;
    int m_HP;
    int m_coins;


public:
    Player(std::string name, int maxHP =100, int force =5);


};


#endif //EX2_PLAYER_H
