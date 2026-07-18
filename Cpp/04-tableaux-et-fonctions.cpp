#include <iostream>
void computetable(int table, int output[11])
{
    for (int i = 0; i <= 10; ++i)
    {
        output[i] = table * i;
    }
}
void printtable(int output[11])
{
    for (int i = 0; i <= 10; ++i)
    {
        std::cout << output[i] << std::endl;
    }
}
// les pointeurs
int a = 0;
float b = 0;
int *p_int = &a;     // pointeur vers un entier
float *p_float = &b; // pointeur vers un float
int main()
{
    std ::cout << a << std::endl;
    std ::cout << b << std::endl;
    std ::cout << p_int << std::endl;
    std ::cout << p_float << std::endl;
    int table[11] = {0};
    computetable(5, table);
    printtable(table);

    return 0;
}
