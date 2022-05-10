#include "Player.h"
#include "Mtmchkin.h"
#include "Card.h"


const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
m_player(playerName)
{
    Card *temp = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        temp[i] = cardsArray[i];
    }
    this->m_cards = temp;
    this->m_status = GameStatus::MidGame;
    this->m_currCard = 0;
    this->m_numOfCards = numOfCards;
}

Mtmchkin::~Mtmchkin(){
    delete [] m_cards;
}

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_status;
}


bool Mtmchkin::isOver(){
    if(this->m_player.isKnockedOut()) {
        this->m_status= GameStatus::Loss;
        return true;
    }
    if(this->m_player.getLevel()==MAX_LEVEL) {
        this->m_status = GameStatus::Win;
        return true;
    }
    return false;
}

void Mtmchkin::playNextCard() {
    this->m_cards[this->m_currCard].printInfo();
    this->m_cards[this->m_currCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    if(this->m_currCard+1==this->m_numOfCards) {
        this->m_currCard=0;
    } else {
        this->m_currCard++;
    }
}

