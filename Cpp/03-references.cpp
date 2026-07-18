#include <iostream>
#include <stdexcept>

void Foo(int &b)
{
    b = 50; // modifie la valeur de a
}
void Foo(int *b) // const pour pas modifier la valeur de a
{
    if (b != nullptr)
        *b = 50; // modifie la valeur pointée par a
}

int *foo();
int &ref_foo();

int main()
{
    const int *const ptrConst = nullptr; // s'applique à l'élément à gauche et à droite
    int a = 0;
    int b = 5;
    Foo(b);
    std ::cout << b << std::endl;
    // pointeur vers un entier
    int *ptr = &a; // peut ne pas être initialisé et peut être nul
    // référence
    int &ref = a; // ref initialisation obligatoire
    std::cout << ref << std::endl;
    std::cout << sizeof(ref) << std::endl;

    if (!foo())
    {
        std::cout << "Not Found" << std::endl;
    }
}

int *foo()
{
    //...
    return nullptr;
}

int &ref_foo()
{
    //...
    throw std::runtime_error("Not Found"); // throw une exception
}
// lvalue reference
// int a = 0;
// int & b = a; // b est une référence à a
// b = a;
// revalue reference
// int && b = a; pour
