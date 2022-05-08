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
    Player(const Player&);
    Player operator=(const Player&);
    ~Player() = default;
    void printInfo() const;
    void levelUpdate();
    int getLevel() const;
    void buff(int addedForce);
    void heal(int health);
    void damage(int damage);
    bool isKnockedOut() const;
    void addCoins(int amount);
    bool pay(int amount);
    int getAttackStrength() const;

};


#endif //EX2_PLAYER_H
