#include "player.h"
#include "utilities.h"
#include <string>
using std::string;

Player::Player(const string& name, int maxHP = 100, int force = 5){
    this->m_name = name;
    this->m_level = 1;
    this->m_force = force;
    this->m_maxHP = maxHP;
    this->m_HP = maxHP;
    this->m_coins = 0;
}

void Player::printInfo() const {
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp(){
    if(m_level != 10){
        m_level += 1;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(int num){
    m_force += num;
}

void Player::heal(int num){
    if(num < 0){
        return;
    }
    m_HP += num;
    if(m_HP > m_maxHP){
        m_HP = m_maxHP;
    }
}

void Player::damage(int num){
    if(num < 0){
        return;
    }
    m_HP -= num;
    if(m_HP < 0){
        m_HP = 0;
    }
}

bool Player::isKnockedOut() const{
    return m_HP == 0;
}

void Player::addCoins(int num){
    if(num < 0){
        return;
    }
    m_coins += num;
}

bool Player::pay(int num){
    if(num < 0 || m_coins < num){
        return false;
    }
    m_coins -= num;
    return true;
}

int Player::getAttackStrengh() const{
    return m_force + m_level; 
}