#include <string>
#include "Player.h"
#include "utilities.h"
#include "Card.h"

Card::Card(CardType type, const CardStats stats&) : m_effect(type), m_stats(stats);

void Card::applyEncounter(Player& player) const{
    switch(m_effect){
        case Battle:
            bool win = player.getAttackStrengh() >= m_stats.force;
            printBattleResult(win);
            if(win){
                player.levelUp();
                player.addCoins(m_stats.loot);
            } else{
                player.damage(m_stats.hpLossOnDefeat);
            }
            break;
        case Heal:
            if(player.pay(cost)){
                player.m_HP += heal;
            }
            break;
        case Buff:
            if(player.pay(cost)){
                player.m_force += buff;
            }
            break;
        case Treasure:
            player.addCoins(loot);
            break;
    }
}

void Card::printInfo() const{
    switch(m_effect){
        case Battle:
            printBattleCardInfo(m_stats);
            break;
        case Heal:
            printHealCardInfo(m_stats);
            break;
        case Buff:
            printBuffCardInfo(m_stats);
            break;
        case Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }    
}