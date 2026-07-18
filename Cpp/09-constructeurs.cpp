#include <iostream>
#include <string>

struct Player
{
    std::string name;
    int vie;
    int damages;

    Player();                                              // constructeur par défaut
    Player(const Player &player);                          // constructeur de copie
    Player(const std::string &name, int vie, int damages); // constructeur avec paramètres

    bool IsDead();

    void attack(Player &other); // déclaration de la méthode attack
};

// Définition des constructeurs et méthodes

Player::Player() : name(""), vie(100), damages(10) {} // constructeur par défaut

Player::Player(const Player &player) : name(player.name), vie(player.vie), damages(player.damages) {} // constructeur de copie

Player::Player(const std::string &name, int vie, int damages) : name(name), vie(vie), damages(damages) {} // constructeur avec paramètres

bool Player::IsDead()
{
    return vie <= 0;
}
void Player::attack(Player &other)
{
    other.vie -= damages;
}

// Fonction main

int main()
{
    Player player1("Player 1", 100, 10);
    Player player2("Player 2", 100, 20);

    if (player1.IsDead())
    {
        std::cout << player1.name << " is dead." << std::endl;
    }
    else
    {
        std::cout << player1.name << " is alive." << std::endl;
    }

    player1.attack(player2);
    std::cout << player2.name << " has " << player2.vie << " life points left." << std::endl;

    return 0;
}
