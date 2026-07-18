#include <iostream>
#include <string>

struct Player
{
    Player();                                              // constructeur par défaut
    Player(const Player &player);                          // constructeur de copie
    Player(const std::string &name, int vie, int damages); // constructeur avec paramètres
    ~Player();                                             // destructeur

    std::string name;
    int vie;
    int damages;
    int *m_Data;

    bool IsDead()
    {
        return vie <= 0;
    }
    void attack(Player &other)
    {
        other.vie -= damages;
    }
};

Player::Player() : name(""), vie(100), damages(10), m_Data(nullptr) { m_Data = new int(); }                                // constructeur par défaut
Player::Player(const Player &player) : name(player.name), vie(player.vie), damages(player.damages), m_Data(nullptr) {}     // constructeur de copie
Player::Player(const std::string &name, int vie, int damages) : name(name), vie(vie), damages(damages), m_Data(nullptr) {} // constructeur avec paramètres
Player::~Player()                                                                                                          // destructeur
{
    if (m_Data != nullptr)
        // std::cout << "Destructor"<< std::endl; // plutôt ne rien faire
        delete m_Data; // libérer la mémoire allouée
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        Player player0; // risque de fuite mémoire si pas de destructeur
    }
    // instance of Player
    Player player1("Player 1", 100, 10); // utilisation du constructeur avec paramètres
    Player player2("Player 2", 100, 20); // utilisation du constructeur avec paramètres
    if (player1.IsDead())
    {
        std::cout << player1.name << " is dead." << std::endl;
    }
    else
    {
        std::cout << player1.name << " is alive." << std::endl;
    }

    player1.attack(player2);
    std ::cout << player2.name << " has " << player2.vie << " life points left." << std::endl;
    return 0;
}
