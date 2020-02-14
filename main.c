/**
 * \name Recette
 * \author augsburger kenan
 * \date 13.02.2020
 * \version 0.1
 */

#include <stdio.h>
#include <stdlib.h>

//constantes par recettes (farine/lait/biere/eau/oeufs/sel/beurre/levure)
const float CLASSIQUES[8] = {125, 0.25f, 0, 0, 1.5f, 0.5f, 0.5f, 0};
const float BIERE[8] = {125, 0.1875f, 0.0625f, 0, 1.5f, 0.5f, 0.5f, 0};
const float LEGERES[8] = {125, 0, 0, 0.25f, 1.5f, 0.5f, 0.5f, 0};
const float GAUFFRES[8] = {75, 0.125f, 0, 0, 0.5f, 0.5f, 1, 2.5f};
const float PANCAKE[8] = {62.5f, 0.075f, 0, 0, 0.5f, 0.25f, 0.75f, 2.5f};

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
    float temp;

    printf("\n");
    printf("Les ingredients necessaires pour %d personnes sont :\n", portions);

    for (int i = 0; i < 8; ++i) {
        switch (recette) {
            case 0:
                temp = CLASSIQUES[i] * portions;
                break;
            case 1:
                temp = BIERE[i] * portions;
                break;
            case 2:
                temp = LEGERES[i] * portions;
                break;
            case 3:
                temp = GAUFFRES[i] * portions;
                break;
            case 4:
                temp = PANCAKE[i] * portions;
                break;
            default:
                printf("\n");
                printf("Erreur choix de recette invalid lors du calcul\n");
                break;
        }

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

    recette = choixRecette();
    nomRecette = recetteChoisie(recette);
    portions = nombrePersonnes(nomRecette);
    calculProportions(recette, portions);

    system("pause");
    return 0;
}
