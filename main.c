#include <stdio.h>
#include "morpion.h"

int main(void)
{
    // creation d'un tableau 3x3 pour le morpion
    char terrain[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int ligne, colonne;
    int result;
    int *pt_ligne = &ligne;
    int *pt_colonne = &colonne;
    int tour = 0;

    // creation du terrain de jeu

    while (1)
    {
        if(tour>8){
            printf("egalite");
            break;
        }
        if (tour % 2 == 0)
        {
            printf("\ntour Jouer 1 :\n");
        }
        else
        {
            printf("\ntour Jouer 2 :\n");
        }
       afficherTerrain(terrain);
        do
        {
            jouerPosition(pt_ligne, pt_colonne);
             if (terrain[ligne - 1][colonne - 1] == 'X' || terrain[ligne - 1][colonne - 1] == 'O') {
            printf("Position deja jouer\n");
        }
        } while (terrain[ligne - 1][colonne - 1] == 'X' || terrain[ligne - 1][colonne - 1] == 'O');

        if (tour % 2 == 0)
        {
            terrain[ligne - 1][colonne - 1] = 'X';
            if (verifVictoire(terrain) == 1)
            {
                afficherTerrain(terrain);
                printf("victoire du joueur 1");
                break;
            }
        }
        else
        {
            terrain[ligne - 1][colonne - 1] = 'O';
            if (verifVictoire(terrain) == 1)
            {
                afficherTerrain(terrain);
                printf("victoire du joueur 2");
                break;
            }
        }

        tour++;
    }

    return 0;
}

/*
     |     |
  1  |  2  |  3
_____|_____|_____
     |     |
  1  |  x  |  3
_____|_____|_____
     |     |
  1  |  2  |  3
     |     |

*/