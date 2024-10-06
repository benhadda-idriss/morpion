#include <stdio.h>
#include "morpion.h"

int verifVictoire(char tab[][3]){
    
    //Verifier ligne 
    for(int i=0; i<3; i++){

        if((tab[i][0]=='X')&&(tab[i][1]=='X')&&(tab[i][2]=='X'))
        {

            return 1;
        }

        if((tab[i][0]=='O')&&(tab[i][1]=='O')&&(tab[i][2]=='O'))
        {

            return 1;
        }
    }

    //Verifier colonne 
    for(int i=0; i<3; i++){

        if((tab[0][i]=='X')&&(tab[1][i]=='X')&&(tab[2][i]=='X'))
        {

            return 1;
        }

        if((tab[0][i]=='O')&&(tab[1][i]=='O')&&(tab[2][i]=='O'))
        {

            return 1;
        }
    }

    //verifeir diagonal

        if((tab[0][0]=='X')&&(tab[1][1]=='X')&&(tab[2][2]=='X'))
        {

            return 1;
        }

        if((tab[0][2]=='X')&&(tab[1][1]=='X')&&(tab[2][0]=='X'))
        {

            return 1;
        }

         if((tab[0][0]=='O')&&(tab[1][1]=='O')&&(tab[2][2]=='O'))
        {

            return 1;
        }

        if((tab[0][2]=='O')&&(tab[1][1]=='O')&&(tab[2][0]=='O'))
        {
            return 1;
        }
}

void jouerPosition(int *ligne, int *colonne) {
    char input[100];
    int result;
    do {
        printf("Donnez la position de la ligne puis de la colonne du type (1-3) : ");

        fgets(input, sizeof(input), stdin);  // Lire toute la ligne entrée par l'utilisateur

        // Utiliser sscanf pour analyser la chaîne lue
        result = sscanf(input, "%d-%d", ligne, colonne);
        


        // Vérifie si le scanf a réussi et si les valeurs sont dans l'intervalle correct
        if (result != 2 || *ligne < 1 || *ligne > 3 || *colonne < 1 || *colonne > 3) {
            printf("Entrée invalide. Veuillez réessayer.\n");
        }
    } while (result != 2 || *ligne < 1 || *ligne > 3 || *colonne < 1 || *colonne > 3);
}

void afficherTerrain(char tab[3][3]){
     for (int i = 0; i < 3; i++)
        {
            printf("     |     |\n");
            for (int j = 0; j < 3; j++)
            {
                printf("  %c  ", tab[i][j]);
                if (j < 2)
                {
                    printf("|");
                }
            }
            if (i < 2)
            {
                printf("\n_____|_____|_____\n");
            }
        }
        printf("\n");
}


