#include <iostream>
#include <string>

class Player
{
public:
    Player();                                              // constructeur par défaut
    Player(const Player &player);                          // constructeur de copie
    Player(const std::string &name, int vie, int damages); // constructeur avec paramètres
    ~Player();                                             // destructeur
    bool IsDead();
    void attack(Player &other);
    const std::string &getName() const;
    int getVie() const;
    int getDamages() const;
    void setDamages(int damages);

private:
    std::string name;
    int vie;
    int damages;
    int *m_Data;
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

bool Player::IsDead()
{
    return vie <= 0;
}

void Player::attack(Player &other)
{
    other.vie -= damages;
}
const std::string &Player::getName() const
{
    return name;
}
int Player::getVie() const
{
    return vie;
}
int Player::getDamages() const
{
    return damages;
}
void Player::setDamages(int damages)
{
    this->damages = damages;
}
int main()
{
    // instance of Player
    Player player1("Player 1", 100, 10); // utilisation du constructeur avec paramètres
    Player player2("Player 2", 100, 20); // utilisation du constructeur avec paramètres
    std::cout << player1.getName() << std::endl;
    player1.setDamages(10);
    if (player1.IsDead())
    {
        std::cout << player1.getName() << " is dead." << std::endl;
    }
    else
    {
        std::cout << player1.getName() << " is alive." << std::endl;
    }

    player1.attack(player2);
    std ::cout << player2.getName() << " has " << player2.getVie() << " life points left." << std::endl;
    return 0;
}
