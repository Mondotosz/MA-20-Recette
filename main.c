/**
 * \name Recette struct v2
 * \author augsburger kenan
 * \date 17.02.2020
 * \version 0.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#pragma execution_character_set("utf-8")

#define NOMBRE_DE_RECETTES 5
#define NOMBRE_D_INGREDIENTS 8

typedef struct {
    char nom[30];
    float quantite[NOMBRE_D_INGREDIENTS];
} bettyBossy;
//                                                      recette,                  farine,           lait,              bière,              eau,              oeufs,           sel,              beurre,           levure
const bettyBossy recette[NOMBRE_DE_RECETTES] = {{"crêpes classiques", {125.0f, 0.25f,   0.0f,    0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"crêpes à la bière", {125.0f, 0.1875f, 0.0625f, 0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"crêpes légères",    {125.0f, 0.0f,    0.0f,    0.25f, 1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"gaufres",           {75.0f,  0.125f,  0.0f,    0.0f,  0.5f, 0.5f,  1.0f,  2.5f}},
                                                {"pancakes",          {62.5f,  0.075f,  0.0f,    0.0f,  0.5f, 0.25f, 0.75f, 2.5f}}};

// stock les choix fait pour un usage future
typedef struct {
    int numeroDeRecette;
    char nom[10];
    int portions;
    float quantite[NOMBRE_D_INGREDIENTS];
} choix;

choix recetteChoisie;

// permet d'afficher l'ingredient avec son unité
typedef struct {
    char nom[10];
    char unite[15];
} ingredients;

const ingredients ingredient[NOMBRE_D_INGREDIENTS] = {{"Farine", "g"},
                                                      {"Lait",   "l"},
                                                      {"Bière",  "l"},
                                                      {"Eau",    "l"},
                                                      {"Oeufs",  ""},
                                                      {"Sel",    "pincées"},
                                                      {"Beurre", "cuillères"},
                                                      {"Levure", "g"}};

/**
 * demander la recette souhaitée et stocker son numéro
 */
void choixDeRecette() {

    //afficher les choix
    printf("---- CHANDELEUR 2 le retour ----\n");
    printf("\n");
    printf("\n");
    printf("Choisissez la recette que vous souhaiteriez faire :\n");
    printf("1 - crêpes classiques\n");
    printf("2 - crêpes a la bière\n");
    printf("3 - crêpes légères\n");
    printf("4 - gaufres\n");
    printf("5 - pancake\n");
    printf("Faites votre choix :");

    //attendre un choix valide
    do {
        fflush(stdin);
        scanf("%d", &recetteChoisie.numeroDeRecette);
    } while (recetteChoisie.numeroDeRecette < 1 || recetteChoisie.numeroDeRecette > NOMBRE_DE_RECETTES);

    //déduire 1 pour aligner le choix à l'array
    recetteChoisie.numeroDeRecette--;

    //stocker et confirmer la sélection
    strcpy(recetteChoisie.nom, recette[recetteChoisie.numeroDeRecette].nom);
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", recetteChoisie.nom);

}

/**
 * demander le nombre de personnes et le stocker dans recetteChoisie
 */
void nombreDePersonnes() {

    printf("\n");
    printf("Entrez le nombre de personnes qui mangeront des %s :", recetteChoisie.nom);

    //demander le nombre de personnes tant que la valeur est inférieur a 1
    do {
        fflush(stdin);
        scanf("%d", &recetteChoisie.portions);
    } while (recetteChoisie.portions < 1);

}

/**
 * calculer, stocker et afficher les proportions pour la recette souhaitée
 */
void calculDeProportions() {

    printf("\n");
    printf("Les ingrédients nécessaires pour %d personnes sont :\n", recetteChoisie.portions);

    //calculer les proportions pour chaque ingredients et les afficher
    for (int i = 0; i < 8; ++i) {

        //récupérer la quantité pour la recette
        recetteChoisie.quantite[i] = recette[recetteChoisie.numeroDeRecette].quantite[i];

        //calculer la quantité nécessaire
        recetteChoisie.quantite[i] *= recetteChoisie.portions;

        //retourner la quantité dans le bon format si elle est supérieure a 0
        if (recetteChoisie.quantite[i] > 0)
            printf("%s : %g %s\n", ingredient[i].nom, recetteChoisie.quantite[i], ingredient[i].unite);

    }

    //feedback de fin de fonction
    printf("\n");
    printf("Bonne dégustation !\n");
}

/**
 * programme principal
 * @return 0
 */
int main() {
    SetConsoleOutputCP(65001);

    //choisir une recette
    choixDeRecette();
    //demander le nombre de portions
    nombreDePersonnes();
    //calculer les proportions
    calculDeProportions();

    system("pause");
    return 0;
}
