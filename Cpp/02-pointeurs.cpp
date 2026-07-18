#include <iostream>

void Foo(int *a)
{
    if (a != nullptr)
        *a = 50;
}
int main()
{
    int a = 0;
    float b = 0;
    int *p_int = &a;     // pointeur vers un entier  // p_int --;
    float *p_float = &b; // pointeur vers un float
    // Foo(a);              // 0
    Foo(p_int); // 50
    std ::cout << a << std::endl;
    std ::cout << b << std::endl;
    std ::cout << "Adresse de a = " << p_int << std::endl;
    std ::cout << "Adresse de b = " << p_float << std::endl;
    // recupérer la valeur pointée par le pointeur
    std ::cout << "Valeur pointée par p_int = " << *p_int << std::endl;
    std ::cout << "Valeur pointée par p_float = " << *p_float << std::endl;
}
