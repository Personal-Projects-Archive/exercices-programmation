#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, free
#include <string.h>   // strcpy, strlen

// Fonctions

// Fonction simple
int addition(int a, int b) {
    return a + b;
}

// Fonction avec pointeur (modifie la variable originale)
void doubler(int *x) {
    *x = *x * 2;
}

// Structure
struct Joueur {
    char nom[20];
    int score;
};

// Programme principal
int main() {

    // Variables
    int age = 20;
    float taille = 1.75;
    char lettre = 'A';

    printf("Age : %d, Taille: %.2f, Lettre: %c\n", age, taille, lettre);

    // Conditions
    if(age >= 18) {
        printf("Majeur\n");
    } else {
        printf("Mineur\n");
    }

    // Boucle for
    for(int i = 0; i < 3; i++) {
        printf("i = %d\n", i);
    }

    // Tableau
    int notes[3] = {12, 15, 18};
    printf("Premiere note: %d\n", notes[0]);

    // Chaînes de caractères
    char mot[20] = "Bonjour";
    printf("Longueur mot: %lu\n", strlen(mot));

    // Pointeurs
    int x = 5;
    int *p = &x;      // p contient l'adresse de x
    printf("Valeur de x via pointeur: %d\n", *p);

    doubler(&x);
    printf("x double = %d\n", x);

    // Allocation dynamique
    int *tab = malloc(3 * sizeof(int));
    tab[0] = 10;
    tab[1] = 20;
    tab[2] = 30;
    printf("malloc tab[1] = %d\n", tab[1]);
    free(tab);   // libérer la mémoire

    // Structures
    struct Joueur j1;
    strcpy(j1.nom, "Alex");
    j1.score = 100;
    printf("Joueur: %s, Score: %d\n", j1.nom, j1.score);

    // Fonction
    int resultat = addition(4, 6);
    printf("Addition = %d\n", resultat);

    // Fichiers
    FILE *f = fopen("test.txt", "w");
    if(f != NULL) {
        fprintf(f, "Hello fichier!\n");
        fclose(f);
    }

    return 0;
}
// | Fonction  | Signification                 |
// | --------- | ----------------------------- |
// | `printf`  | print formatted (écran)       |
// | `fprintf` | file print formatted          |
// | `scanf`   | lire clavier                  |
// | `fscanf`  | lire depuis fichier           |
// | `getc`    | lire caractère                |
// | `fgetc`   | lire caractère depuis fichier |
