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

/**
 * to do
 * replace const with define
 * change char * to char [x] to avoid overwriting memory info
 * rethink names
 */

#include <stdio.h>
#include <stdlib.h>

//constantes par recettes
//                  farine  lait    biere   eau     oeufs   sel     beurre  levure
#define CLASSIQUES  {125,   0.25,   0.0,    0.0,    1.5,    0.5,    0.5,    0.0}
#define BIERE       {125.0, 0.1875, 0.0625, 0.0,    1.5,    0.5,    0.5,    0.0}
#define LEGERES     {125.0, 0.0,    0.0,    0.25,   1.5,    0.5,    0.5,    0.0}
#define GAUFFRES    {75.0,  0.125,  0.0,    0.0,    0.5,    0.5,    1.0,    2.5}
#define PANCAKE     {62.5,  0.075,  0.0,    0.0,    0.5,    0.25,   0.75,   2.5}

/**
 * demande la recette souhaitee
 * @return numero de recette
 */
int choixRecette() {
    int recette;

    //affiche les choix
    printf("---- CHANDELEUR 2 le retour ----\n");
    printf("\n");
    printf("\n");
    printf("Choisissez la recette que vous souhaiteriez faire :\n");
    printf("1 - crepes classiques\n");
    printf("2 - crepes a la biere\n");
    printf("3 - crepes legeres\n");
    printf("4 - gauffres\n");
    printf("5 - pancake\n");
    printf("Faites votre choix :");

    //attend un choix valide
    do {
        fflush(stdin);
        scanf("%d", &recette);
    } while (recette < 1 || recette > 5);

    //deduit un a la recette pour s'aligner au 0 des arrays
    recette--;

    return recette;
}

/**
 *rend le nom de la recette selectionnee dans un string
 * @param recette
 * @return nom de la recette
 */
char *recetteChoisie(int recette) {
    char *nomRecette;

    //definit le nom selon la recette
    switch (recette) {
        case 0:
            nomRecette = "crepes classiques";
            break;
        case 1:
            nomRecette = "crepes a la biere";
            break;
        case 2:
            nomRecette = "crepes legeres";
            break;
        case 3:
            nomRecette = "gauffres";
            break;
        case 4:
            nomRecette = "pancake";
            break;
        default:
            nomRecette = "erreur";
    }

    //feedback
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", nomRecette);

    return nomRecette;
}

/**
 * demande le nombre de portions
 * @param nomRecette    pour l'affichage
 * @return nombre de personnes
 */
int nombrePersonnes(char *nomRecette) {
    int nombreDePersonnes;

    printf("\n");
    printf("Entrez le nombre de personnes qui mangeront des %s :", nomRecette);

    //demande le nombre de personnes tant que la valeur est inferieur a 1
    do {
        fflush(stdin);
        scanf("%d", &nombreDePersonnes);
    } while (nombreDePersonnes < 1);

    return nombreDePersonnes;
}

/**
 * calcul et affiche les proportions pour la recette souhaitee
 * @param recette
 * @param portions
 */
void calculProportions(int recette, int portions) {
    float classiques[] = CLASSIQUES;
    float biere[] = BIERE;
    float legeres[] = LEGERES;
    float gauffres[] = GAUFFRES;
    float pancake[] = PANCAKE;
    float temp;

    printf("\n");
    printf("Les ingredients necessaires pour %d personnes sont :\n", portions);

    //calcul les proportions pour chaque ingredients et les affiche
    for (int i = 0; i < 8; ++i) {

        //recuperer la quantite
        switch (recette) {
            case 0:
                temp = classiques[i];
                break;
            case 1:
                temp = biere[i];
                break;
            case 2:
                temp = legeres[i];
                break;
            case 3:
                temp = gauffres[i];
                break;
            case 4:
                temp = pancake[i];
                break;
            default:
                printf("\n");
                printf("Erreur choix de recette invalid lors du calcul\n");
                break;
        }

        //calcule la quantite necessaire
        temp *= portions;

        //retourne la quantite dans le bon format si elle est superieure a 0
        if (temp > 0)
            switch (i) {
                case 0:
                    printf("Farine : %.2f g\n", temp);
                    break;
                case 1:
                    printf("Lait : %.2f l\n", temp);
                    break;
                case 2:
                    printf("Biere : %.2f l\n", temp);
                    break;
                case 3:
                    printf("Eau : %.2f l\n", temp);
                    break;
                case 4:
                    printf("Oeufs : %.f\n", temp);
                    break;
                case 5:
                    printf("Sel : %.f pincees\n", temp);
                    break;
                case 6:
                    printf("Beurre : %.f cuilleres\n", temp);
                    break;
                case 7:
                    printf("Levure : %.f g\n", temp);
                    break;
                default:
                    printf("erreur lors de l'affichage des quantites\n");
            }
    }

    //feedback de fin de fonction
    printf("\n");
    printf("Bonne degustation !\n");
}

/**
 * programme principal
 * @return 0
 */
int main() {
    int recette, portions;
    char *nomRecette;

    //choisir la recette
    recette = choixRecette();
    //confirmeer la recette et sortir son nom
    nomRecette = recetteChoisie(recette);
    //demander le nombre de portions
    portions = nombrePersonnes(nomRecette);
    //calculer les proportions
    calculProportions(recette, portions);

    system("pause");
    return 0;
}
