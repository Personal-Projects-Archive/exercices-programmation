// Exemple simple : tri croissant (méthode bulle)
#include <iostream>
using namespace std;

int main() {
    int tableau[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    // Tri à bulles
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(tableau[j] > tableau[j + 1]) {
                // échange
                int temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    // Affichage
    cout << "Tableau trié : ";
    for(int i = 0; i < n; i++) {
        cout << tableau[i] << " ";
    }

    return 0;
}


// Version moderne (plus simple) avec la STL
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int tableau[] = {5, 2, 9, 1, 5, 6};
//     int n = 6;

//     sort(tableau, tableau + n);

//     cout << "Tableau trié : ";
//     for(int i = 0; i < n; i++) {
//         cout << tableau[i] << " ";
//     }

//     return 0;
// }
