#include <iostream>
// #include <ctime>
// fonction
int pow_custom(int base, int exponent);
int addition(int a, int b);
float addition(float a, float b);
int main()
{
    std ::cout << "5^3 = " << pow_custom(5, 3) << std::endl;
    std ::cout << "5+10 = " << addition(5, 10) << std::endl;
    std::cout << "5.5 + 10.5 = " << addition(5.5f, 10.5f) << std::endl;
    // jeu devine un nombre mystère
    int mystery_number = std ::rand() % 100 + 1; // Generate a random number between 1 and 100
    int max_try = 6;

    for (int i = 0; i < max_try; ++i)
    {
        std ::cout << "Guess the mystery number (between 1 and 100): ";
        int number = 0;
        std ::cin >> number;
        if (mystery_number == number)
        {
            std::cout << "Congratulations! You guessed the mystery number!" << std::endl;
            break; // Exit the loop if the guess is correct
        }
        else if (number < mystery_number)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else
        {
            std::cout << "Too high! Try again." << std::endl;
        }
        if (i == max_try - 1)
        {
            std::cout << "Sorry, you've used all your tries. The mystery number was " << mystery_number << "." << std::endl;
        }
    }

    return 0;
}

int pow_custom(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

int addition(int a, int b)
{
    return a + b;
}
// surcharge de fonction
float addition(float a, float b)
{
    return a + b;
}
