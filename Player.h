#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
using std::string;

class Player {
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:
    /**
    * C'tor for player.
    * @param name - Player's name
    * @param maxHP - Player's maximum HP (default value = 100)
    * @param force - Player's force (default value = 5)
    */
    Player(string name, int maxHP = 100, int force = 5);
    
    Player(const Player& p) = default;

    Player& operator=(const Player& p) = default;

    ~Player() = default;

    /**
    * Prints player's name, level, force, HP and coins
    * @return
    *   void
    */
    void printInfo() const;

    /**
    * Raises the player's level by 1 (does nothing if it's alreay 10)
    * @return
    *   void
    */
    void levelUp();
    
    /**
    * Gets the player's level
    * @return
    *   Player's level
    */
    int getLevel() const;
    
    /**
    * Raises the player's force by a given (positive) amount
    * @param num - The amount to raise the player's force
    * @return
    *   void
    */
    void buff(int num);

    /**
    * Raises the player's HP by a given (positive) amount (up to maxHP)
    * @param num - The amount to raise the player's HP
    * @return
    *   void
    */
    void heal(int num);
    
    /**
    * Decreases the player's HP by a given (positive) amount
    * @param num - The amount to decrease the player's HP
    * @return
    *   void
    */
    void damage(int num);
    
    /**
    * Checks if the player has 0 HP
    * @return
    *   true if knockes out, else false
    */
    bool isKnockedOut() const;
    
    /**
    * Raises the player's coins by a given (positive) amount
    * @param num - The amount to raise the player's coins
    * @return
    *   void
    */
    void addCoins(int num);

    /**
    * Decreases the player's coins by a given (positive) amount, if possible
    * @param num - The amount to of coins to pay
    * @return
    *   true if the player can pay the amount, else flase
    */
    bool pay(int num);

    /**
    * Gets the player's attack strengh (force + level)
    * @return
    *   The player's attack strengh
    */
    int getAttackStrengh() const;
}

#endif //EX2_PLAYER_H