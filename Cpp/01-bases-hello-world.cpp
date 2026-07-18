#include <iostream>
int main()
{
    // type name ;
    // char - character -   'r'
    // int - integer - 1, 2, 3, 4, 5
    // float - floating point - 1.0f, 2.5f, 3.14f
    // double - double precision floating point - 1.0, 2.5, 3.14
    // This is a simple C++ program that prints "Hello, World!" to the console.
    // age
    std::cout << "Hello, World!" << std::endl;
    int age = 0;
    std::cout << "How old are you?" << std::endl;
    std ::cin >> age;
    // std::cin.ignore();

    std::cout << "You are " << age << " years old." << std::endl;
    // std::cin.ignore();

    float mark = 1;
    double height = 1.75;
    // operateur // + - * / % ++ -- += -= *= /= %= & |
    int a = 5;
    int b = 10;
    std::cout << a + b << std::endl;
    // std::cin.ignore();
    //  Return 0 to indicate successful execution
    int c = 0;
    int d = 0;
    std::cout << "Enter c then d";
    std::cin >> c >> d;
    // std::cin.ignore();
    std::cout << "c + d = " << c + d << std::endl;
    // std::cin.ignore();
    // les conditions
    float average = 0.0f;
    std::cout << "Enter your average: ";
    std ::cin >> average;
    if (average == 20.0f)
    {
        std::cout << "Félicitation" << std::endl;
    }
    else if (average >= 16.0f)
    {
        std ::cout << "très bien" << std::endl;
    }
    else if (average >= 14.0f)
    {
        std::cout << "Bien" << std::endl;
    }
    else if (average >= 12.0f)
    {
        std::cout << "Assez bien" << std::endl;
    }

    else
    {
        std::cout << "Pas de mention" << std::endl;
    }
    int age2 = 0;
    std::cout << "Enter your age: " << std::endl;
    std::cin >> age2;

    if (age2 < 18)
    {
        std ::cout << "you are a minor" << std ::endl;
    }
    else
    {
        std ::cout << "you are an adult" << std ::endl;
    }
    // condition ternaire
    std::cout << "You are " << (age2 < 18 ? "a minor" : "an adult") << std::endl;

    // operateur logique
    bool isStudent = true;
    int age3 = 10;
    if (age3 > 16 || isStudent && age >= 10)
    {
        std ::cout << "Autorisé";
    }
    else
    {
        std ::cout << "non autorisé";
    }
    // les boucles
    int N = 0;
    std::cout << "Enter a number: ";
    std::cin >> N;
    for (int i = 0; i <= N; ++i)
    {
        std::cout << i << std::endl;
    }
    int table = 0;
    std::cout << "Enter a number for the multiplication table: ";
    std::cin >> table;
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << table << " x " << i << " = " << table * i << std::endl;
    }
    // Suite géométrique
    int u = 4;
    int r = 3;
    int z = 0;
    std::cout << "Enter the number of terms in the geometric sequence: ";
    std::cin >> z;
    for (int i = 0; i < z; ++i)
    {
        u *= r; // Multiplie u par r à chaque itération
    }
    std ::cout << u << std ::endl;
    int h = 0;
    while (h != 0)
    {
        std::cout << "Enter a number (0 to exit): ";
        std ::cin >> h;
    }
    do
    {
        std::cout << "Enter a number (0 to exit): ";
        std ::cin >> h;
    } while (h == 0);

    return 0;
}
