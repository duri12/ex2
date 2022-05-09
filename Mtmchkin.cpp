#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"
#include "utilities.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    this->m_player = Player(playerName);
    this->m_status = GameStatus::MidGame;
    this->m_cards = cardsArray;
    this->m_currCard = 0;
    this->m_numOfCards = numOfCards;
}

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_status;
}

bool Mtmchkin::isOver() const {
    if(this->m_player.isKnockedOut()) {
        this->m_status= GameStatus::Loss;
        return true;
    }
    if(this->m_player.getLevel()==Player::MAX_LEVEL) {
        this->m_status = GameStatus::Win;
        return true;
    }
    return false;
}

void Mtmchkin::playNextCard() {
    this->m_cards[this->m_currCard].applyEncounter();
    if(this->m_currCard+1==this->m_numOfCards) {
        this->m_currCard=0;
    } else {
        this->m_currCard++;
    }

}
