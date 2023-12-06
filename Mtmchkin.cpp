#include "Card.h"
#include <iostream>
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    m_playerName = playerName;
    m_cardsArray = cardsArray;
    m_numOfCards = numOfCards;
    m_turns = 0;
    m_player = Player(playerName);
    m_status = GameStatus::MidGame;
}

Mtmchkin::Mtmchkin(const Mtmchkin& other){
    m_playerName = other.m_playerName;
    m_numOfCards = other.m_numOfCards;
    m_cardsArray = new Card[m_numOfCards];
    for(int i = 0; i < m_numOfCards; i++){
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    m_turns = other.m_turns;
    m_player = other.m_player;
    m_status = other.m_status;
}

Mtmchkin::~Mtmchkin(){
    delete[] m_playerName;
    delete[] m_cardsArray;
    ~m_player();
}

Mtmchkin& operator=(const Mtmchkin& other){
    m_playerName = other.m_playerName;
    m_numOfCards = other.m_numOfCards;
    m_cardsArray = new Card[m_numOfCards];
    for(int i = 0; i < m_numOfCards; i++){
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    m_turns = other.m_turns;
    m_player = other.m_player;
    m_status = other.m_status;
}

void Mtmchkin::playNextCard(){
    Card current_card = cardsArray[m_turns % m_numOfCards];
    current_card.printInfo();
    current_card.applyEncounter(m_player);
    ++m_turns;
}

bool Mtmchkin::isOver(){
    return player.isKnockedOut() || player.GetLevel() == 10;
}

GameStatus getGameStatus(){
    if(this.isOver()){
        if(player.isKnockedOut()){
            return Loss;
        } else{
            return Win
        }
    }
    return MidGame;
}