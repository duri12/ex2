#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"
#include "utilities.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    this->m_player = Player(playerName);
    this->m_status = GameStatus::MidGame;
    this->m_cards = new Card[numOfCards];
    for(int i=0; i<numOfCards; i++) {
        this->m_cards[i] = cardsArray[i];
    }
}
