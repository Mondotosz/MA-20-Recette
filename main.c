/**
 * \name Recette struct v3
 * \author augsburger kenan
 * \date 26.02.2020
 * \version 0.5
 */

//TODO:fix this
//TODO:remove arrays from structs

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#pragma execution_character_set("utf-8")

#define NOMBRE_DE_RECETTES 5
#define NOMBRE_D_INGREDIENTS 8
#define LONGUEURE_MAX_NOM 30

typedef struct {
    char nom[LONGUEURE_MAX_NOM];
    float quantite[NOMBRE_D_INGREDIENTS];
} bettyBossy;
//                                                recette,             farine, lait,    bière,   eau,   oeufs,sel,   beurre,levure
const bettyBossy recette[NOMBRE_DE_RECETTES] = {{"crêpes classiques", {125.0f, 0.25f,   0.0f,    0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"crêpes à la bière", {125.0f, 0.1875f, 0.0625f, 0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"crêpes légères",    {125.0f, 0.0f,    0.0f,    0.25f, 1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"gaufres",           {75.0f,  0.125f,  0.0f,    0.0f,  0.5f, 0.5f,  1.0f,  2.5f}},
                                                {"pancakes",          {62.5f,  0.075f,  0.0f,    0.0f,  0.5f, 0.25f, 0.75f, 2.5f}}};

// stock les choix fait pour un usage future
typedef struct {
    int numeroDeRecette;
    char nom[LONGUEURE_MAX_NOM];
    int portions;
    float quantite[NOMBRE_D_INGREDIENTS];
} choix;

// permet d'afficher l'ingredient avec son unité
typedef struct {
    char nom[10];
    char unite[15];
} ingredients;
//                                                     ingrédient unité
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
int choixDeRecette() {
    int numeroDeRecette;

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
        scanf("%d", &numeroDeRecette);
    } while (numeroDeRecette < 1 || numeroDeRecette > NOMBRE_DE_RECETTES);

    //déduire 1 pour aligner le choix à l'array
    numeroDeRecette--;

    return numeroDeRecette;
}

/**
 *rend le nom de la recette sélectionnée dans un string
 * @param numeroDeRecette
 * @return nom de la recette
 */
char *nomDeRecette(int numeroDeRecette) {
    char nomDeRecette[LONGUEURE_MAX_NOM];

    strcpy(nomDeRecette, recette[numeroDeRecette].nom);

    //confirmer la selection
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", nomDeRecette);

    return nomDeRecette;
}

/**
 * demander le nombre de personnes et le stocker dans recetteChoisie
 */
int nombreDePersonnes(char nomDeRecette[LONGUEURE_MAX_NOM]) {
    int portions;
    printf("\n");
    printf("Entrez le nombre de personnes qui mangeront des %s :", nomDeRecette);

    //demander le nombre de personnes tant que la valeur est inférieur a 1
    do {
        fflush(stdin);
        scanf("%d", &portions);
    } while (portions < 1);

    return portions;
}

/**
 * calculer, stocker et afficher les proportions pour la recette souhaitée
 */
float *calculDeProportions(int numeroDeRecette, int portions) {
    float *quantite;
//    printf("\n");
//    printf("Les ingrédients nécessaires pour %d personnes sont :\n", recetteChoisie.portions);

    //calculer les proportions pour chaque ingredients et les afficher
    for (int i = 0; i < NOMBRE_D_INGREDIENTS; ++i) {

        //récupérer la quantité pour la recette
        quantite[i] = recette[numeroDeRecette].quantite[i];

        //calculer la quantité nécessaire
        quantite[i] *= portions;

//        //retourner la quantité dans le bon format si elle est supérieure a 0
//        if (recetteChoisie.quantite[i] > 0)
//            printf("%s : %g %s\n", ingredient[i].nom, recetteChoisie.quantite[i], ingredient[i].unite);
//
    }

    return quantite;

//    //feedback de fin de fonction
//    printf("\n");
//    printf("Bonne dégustation !\n");
}

/**
 * programme principal
 * @return 0
 */
int main() {

    choix recetteChoisie;

    SetConsoleOutputCP(65001);

    //choisir une recette
    recetteChoisie.numeroDeRecette=choixDeRecette();
    //récupérer le nom de la recette
    strcpy(recetteChoisie.nom,nomDeRecette(recetteChoisie.numeroDeRecette));
    //demander le nombre de portions
    recetteChoisie.portions=nombreDePersonnes(recetteChoisie.nom);
    //calculer les proportions
    memcpy(recetteChoisie.quantite,calculDeProportions(recetteChoisie.numeroDeRecette,recetteChoisie.portions),NOMBRE_D_INGREDIENTS);

    system("pause");
    return 0;
}
