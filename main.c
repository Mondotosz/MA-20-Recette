/**
 * \name Recette struct v3
 * \author augsburger kenan
 * \date 26.02.2020
 * \version 1.0
 */

//TODO:spell check

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

#define MAX_NAME_LENGTH 30
#define MAX_RECIPE_ID 5

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float flour;
    float milk;
    float beer;
    float water;
    float egg;
    float salt;
    float butter;
    float yeast;
    int portions;
} recipe;

//available recipes
const recipe classic = {1, "crêpes classiques", 125.f, 0.25f, 0.f, 0.f, 1.5f, 0.5f, 0.5f, 0.f, 1};
const recipe beer = {2, "crêpes à la bière", 125.f, 0.1875f, 0.0625f, 0.f, 1.5f, 0.5f, 0.5f, 0.f, 1};
const recipe light = {3, "crêpes légères", 125.f, 0.f, 0.f, 0.25f, 1.5f, 0.5f, 0.5f, 0.f, 1};
const recipe waffle = {4, "gaufres", 75.f, 0.125f, 0.f, 0.f, 0.5f, 0.5f, 1.f, 2.5f, 1};
const recipe pancake = {5, "pancakes", 62.5f, 0.075f, 0.f, 0.f, 0.5f, 0.25f, 0.75f, 2.5f, 1};

/**
 * displays the title
 */
void displayTitle(){
    printf("---- CHANDELEUR 2 le retour ----\n");
    printf("\n");
}

/**
 * ask for a recipe id and returns it
 * @param recipeID
 * @return recipe with an id
 */
recipe getRecipeID(recipe recipeID) {

    //displays available recipes
    printf("\n");
    printf("Choisissez la recette que vous souhaiteriez faire :\n");
    printf("1 - crêpes classiques\n");
    printf("2 - crêpes a la bière\n");
    printf("3 - crêpes légères\n");
    printf("4 - gaufres\n");
    printf("5 - pancakes\n");
    printf("Faites votre choix : ");

    //asks until a valid id is entered
    do {
        fflush(stdin);
        scanf("%d", &recipeID.id);
    } while (recipeID.id < 1 || recipeID.id > MAX_RECIPE_ID);

    //returns the recipe with its id
    return recipeID;
}

/**
 * gets the content for the chosen recipe
 * @param recipeWithID
 * @return
 */
recipe getRecipe(recipe recipeWithID) {

    //gets the data from a predefined recipe with the id given
    switch (recipeWithID.id) {
        case 1:
            recipeWithID = classic;
            break;
        case 2:
            recipeWithID = beer;
            break;
        case 3:
            recipeWithID = light;
            break;
        case 4:
            recipeWithID = waffle;
            break;
        case 5:
            recipeWithID = pancake;
            break;
        default:
            printf("unexpected id %d", recipeWithID.id);
    }

    //recipe choice confirmation
    printf("\n");
    printf("Vous avez choisi la recette des %s\n", recipeWithID.name);

    //returns the recipe with its correct content
    return recipeWithID;
}

/**
 * gets the number of portions wanted
 * @param recipeWithContent
 * @return the recipe with the wanted portions added
 */
recipe getPortions(recipe recipeWithContent) {

    printf("\n");
    printf("Entrez le nombre de personnes qui mangeront des %s : ", recipeWithContent.name);

    //asks for the number of portions until a valid value is entered
    do {
        fflush(stdin);
        scanf("%d", &recipeWithContent.portions);
    } while (recipeWithContent.portions < 1);

    //returns the recipe with its target number of portions
    return recipeWithContent;
}

/**
 * calculate the proportions for the recipe
 * @param recipeWithPortions
 * @return the recipe with its updated proportions
 */
recipe getProportions(recipe recipeWithPortions) {

    //calculates the proportions for each ingredient
    recipeWithPortions.flour *= recipeWithPortions.portions;
    recipeWithPortions.milk *= recipeWithPortions.portions;
    recipeWithPortions.beer *= recipeWithPortions.portions;
    recipeWithPortions.water *= recipeWithPortions.portions;
    recipeWithPortions.egg *= recipeWithPortions.portions;
    recipeWithPortions.salt *= recipeWithPortions.portions;
    recipeWithPortions.butter *= recipeWithPortions.portions;
    recipeWithPortions.yeast *= recipeWithPortions.portions;

    //returns the updated recipe
    return recipeWithPortions;
}

/**
 * displays the proportions for the chosen recipe
 * @param recipeWithProportions
 */
void displayProportions(recipe recipeWithProportions) {

    printf("\n");
    printf("Les ingrédients nécessaires pour %d personnes sont :\n", recipeWithProportions.portions);

    //displays each ingredients with it's unit if it is positive
    if (recipeWithProportions.flour > 0)printf("Farine\t: %g g\n", recipeWithProportions.flour);
    if (recipeWithProportions.milk > 0)printf("Lait\t: %g l\n", recipeWithProportions.milk);
    if (recipeWithProportions.beer > 0)printf("Bière\t: %g l\n", recipeWithProportions.beer);
    if (recipeWithProportions.water > 0)printf("Eau\t: %g l\n", recipeWithProportions.water);
    if (recipeWithProportions.egg > 0)printf("Oeufs\t: %.0f\n", recipeWithProportions.egg);
    if (recipeWithProportions.salt > 0)printf("Sel\t: %.0f pincées\n", recipeWithProportions.salt);
    if (recipeWithProportions.butter > 0)printf("Beurre\t: %.0f cuillères\n", recipeWithProportions.butter);
    if (recipeWithProportions.yeast > 0)printf("Levure\t: %.0f g\n", recipeWithProportions.yeast);

    printf("\n");
    printf("Bonne dégustation !\n");

}

/**
 * main program
 * @return 0
 */
int main() {
    //structure stocking the required data
    recipe currentRecipe;

    //sets the console to output utf-8 characters
    SetConsoleOutputCP(65001);

    //displays the program title
    displayTitle();
    //gets a recipe id
    currentRecipe = getRecipeID(currentRecipe);
    //gets the recipe content
    currentRecipe = getRecipe(currentRecipe);
    //gets the number of portions
    currentRecipe = getPortions(currentRecipe);
    //calculates the proportions for each ingredient
    currentRecipe = getProportions(currentRecipe);
    //displays the proportions
    displayProportions(currentRecipe);

    system("pause");
    return 0;
}
