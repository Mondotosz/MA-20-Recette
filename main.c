/**
 * \name Recette
 * \author augsburger kenan
 * \date 13.02.2020
 * \version 0.1
 * ------------------------
 * \author augsburger kenan
 * \date 14.02.2020
 * \version 0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

//constantes par recette
//                  farine  lait    biere   eau     oeufs   sel     beurre  levure
#define CLASSIQUES  {125,   0.25,   0.0,    0.0,    1.5,    0.5,    0.5,    0.0}
#define BIERE       {125.0, 0.1875, 0.0625, 0.0,    1.5,    0.5,    0.5,    0.0}
#define LEGERES     {125.0, 0.0,    0.0,    0.25,   1.5,    0.5,    0.5,    0.0}
#define GAUFFRES    {75.0,  0.125,  0.0,    0.0,    0.5,    0.5,    1.0,    2.5}
#define PANCAKE     {62.5,  0.075,  0.0,    0.0,    0.5,    0.25,   0.75,   2.5}

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

    //deduire 1 pour aligner le choix à l'array
    numeroDeRecette--;

    return numeroDeRecette;
}

/**
 *rend le nom de la recette selectionnée dans un string
 * @param numeroDeRecette
 * @return nom de la recette
 */
char *recetteChoisie(int numeroDeRecette) {
    char *nomDeRecette;

    //definir le nom selon la recette
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

    //demander le nombre de personnes tant que la valeur est inferieur a 1
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
    float classiques[] = CLASSIQUES;
    float biere[] = BIERE;
    float legeres[] = LEGERES;
    float gauffres[] = GAUFFRES;
    float pancake[] = PANCAKE;
    float proportion;

    printf("\n");
    printf("Les ingrédients nécessaires pour %d personnes sont :\n", portions);

    //calculer les proportions pour chaques ingredients et les afficher
    for (int i = 0; i < 8; ++i) {

        //recuperer la quantité pour la recette
        switch (numeroDeRecette) {
            case 0:
                proportion = classiques[i];
                break;
            case 1:
                proportion = biere[i];
                break;
            case 2:
                proportion = legeres[i];
                break;
            case 3:
                proportion = gauffres[i];
                break;
            case 4:
                proportion = pancake[i];
                break;
            default:
                printf("\n");
                printf("Le numéro de recette indiqué pour le calcul est invalide : %d\n", numeroDeRecette);
                proportion = 0;
                break;
        }

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
