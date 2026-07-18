#include <iostream>
#include <string>
// public
// private
// protected
// preferable les structures pour les données
struct Player
{
    std::string name;
    int vie;
    int damages;
    bool IsDead()
    {
        return vie <= 0;
    }
    void attack(Player &other)
    {
        other.vie -= damages;
    }
};

int main()
{
    // instance of Player
    Player player1;
    Player player2;
    player1.name = "Player 1";
    player1.vie = 100;
    std::cout << player1.name << std::endl;
    if (player1.IsDead())
    {
        std::cout << player1.name << " is dead." << std::endl;
    }
    else
    {
        std::cout << player1.name << " is alive." << std::endl;
    }
    player2.name = "Player 2";
    player2.vie = 100;
    player2.damages = 20;
    player1.attack(player2);
    std ::cout << player2.name << " has " << player2.vie << " life points left." << std::endl;
    return 0;
}
