/**
 * \name Recette
 * \author augsburger kenan
 * \date 13.02.2020
 * \version 0.1
 * ------------------------
 * \author augsburger kenan
 * \date 14.02.2020
 * \version 0.2
 * ------------------------
 * \name Recette array 2d
 * \author augsburger kenan
 * \date 14.02.2020
 * \version 0.3
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

#define NOMBRE_DE_RECETTES 5
#define NOMBRE_D_INGREDIENTS 8

//                                                                 farine,lait,   biere,  eau, oeufs,sel,beurre,levure
const float RECETTES[NOMBRE_DE_RECETTES][NOMBRE_D_INGREDIENTS] = {{125.0, 0.25,   0.0,    0.0,  1.5, 0.5,  0.5,  0.0},/*Classique*/
                                                                  {125.0, 0.1875, 0.0625, 0.0,  1.5, 0.5,  0.5,  0.0},/*Biere*/
                                                                  {125.0, 0.0,    0.0,    0.25, 1.5, 0.5,  0.5,  0.0},/*Legeres*/
                                                                  {75.0,  0.125,  0.0,    0.0,  0.5, 0.5,  1.0,  2.5},/*Gauffres*/
                                                                  {62.5,  0.075,  0.0,    0.0,  0.5, 0.25, 0.75, 2.5}};/*Pancake*/

/**
 * demander la recette souhaitée
 * @return numéro de recette
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
    printf("4 - gauffres\n");
    printf("5 - pancake\n");
    printf("Faites votre choix :");

    //attendre un choix valide
    do {
        fflush(stdin);
        scanf("%d", &numeroDeRecette);
    } while (numeroDeRecette < 1 || numeroDeRecette > 5);

    //déduire 1 pour aligner le choix à l'array
    numeroDeRecette--;

    return numeroDeRecette;
}

/**
 *rend le nom de la recette sélectionnée dans un string
 * @param numeroDeRecette
 * @return nom de la recette
 */
char *recetteChoisie(int numeroDeRecette) {
    char *nomDeRecette;

    //définir le nom selon la recette
    switch (numeroDeRecette) {
        case 0:
            nomDeRecette = "crêpes classiques";
            break;
        case 1:
            nomDeRecette = "crêpes a la bière";
            break;
        case 2:
            nomDeRecette = "crêpes légères";
            break;
        case 3:
            nomDeRecette = "gauffres";
            break;
        case 4:
            nomDeRecette = "pancake";
            break;
        default:
            nomDeRecette = "erreur";
    }

    //confirmer la selection
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", nomDeRecette);

    return nomDeRecette;
}

/**
 * demande le nombre de personnes
 * @param nomDeRecette    pour l'affichage
 * @return nombre de portions
 */
int nombreDePersonnes(char *nomDeRecette) {
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
 * calculer et afficher les proportions pour la recette souhaitée
 * @param numeroDeRecette
 * @param portions
 */
void calculDeProportions(int numeroDeRecette, int portions) {
    float proportion;

    printf("\n");
    printf("Les ingrédients nécessaires pour %d personnes sont :\n", portions);

    //calculer les proportions pour chaque ingredients et les afficher
    for (int i = 0; i < 8; ++i) {

        //récupérer la quantité pour la recette
        proportion=RECETTES[numeroDeRecette][i];

        //calculer la quantité nécessaire
        proportion *= portions;

        //retourner la quantité dans le bon format si elle est supérieure a 0
        if (proportion > 0)
            switch (i) {
                case 0:
                    printf("Farine : %.2f g\n", proportion);
                    break;
                case 1:
                    printf("Lait : %.2f l\n", proportion);
                    break;
                case 2:
                    printf("Bière : %.2f l\n", proportion);
                    break;
                case 3:
                    printf("Eau : %.2f l\n", proportion);
                    break;
                case 4:
                    printf("Oeufs : %.f\n", proportion);
                    break;
                case 5:
                    printf("Sel : %.f pincées\n", proportion);
                    break;
                case 6:
                    printf("Beurre : %.f cuillères\n", proportion);
                    break;
                case 7:
                    printf("Levure : %.f g\n", proportion);
                    break;
                default:
                    printf("Ingrédient non reconnu : %d\n", i);
            }
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
    int numeroDeRecette, portions;
    char *nomDeRecette;
    SetConsoleOutputCP(65001);

    //choisir une recette
    numeroDeRecette = choixDeRecette();
    //confirmer la recette et récupérer son nom
    nomDeRecette = recetteChoisie(numeroDeRecette);
    //demander le nombre de portions
    portions = nombreDePersonnes(nomDeRecette);
    //calculer les proportions
    calculDeProportions(numeroDeRecette, portions);

    system("pause");
    return 0;
}
