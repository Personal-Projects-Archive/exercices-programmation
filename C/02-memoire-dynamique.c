#include <stdio.h>
#include <stdlib.h>   // malloc, calloc, realloc, free

// Fiche révision : mémoire avancée et tableaux dynamiques

int main() {

    // 1. Différence mémoire statique vs dynamique

    // STATIQUE (taille fixe, pile / stack)
    int tabStatique[3] = {1, 2, 3};

    // DYNAMIQUE (taille décidée à l'exécution, tas / heap)
    int *tab = malloc(3 * sizeof(int));  // réserve mémoire pour 3 entiers

    if(tab == NULL) {
        printf("Erreur allocation mémoire\n");
        return 1;
    }

    // 2. Utiliser un tableau dynamique

    for(int i = 0; i < 3; i++) {
        tab[i] = (i + 1) * 10;  // 10, 20, 30
    }

    printf("Tableau dynamique initial : ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // 3. Realloc : agrandir le tableau

    tab = realloc(tab, 5 * sizeof(int));  // on passe de 3 à 5 cases

    if(tab == NULL) {
        printf("Erreur realloc\n");
        return 1;
    }

    tab[3] = 40;
    tab[4] = 50;

    printf("Après realloc : ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // 4. Calloc (initialise à 0)

    int *zeros = calloc(4, sizeof(int));  // 4 entiers initialisés à 0

    printf("calloc : ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");

    // 5. Pointeurs et adresses

    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("Adresse de x = %p\n", &x);
    printf("p pointe vers = %p\n", p);
    printf("Valeur pointée par p = %d\n", *p);

    // 6. Tableau dynamique 2D (matrice)

    int lignes = 2, colonnes = 3;
    int **mat = malloc(lignes * sizeof(int*));

    for(int i = 0; i < lignes; i++) {
        mat[i] = malloc(colonnes * sizeof(int));
    }

    mat[0][0] = 1;
    mat[1][2] = 9;

    printf("Matrice[1][2] = %d\n", mat[1][2]);

    // 7. Libération mémoire (très important)

    free(tab);
    free(zeros);

    for(int i = 0; i < lignes; i++) {
        free(mat[i]);
    }
    free(mat);

    printf("Mémoire libérée correctement\n");

    return 0;
}

// int x = 10;
// int *p = &x;

// free(p);  // ERREUR GRAVE : double free si on refait free(p) plus bas

// free(p);
// p = NULL;   // bonne pratique après un free
