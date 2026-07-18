#include <iostream>
#include <algorithm> // pour std::max

int main()
{
    unsigned firSize = 0;
    const unsigned firMinSize = 1;
    const unsigned firMaxSize = 25;

    std::cout << "Enter the size of the fir tree (between " << firMinSize << " and " << firMaxSize << "): ";
    std::cin >> firSize;

    if (firSize < firMinSize || firSize > firMaxSize)
    {
        std::cerr << "Error: Size must be between " << firMinSize << " and " << firMaxSize << "." << std::endl;
        return -1;
    }

    std::cout << "\nHere's your fir tree:\n\n";

    // Étoile au sommet
    for (unsigned i = 0; i < firSize - 1; ++i)
        std::cout << ' ';
    std::cout << "*" << std::endl;

    // Branches du sapin (commencent à i = 2 pour éviter le doublon)
    for (unsigned i = 2; i <= firSize; ++i)
    {
        for (unsigned j = 0; j < firSize - i; ++j)
            std::cout << ' ';

        for (unsigned j = 0; j < 2 * i - 1; ++j)
            std::cout << '*';

        std::cout << std::endl;
    }

    // Tronc
    unsigned trunkHeight = std::max(1u, firSize / 4);
    for (unsigned i = 0; i < trunkHeight; ++i)
    {
        for (unsigned j = 0; j < firSize - 1; ++j)
            std::cout << ' ';
        // std::cout << "|\n";
    }

    return 0;
}
