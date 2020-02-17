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
 * ------------------------
 * \name Recette struct v1
 * \author augsburger kenan
 * \date 17.02.2020
 * \version 0.3
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

#define NOMBRE_DE_RECETTES 5
#define NOMBRE_D_INGREDIENTS 8

typedef struct {
    char nom[10];
    float ingredient[NOMBRE_D_INGREDIENTS];
} bettyBossy;
//                                                      recette,                  farine,             lait,                 bière,               eau,               oeufs,             sel,               beurre,            levure
const bettyBossy recette[NOMBRE_DE_RECETTES] = {{"classiques", {125.0f, 0.25f,   0.0f,    0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"bière",      {125.0f, 0.1875f, 0.0625f, 0.0f,  1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"légères",    {125.0f, 0.0f,    0.0f,    0.25f, 1.5f, 0.5f,  0.5f,  0.0f}},
                                                {"gaufres",    {75.0f,  0.125f,  0.0f,    0.0f,  0.5f, 0.5f,  1.0f,  2.5f}},
                                                {"pancakes",   {62.5f,  0.075f,  0.0f,    0.0f,  0.5f, 0.25f, 0.75f, 2.5f}}};

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

    //confirmer la selection
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", recette[numeroDeRecette].nom);

    return numeroDeRecette;
}

/**
 * demande le nombre de personnes
 * @param numeroDeRecette  pour l'affichage
 * @return nombre de portions
 */
int nombreDePersonnes(int numeroDeRecette) {
    int portions;

    printf("\n");
    printf("Entrez le nombre de personnes qui mangeront des %s :", recette[numeroDeRecette].nom);

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
        proportion = recette[numeroDeRecette].ingredient[i];

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
    SetConsoleOutputCP(65001);

    //choisir une recette
    numeroDeRecette = choixDeRecette();
    //demander le nombre de portions
    portions = nombreDePersonnes(numeroDeRecette);
    //calculer les proportions
    calculDeProportions(numeroDeRecette, portions);

    system("pause");
    return 0;
}
